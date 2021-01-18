//
// Created by lezenn on 18/01/2021.
//

#ifndef QUAZAR_LOGGER_HPP
#define QUAZAR_LOGGER_HPP

#include <string>

namespace quazar::core
{
    enum class LoggerLevel
    {
        Error,
        Info,
        Warning,
        Debug
    };

    struct Logger
    {
        static void info(const std::string& message) noexcept;
        static void error(const std::string& message) noexcept;
        static void warn(const std::string& message) noexcept;
        static void debug(const std::string& message) noexcept;
    private:
        static void log(const LoggerLevel& level, const std::string& message) noexcept;
    };
}

#endif //QUAZAR_LOGGER_HPP
