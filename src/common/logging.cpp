#include <common/logging.h>
#include <cstdio>
#include <cstdarg>

const char *logLevels[] = {
    "DEBUG",
    "INFO",
    "WARNING",
    "ERROR",
    "FATAL"
};

void Logging::Log(LogLevel level, const char *fmt...) {
    va_list args;
    va_start(args, fmt);
    fprintf(stderr, "[%s] ", logLevels[level]);
    vfprintf(stderr, fmt, args);
    va_end(args);
}