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


#ifndef __HOOPOE_ENGINE_TESTBASE_H__
#define __HOOPOE_ENGINE_TESTBASE_H__

#include "../../Core/include/LogManager.h"

#include "TestReporter.h"

#define HE_UTEST_ASSERT(x) \
    if(x) { \
        reporter->saveResult(this->getName(), __func__, true); \
    } else { \
        reporter->saveResult(this->getName(), __func__, false); \
    } \

namespace Hoopoe { namespace Test {

class TestBase 
{
public:
    TestBase(const String& name) : name(name) {}
    virtual ~TestBase() {}

    virtual void run() = 0;
    virtual void setReporter(TestReporter* reporter) { this->reporter = reporter; }
    virtual String getName() { return this->name; };

protected:
    String name;
    TestReporter *reporter;
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_TESTBASE_H__