//
// Created by root on 2020/6/8.
//
#include <iostream>

#include "spdlog/sinks/stdout_color_sinks.h"
#include "logger.h"
namespace HC
{
    #define MAX_BUF_SIZE 2048
    HCLogger* HCLogger::intance_ = nullptr;
    const std::string myLoggerName = "HCLogger";

    HCLogger::HCLogger()
    {
    //    m_logger = spdlog::get(myLoggerName);
        // Create color multi threaded logger.
        auto console = spdlog::stdout_color_mt("console");
        // or for stderr:
        // auto console = spdlog::stderr_color_mt("error-logger");

        // Customize msg format for all loggers
        spdlog::set_pattern("[%H:%M:%S %z] [%^%L%$] [thread %t] %v");
        spdlog::info("This an info message with custom format");
       // spdlog::set_pattern("%+"); // back to default format
        spdlog::set_level(spdlog::level::trace);
    }

    HCLogger::~HCLogger()
    {
        if (intance_)
        {
            delete intance_;
            intance_ = nullptr;
        }
    }

    HCLogger* HCLogger::getInstance()
    {
        if (intance_ == nullptr)
        {
            intance_ = new HCLogger();
        }
        return intance_;
    }
    std::string HCLogger::loggerName()
    {
        return myLoggerName;
    }


}
