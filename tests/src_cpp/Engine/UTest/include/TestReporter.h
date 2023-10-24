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


#ifndef __HOOPOE_ENGINE_TESTREPORTER_H__
#define __HOOPOE_ENGINE_TESTREPORTER_H__

#include <list>
#include <memory>
#include <algorithm>
#include <iterator>

#include "spdlog/spdlog.h"
#include "spdlog/sinks/stdout_color_sinks.h"

#include "../../Core/include/CoreHeaders.h"

namespace Hoopoe { namespace Test {

class TestReporter 
{
public:
    struct TestResult
    {
        TestResult(
                const String& unitName, 
                const String& testName, 
                const bool result
            ) : 
                unitName(unitName),
                testName(testName), 
                result(result)
        {}

        String unitName;
        String testName;
        bool result;
    }; // TestResult

    TestReporter(const String suiteName);
    ~TestReporter();

    void saveResult(const String& unitName, const String& testName, const bool result);
    void printResults(); // print to the console
    String getSuiteName() const;
    static std::shared_ptr<spdlog::logger> getReportLogger();

private:
    String mSuiteName;
    std::list<TestResult*> mTestResults;

    static std::shared_ptr<spdlog::logger> sReportLogger;
}; // TestReporter

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTREPORTER_H__