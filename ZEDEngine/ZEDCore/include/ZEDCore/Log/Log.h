/*
 * © 2025 ZED Interactive. All Rights Reserved.
 */

#pragma once

#ifndef LOG_H
#define LOG_H

#include "ZEDCorePch.h"
#include "ZedCore/Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace ZED
{
    class Log
    {
    public:
        static void Init();

        inline static std::shared_ptr<spdlog::logger>& GetZEDCoreLogger() { return ZEDCoreLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetZEDClientLogger() { return ZEDClientLogger; }
        inline static std::shared_ptr<spdlog::logger>& GetZEDServerLogger() { return ZEDServerLogger; }

    private:
        static std::shared_ptr<spdlog::logger> ZEDCoreLogger;
        static std::shared_ptr<spdlog::logger> ZEDClientLogger;
        static std::shared_ptr<spdlog::logger> ZEDServerLogger;
    };
}

// Core log macros
#define ZED_CORE_FATAL(...) ::ZED::Log::GetZEDCoreLogger()->fatal(__VA_ARGS__) //Red
#define ZED_CORE_ERROR(...) ::ZED::Log::GetZEDCoreLogger()->error(__VA_ARGS__) //Red
#define ZED_CORE_WARN(...) ::ZED::Log::GetZEDCoreLogger()->warn(__VA_ARGS__)   //Yellow
#define ZED_CORE_INFO(...) ::ZED::Log::GetZEDCoreLogger()->info(__VA_ARGS__)   //Green
#define ZED_CORE_TRACE(...) ::ZED::Log::GetZEDCoreLogger()->trace(__VA_ARGS__) //White

// Client log macros
#define ZED_CLIENT_FATAL(...) ::ZED::Log::GetZEDClientLogger()->fatal(__VA_ARGS__) //Red
#define ZED_CLIENT_ERROR(...) ::ZED::Log::GetZEDClientLogger()->error(__VA_ARGS__) //Red
#define ZED_CLIENT_WARN(...) ::ZED::Log::GetZEDClientLogger()->warn(__VA_ARGS__)  //Yellow
#define ZED_CLIENT_INFO(...) ::ZED::Log::GetZEDClientLogger()->info(__VA_ARGS__)  //Green
#define ZED_CLIENT_TRACE(...) ::ZED::Log::GetZEDClientLogger()->trace(__VA_ARGS__) //White

// Client log macros
#define ZED_SERVER_FATAL(...) ::ZED::Log::GetZEDServerLogger()->fatal(__VA_ARGS__) //Red
#define ZED_SERVER_ERROR(...) ::ZED::Log::GetZEDServerLogger()->error(__VA_ARGS__) //Red
#define ZED_SERVER_WARN(...) ::ZED::Log::GetZEDServerLogger()->warn(__VA_ARGS__)  //Yellow
#define ZED_SERVER_INFO(...) ::ZED::Log::GetZEDServerLogger()->info(__VA_ARGS__)  //Green
#define ZED_SERVER_TRACE(...) ::ZED::Log::GetZEDServerLogger()->trace(__VA_ARGS__) //White

#endif //LOG_H
