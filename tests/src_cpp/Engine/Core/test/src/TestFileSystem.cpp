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


#include "../include/TestFileSystem.h"

namespace Hoopoe { namespace Test {

void TestFileSystem::run()
{
    testCreateFile();
    testDeleteFile();
    testMoveFile();
    testIsFile();
    testGetFileSize();
    testCreateFolder();
    testDeleteEmptyFolder();
    testDeleteFolderContents();
    testDeleteFolderAndContents();
    testIsAbsolutePath();
    testCatPath();
    testIsFolder();
    testGetCurrentDirectory();
}

void TestFileSystem::testCreateFile()
{
    HE_UTEST_ASSERT(FileSystem::createFile(FileSystem::getFullPath("resources/TestFileSystem/testCreateFile")));
}

void TestFileSystem::testDeleteFile()
{
    HE_UTEST_ASSERT(FileSystem::deleteFile(FileSystem::getFullPath("resources/TestFileSystem/testDeleteFile")));
}

void TestFileSystem::testMoveFile()
{
    HE_UTEST_ASSERT(FileSystem::moveFile(FileSystem::getFullPath("resources/TestFileSystem/dir1/testMoveFile"), FileSystem::getFullPath("resources/TestFileSystem/dir2/testMoveFile")));
}

void TestFileSystem::testIsFile()
{
    HE_UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("resources/TestFileSystem/testIsFile")));
}

void TestFileSystem::testGetFileSize()
{
    HE_UTEST_ASSERT(FileSystem::getFileSize(FileSystem::getFullPath("resources/TestFileSystem/testGetFileSize")) == 9);
}

void TestFileSystem::testCreateFolder()
{
    HE_UTEST_ASSERT(FileSystem::createFolder(FileSystem::getFullPath("resources/TestFileSystem/testCreateFolder")));
}

void TestFileSystem::testDeleteEmptyFolder()
{
    HE_UTEST_ASSERT(FileSystem::deleteEmptyFolder(FileSystem::getFullPath("resources/TestFileSystem/testDeleteEmptyFolder")));
}

void TestFileSystem::testDeleteFolderContents()
{
    HE_UTEST_ASSERT(FileSystem::deleteFolderContents(FileSystem::getFullPath("resources/TestFileSystem/testDelDirContents")));
}

void TestFileSystem::testDeleteFolderAndContents()
{
    HE_UTEST_ASSERT(FileSystem::deleteFolderAndContents(FileSystem::getFullPath("resources/TestFileSystem/testDelDirAndContents")));
}

void TestFileSystem::testIsAbsolutePath()
{
    HE_UTEST_ASSERT(FileSystem::isAbsolutePath("/usr/lib"));
}

void TestFileSystem::testCatPath()
{
    HE_UTEST_ASSERT(FileSystem::catPath("/usr", "lib") == "/usr/lib");
}

void TestFileSystem::testIsFolder()
{
    HE_UTEST_ASSERT(FileSystem::isFolder(FileSystem::getFullPath("resources/TestFileSystem/dir1")));
}

void TestFileSystem::testGetCurrentDirectory()
{
    HE_UTEST_ASSERT(FileSystem::isFile(FileSystem::getFullPath("resources/TestFileSystem/testGetStringDir")));
}

} // Test
} // Hoopoe