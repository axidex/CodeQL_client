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


#ifndef __HOOPOE_ENGINE_CORE_FILESYSTEM_H__
#define __HOOPOE_ENGINE_CORE_FILESYSTEM_H__

#include <fstream>
#include <dirent.h>
#include <libgen.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <ftw.h>

#include "CoreHeaders.h"
#include "DataStream.h"

namespace Hoopoe
{

class FileSystem
{
public:
    // Files
    static DataStreamPtr openFileStream(const String& path, std::ios::openmode mode, const String& name = "");
    
    static bool createFile(const String& path);   
    static bool deleteFile(const String& path);
    static bool moveFile(const String& oldPath, const String& newPath);
    static bool isFile(const String& path);
    static size_t getFileSize(const String& path);
    static String syncReadFile(const String& path);
    static String asyncReadFile(const String& path);

    // Folders
    static bool isAbsolutePath(const String& path);
    static bool createFolder(const String& path);
    static bool deleteEmptyFolder(const String& path);
    static bool deleteFolderContents(const String& path);
    static bool deleteFolderAndContents(const String& path);
    static bool isFolder(const String& path);
    static String catPath(const String& basePath, const String& subPath);
    static String getFullPath(const String& path);
    static String getCurrentDirectory();

private:
#ifdef HE_IS_LINUX
    static struct stat pathStat;
#endif
}; // FileSystem

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_FILESYSTEM_H__