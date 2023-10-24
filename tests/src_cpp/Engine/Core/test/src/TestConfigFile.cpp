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


#include "../include/TestConfigFile.h"

namespace Hoopoe { namespace Test {

void TestConfigFile::run()
{
    testConfig1();
    testConfig2();
    testConfig3();
}

void TestConfigFile::testConfig1() 
{
    ConfigFile testCfg;
    testCfg.load(FileSystem::getFullPath("resources/TestConfigFile/TestConfigFile.cfg"));

    HE_UTEST_ASSERT(testCfg.getSetting("option1", HE_BLANK_CONFIG_SECTION, "1") == "1");
}

void TestConfigFile::testConfig2() 
{
    ConfigFile testCfg;
    testCfg.load(FileSystem::getFullPath("resources/TestConfigFile/TestConfigFile.cfg"));

    HE_UTEST_ASSERT(testCfg.getSetting("option2", HE_ALL_CONFIG_SECTIONS, "NULL") == "2");
}

void TestConfigFile::testConfig3() 
{
    ConfigFile testCfg;
    testCfg.load(FileSystem::getFullPath("resources/TestConfigFile/TestConfigFile.cfg"));

    HE_UTEST_ASSERT(testCfg.getSetting("option3", "Section 2", "NULL") == "3");
}

} // Test
} // Hoopoe