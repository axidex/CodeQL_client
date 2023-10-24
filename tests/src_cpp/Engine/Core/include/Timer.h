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


#ifndef __HOOPOE_ENGINE_CORE_TIMER_H__
#define __HOOPOE_ENGINE_CORE_TIMER_H__

#include "CoreHeaders.h"

#include <iostream>
#include <chrono>

namespace Hoopoe 
{

class Timer
{
public:
    Timer(const String& funcName, const String& fileName, const int line);
    ~Timer();

    void stop();

private:
    String m_funcName;
    String m_fileName;
    int m_line;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_startTimepoint;
    bool m_stopped;
};

} // Hoopoe

#if HE_BENCHMARK_MODE == 1
    #define HE_TIMER_ON Hoopoe::Timer __he_timer__(__func__, __FILE__, __LINE__);
    #define HE_TIMER_OFF __he_timer__.stop();
#else
    #define HE_TIMER_ON
    #define HE_TIMER_OFF
#endif

#endif // __HOOPOE_ENGINE_CORE_TIMER_H__