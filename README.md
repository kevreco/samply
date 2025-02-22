# samply

(Soon) cross-platform and simple sampling (non-intrusive) profiler.

## CLI - Example

`samply --no-gui --run timeout 3`

The command above will run the program `timeout` for `3` seconds.
Meanwhile, the program will be sampled.

Possible output:
```
Sample count: 247989
0.98    242897  NtDelayExecution
0.01    1698    <unknown-symbol>
0.01    1582    NtDeviceIoControlFile
0.00    584     PeekConsoleInputW
0.00    535     ZwClose
0.00    135     RtlGetCurrentUmsThread
0.00    119     NtQueryWnfStateData
0.00    106     RtlFindCharInUnicodeString
```

## TODO

- [./] Display summary in terminal.
- Display summary in GUI.
    - Use a table and make it sortable.
- Display detailed result in GUI.
    - Use a table and make it sortable.
    - Display source code associated to the specific symbol.
- Remove .sln file and build with use cb.h
- Implement Linux version once the Windows version is usable.

## Credits and licences

The codebase is MIT and is using those components:

- [imgui](https://github.com/ocornut/imgui) (MIT license)
- samply.ico from [Kirill Kazachek](https://creativemarket.com/kirill.kazachek) (CC BY 4.0 license)
- [thread.h](https://github.com/mattiasgustavsson/libs/blob/main/thread.h) (dual MIT and Public Domain license)