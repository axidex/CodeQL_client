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


#ifndef __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__

#include "../../include/ConfigFile.h"
#include "../../../UTest/include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestConfigFile : public TestBase
{
public:
    TestConfigFile(const String& name) : TestBase(name) {}
    ~TestConfigFile() {}

    void run() override;

private:
    void testConfig1();
    void testConfig2();
    void testConfig3();
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_TEST_CONFIGFILE_H__