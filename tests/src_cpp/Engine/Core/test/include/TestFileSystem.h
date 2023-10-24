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


#ifndef __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__
#define __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__

#include "../../include/FileSystem.h"
#include "../../../UTest/include/TestBase.h"

namespace Hoopoe { namespace Test {

class TestFileSystem : public TestBase
{
public:
    TestFileSystem(const String& name) : TestBase(name) {}
    ~TestFileSystem() {}

    void run() override;

private:
    void testCreateFile();
    void testDeleteFile();
    void testMoveFile();
    void testIsFile();
    void testGetFileSize();
    void testCreateFolder();
    void testDeleteEmptyFolder();
    void testDeleteFolderContents();
    void testDeleteFolderAndContents();
    void testIsAbsolutePath();
    void testCatPath();
    void testIsFolder();
    void testGetCurrentDirectory();
};

} // Test
} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_TEST_FILESYSTEM_H__