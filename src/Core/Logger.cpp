//
// Created by lezenn on 18/01/2021.
//

#include "Logger.hpp"
#include <iostream>

namespace quazar::core
{
    void Logger::info(const std::string &message) noexcept
    {
        log(LoggerLevel::Info, message);
    }

    void Logger::error(const std::string &message) noexcept
    {
        log(LoggerLevel::Error, message);
    }

    void Logger::warn(const std::string &message) noexcept
    {
        log(LoggerLevel::Warning, message);
    }

    void Logger::debug(const std::string &message) noexcept
    {
        log(LoggerLevel::Debug, message);
    }

    void Logger::log(const LoggerLevel &level, const std::string &message) noexcept
    {
        std::string prefix;

        switch (level)
        {
            case LoggerLevel::Info:
                prefix = "Info";
                break;
            case LoggerLevel::Error:
                prefix = "Error";
                break;
            case LoggerLevel::Warning:
                prefix = "Warning";
                break;
            case LoggerLevel::Debug:
                prefix = "Debug";
        }

        if (level == LoggerLevel::Error)
        {
            std::cerr << "[\t\t" << prefix << "\t\t] " << message << std::endl;

        }
        else
        {
            std::cout << "[\t\t" << prefix << "\t\t] " << message << std::endl;
        }
    }
}