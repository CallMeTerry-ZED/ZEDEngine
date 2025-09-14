/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#include "ZEDCorePch.h"
#include "ZEDCore/Log/Log.h"
#include "spdlog/sinks/stdout_color_sinks-inl.h"

namespace ZED
{
    std::shared_ptr<spdlog::logger> Log::ZEDCoreLogger;
    std::shared_ptr<spdlog::logger> Log::ZEDClientLogger;
    std::shared_ptr<spdlog::logger> Log::ZEDServerLogger;

    void Log::Init()
    {
        // Log order is timestamp logger name and the actual message
        // Then it will be wrapped in whatever color the message should be
        spdlog::set_pattern("%^[%T] %n: %v%$");
        ZEDCoreLogger = spdlog::stdout_color_mt("ZED");
        ZEDCoreLogger->set_level(spdlog::level::trace);

        ZEDClientLogger = spdlog::stdout_color_mt("CLIENT");
        ZEDClientLogger->set_level(spdlog::level::trace);

        ZEDServerLogger = spdlog::stdout_color_mt("SERVER");
        ZEDServerLogger->set_level(spdlog::level::trace);
    }
}