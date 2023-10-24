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


#include "../../../UTest/include/TestSuite.h"
#include "../include/TestConfigFile.h"
#include "../include/TestFileSystem.h"

int main(int argc, char* argv[]) 
{
    HE_UTEST_BEGIN_SUITE("Core")
        HE_UTEST_ADD_TEST(TestConfigFile("TestConfigFile"))
        HE_UTEST_ADD_TEST(TestFileSystem("TestFileSystem"))
    HE_UTEST_END_SUITE

    return 0;
}