#include "file_mapper.h"

#include "log.h"

void file_mapper_init(file_mapper* fm)
{
    memset(fm, 0, sizeof(file_mapper));

    darrT_init(&fm->chars);
}

void file_mapper_destroy(file_mapper* fm)
{
    darrT_destroy(&fm->chars);
}

#ifdef _WIN32
static int convert_utf8_to_wchar(file_mapper* fm, strv chars)
{
    /* Get length of converted string. */
    int len = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, chars.data, (int)chars.size, NULL, 0);
    int result = 0;

    /* Ensure the buffer is big enough. */
    darrT_ensure_space(wchar_t, &fm->chars, len + 1);

    if (len != 0)
    {
        /* Convert From UTF-8. */
        result = MultiByteToWideChar(CP_UTF8, MB_ERR_INVALID_CHARS, chars.data, (int)chars.size, fm->chars.data, len);
    }

    /* Ensure that the buffer ends with a null terminated wchar. */
    fm->chars.data[len] = L'\0';
    fm->chars.size = (size_t)len;
    return result;
}

#endif

bool file_mapper_open(file_mapper* fm, readonly_file* file, strv filepath)
{
    readonly_file_init(file);
#ifdef _WIN32

    if (!convert_utf8_to_wchar(fm, filepath))
    {
        log_error("could not convert path to wchar_t string: %s", filepath);
        return false;
    }

    FILE_ID_INFO info = { 0 };
    HANDLE handle = CreateFileW(fm->chars.data,
        GENERIC_READ,
        FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,
        NULL,
        OPEN_EXISTING,
        FILE_FLAG_BACKUP_SEMANTICS,
        NULL);

    if (handle == INVALID_HANDLE_VALUE
        || !GetFileInformationByHandleEx(handle, FileIdInfo, &info, sizeof(info)))
    {
        log_error("GetFileInformationByHandleEx failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    file->handle = handle;
    file->info = info;

    /* Get file size */
    LARGE_INTEGER file_size;
    if (!GetFileSizeEx(handle, &file_size))
    {
        log_error("GetFileSizeEx failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    /* Handle zero size file as it would make CreateFileMapping to fail. */
    if (file_size.QuadPart == 0)
    {
        file->view = strv_make_from_str("");
        return true;
    }

    HANDLE mapping_handle = CreateFileMappingW(file->handle, NULL, PAGE_READONLY, 0, 0, NULL);
    if (!mapping_handle)
    {
        log_error("CreateFileMapping failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    char* memory_ptr = (char*)MapViewOfFile(mapping_handle, FILE_MAP_READ, 0, 0, 0);
    CloseHandle(mapping_handle);

    file->view.data = memory_ptr;
    file->view.size = (size_t)file_size.QuadPart;
    return true;

#else

    assert(0 && "@TODO copy strv 'file' to a buffer with null termninated char.")

    int fd = open(filepath, O_RDONLY | O_NDELAY, 0644);

    if (fd < 0)
    {
        log_error("open failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    file->fd = fd;

    struct stat st;
    if (fstat(fd, &st) != 0)
    {
        log_error("fstat failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    file->st = st;


    /* Handle zero size file as it would make mmap to fail. */
    if (st.st_size == 0)
    {
        file->view = strv_make_from_str("");
        return true;
    }

    /* mmap */
    char* memory_ptr = (char*)mmap(NULL, st.st_size, PROT_READ, MAP_SHARED, fd, 0);

    if (memory_ptr == MAP_FAILED)
    {
        log_error("mmap failed for file: " STRV_FMT, STRV_ARG(filepath));
        return false;
    }

    file->view.data = memory_ptr;
    file->view.size = (size_t)st.st_size;

    return true;
#endif

}

bool file_mapper_close(file_mapper* fm, readonly_file* file)
{

#if _WIN32
    CloseHandle(file->handle);

    if (file->view.size != 0)
    {
        return UnmapViewOfFile(file->view.data);
    }
    return true;
#else
    close(file->fd);
    if (file->content.size != 0)
    {
        return munmap((void*)file->content.data, file->content.size) == 0;
    }
    return true;
#endif
}

void readonly_file_init(readonly_file* file)
{
    memset(file, 0, sizeof(readonly_file));
}