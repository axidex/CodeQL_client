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



#include "Timer.h"

namespace Hoopoe
{

Timer::Timer(const String& funcName, const String& fileName, const int line) : 
    m_funcName(funcName), 
    m_fileName(fileName),
    m_line(line),
    m_stopped(false)   
{
    m_startTimepoint = std::chrono::high_resolution_clock::now();
}

Timer::~Timer()
{
    if(!m_stopped)
        stop();
}

void Timer::stop()
{
    auto endTimepoint = std::chrono::high_resolution_clock::now();

    long long start = std::chrono::time_point_cast<std::chrono::milliseconds>(m_startTimepoint).time_since_epoch().count();
    long long end = std::chrono::time_point_cast<std::chrono::milliseconds>(endTimepoint).time_since_epoch().count();

    std::cout << m_fileName << " - " << m_funcName << "(line " << m_line << "): " << (end - start) << "ms.\n";

    m_stopped = true;
}

} // Hoopoe