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


#include "../include/TestReporter.h"

namespace Hoopoe { namespace Test 
{

std::shared_ptr<spdlog::logger> TestReporter::sReportLogger;

TestReporter::TestReporter(const String suiteName) : mSuiteName(suiteName)
{
    spdlog::set_pattern("%v%$");

    sReportLogger = spdlog::stdout_color_mt("UTEST");
    sReportLogger->set_level(spdlog::level::trace);
}

TestReporter::~TestReporter()
{
    for (TestResult* test : mTestResults) 
        delete test;
}

void TestReporter::saveResult(const String& unitName, const String& testName, const bool result)
{

    std::list<TestResult*>::iterator it = std::find_if(
        mTestResults.begin(), 
        mTestResults.end(), 
        [&](TestResult *test) 
        {
            return (unitName == test->unitName && testName == test->testName);
        }
    );

    if(it == mTestResults.end())
    {
        mTestResults.push_back(new TestResult(unitName, testName, result));
    }
    else
    {
        if(!result)
        {
            (*it)->result = result ? (*it)->result : result;
        }
    }
}

void TestReporter::printResults()
{
    String testResultMsg = "";
    String unitMessage = "";
    String currentUnitName = "";

    getReportLogger()->trace(getSuiteName());

    for(TestResult* test : mTestResults)
    {
        if(currentUnitName != test->unitName)
        {
            currentUnitName = test->unitName;
            unitMessage = String("\t") + currentUnitName + String(":");
            getReportLogger()->trace(unitMessage);
        }

        testResultMsg = String("\t\t")
            + (test->result ? String(" + ") : String(" - "))
            + test->testName
            + String(" --- ")
            + (test->result ? String("PASSED.") : String("NOT PASSED!"))
        ;

        if(test->result)
            getReportLogger()->info(testResultMsg);
        else
            getReportLogger()->critical(testResultMsg);
    }
}

String TestReporter::getSuiteName() const
{
    return mSuiteName;
}

std::shared_ptr<spdlog::logger> TestReporter::getReportLogger()
{
    return sReportLogger;
}

} // Test
} // Hoopoe