/*
 *  Copyright (C) 2020-2021 Xios
 *
 *  This file is part of Hoopoe-Engine.
 *
 *  Hoopoe-Engine is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Hoopoe-Engine is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with Hoopoe-Engine.  If not, see <https://www.gnu.org/licenses/>.
 */


#ifndef __HOOPOE_ENGINE_CORE_LOGMANAGER_H__
#define __HOOPOE_ENGINE_CORE_LOGMANAGER_H__

#include <memory>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/sinks/rotating_file_sink.h"

#include "CoreHeaders.h"
#include "ConfigFile.h"

namespace Hoopoe 
{

class LogManager
{
public:
    static void Init();
    static void Init(const Hoopoe::ConfigFile& config);

    static void configure(const ConfigFile& config);
    static void setPattern(const String& pattern);

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

private:
    static std::shared_ptr<spdlog::logger> CoreLogger;
    static std::shared_ptr<spdlog::logger> ClientLogger;
}; // LogManager

} // Hoopoe

#if HE_DEBUG_MODE == 1
    #define HE_CORE_TRACE(...) Hoopoe::LogManager::GetCoreLogger()->trace(__VA_ARGS__)
    #define HE_CORE_INFO(...) Hoopoe::LogManager::GetCoreLogger()->info(__VA_ARGS__)
    #define HE_CORE_WARN(...) Hoopoe::LogManager::GetCoreLogger()->warn(__VA_ARGS__)

    #define HE_CLIENT_TRACE(...) Hoopoe::LogManager::GetClientLogger()->trace(__VA_ARGS__)
    #define HE_CLIENT_INFO(...) Hoopoe::LogManager::GetClientLogger()->info(__VA_ARGS__)
    #define HE_CLIENT_WARN(...) Hoopoe::LogManager::GetClientLogger()->warn(__VA_ARGS__)
#else
    #define HE_CORE_TRACE(...)
    #define HE_CORE_INFO(...)
    #define HE_CORE_WARN(...)

    #define HE_CLIENT_TRACE(...)
    #define HE_CLIENT_INFO(...)
    #define HE_CLIENT_WARN(...)
#endif

#define HE_CORE_ERROR(...) Hoopoe::LogManager::GetCoreLogger()->error(__VA_ARGS__)
#define HE_CORE_CRITICAL(...) Hoopoe::LogManager::GetCoreLogger()->critical(__VA_ARGS__)

#define HE_CLIENT_ERROR(...) Hoopoe::LogManager::GetClientLogger()->error(__VA_ARGS__)
#define HE_CLIENT_CRITICAL(...) Hoopoe::LogManager::GetClientLogger()->critical(__VA_ARGS__)

#endif // __HOOPOE_ENGINE_CORE_LOGMANAGER_H__