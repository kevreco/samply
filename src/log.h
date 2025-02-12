#ifndef SAMPLY_LOG_H
#define SAMPLY_LOG_H

#if __cplusplus
extern "C" {
#endif

void log_error(const char* fmt, ...);
void log_warning(const char* fmt, ...);
void log_debug(const char* fmt, ...);
void log_message(const char* fmt, ...);

#if __cplusplus
}
#endif

#endif /* SAMPLY_LOG_H */