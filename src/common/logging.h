#pragma once

namespace Logging {
    enum LogLevel {
        Debug,
        Information,
        Warning,
        Error,
        Fatal
    };
    void Log(LogLevel level, const char *fmt...);
}