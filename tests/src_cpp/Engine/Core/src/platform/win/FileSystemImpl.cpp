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


#include "FileSystem.h"

#define HOOPOE_MAX_DIR_FILES_REMOVE 64

namespace Hoopoe
{

DataStreamPtr FileSystem::openFileStream(const String& fullPath, std::ios::openmode mode, const String& name)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::syncReadFile(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::asyncReadFile(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::isAbsolutePath(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::catPath(const String& basePath, const String& subPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::getFullPath(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::createFile(const String& fileName)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFile(const String& fileName)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::moveFile(const String& oldPath, const String& newPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");1;
}

bool FileSystem::isFile(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

size_t FileSystem::getFileSize(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::createFolder(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteEmptyFolder(const String& folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFolderContents(const String& folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::deleteFolderAndContents(const String& folderPath)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

bool FileSystem::isFolder(const String& path)
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

String FileSystem::getCurrentDirectory()
{
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "There is no implementation under the current operating system.");
}

} // Hoopoe