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

struct stat FileSystem::pathStat;

DataStreamPtr FileSystem::openFileStream(const String& path, std::ios::openmode mode, const String& name)
{
    int32 ret = stat(path.c_str(), &pathStat);
    size_t st_size = ret == 0 ? pathStat.st_size : 0;

    std::istream* baseStream = 0;
    std::ifstream* roStream = 0;
    std::fstream* rwStream = 0;

    if (mode &std::ios::out)
    {
        rwStream = HE_NEW_T(std::fstream);
        rwStream->open(path.c_str(), mode);

        baseStream = rwStream;
    }
    else
    {
        roStream = HE_NEW_T(std::ifstream);
        roStream->open(path.c_str(), mode);

        baseStream = roStream;
    }

    // Should check ensure open succeeded, in case fail for some reason.
    if (baseStream->fail())
    {
        HE_DELETE(roStream);
        HE_DELETE(rwStream);
        HE_EXCEPT(Exception::ERR_FILE_NOT_FOUND, "Cannot open file: " + path);
    }

    /// Construct return stream, tell it to delete on destroy
    FileStream* stream = 0;
    const String& streamname = name.empty() ? path : name;
    if (rwStream)
    {
        // use the writeable stream
        stream = new FileStream(streamname, rwStream, st_size);
    }
    else
    {
        HE_ASSERT(ret == 0, "Problem getting file size");

        // read-only stream
        stream = new FileStream(streamname, roStream, st_size);
    }

    return DataStreamPtr(stream);
}

String FileSystem::syncReadFile(const String& path)
{
    DataStreamPtr stream = openFileStream(path, std::ios::in | std::ios::binary);
    
    return stream->getAsString();
}

String FileSystem::asyncReadFile(const String& path)
{
#if HE_ASYNC == 1
    HE_EXCEPT(Exception::ERR_NOT_IMPLEMENTED, "This functions has no implementation yet.");
#else
    syncReadFile(path);
#endif
}

bool FileSystem::isAbsolutePath(const String& path)
{
    return path[0] == '/' || path[0] == '\\';
}

String FileSystem::catPath(const String& basePath, const String& subPath)
{
    if (basePath.empty() || isAbsolutePath(subPath.c_str()))
        return subPath;
    else
        return basePath + '/' + subPath;
}

String FileSystem::getFullPath(const String& path)
{
    return catPath(FileSystem::getCurrentDirectory(), path);
}

bool FileSystem::createFile(const String& path)
{
    return creat(path.c_str(), S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) != -1;
}

bool FileSystem::deleteFile(const String& path)
{
    return remove(path.c_str()) != -1;
}

bool FileSystem::moveFile(const String& oldPath, const String& newPath)
{
    return rename(oldPath.c_str(), newPath.c_str()) != -1;
}

bool FileSystem::isFile(const String& path)
{
    stat(path.c_str(), &pathStat);

    return S_ISREG(pathStat.st_mode);
}

size_t FileSystem::getFileSize(const String& path)
{
    stat(path.c_str(), &pathStat);

    return pathStat.st_size;
}

bool FileSystem::createFolder(const String& path)
{
    if (stat(path.c_str(), &pathStat) == -1)
        return mkdir(path.c_str(), 0700) != -1;

    return 0;
}

bool FileSystem::deleteEmptyFolder(const String& path)
{
    return rmdir(path.c_str()) != -1;
}

bool FileSystem::deleteFolderContents(const String& path)
{
    auto unlink_cb = [](
            const char* fpath, 
            const struct stat* sb, 
            int32 typeflag, 
            struct FTW* ftwbuf
        )
    {
        // Do not delete if this is the current directory 
        if(ftwbuf->level == 0 && typeflag == FTW_DP)
            return 0;

        return remove(fpath);
    };


    return nftw(path.c_str(), unlink_cb, HOOPOE_MAX_DIR_FILES_REMOVE, FTW_DEPTH | FTW_PHYS) != -1;
}

bool FileSystem::deleteFolderAndContents(const String& path)
{
    auto unlink_cb = [](
            const char* fpath, 
            const struct stat* sb, 
            int32 typeflag, 
            struct FTW* ftwbuf
        )
    {
        return remove(fpath);
    };


    return nftw(path.c_str(), unlink_cb, HOOPOE_MAX_DIR_FILES_REMOVE, FTW_DEPTH | FTW_PHYS) != -1;
}

bool FileSystem::isFolder(const String& path)
{
    stat(path.c_str(), &pathStat);

    return S_ISDIR(pathStat.st_mode);
}

String FileSystem::getCurrentDirectory()
{
    char buff[PATH_MAX];
    ssize_t len = readlink("/proc/self/exe", buff, sizeof(buff) - 1);
    if (len != -1) {
        buff[len] = '\0';
        return String(dirname(buff));
    }

    HE_CORE_ERROR("Cannot get current directory.");
    HE_EXCEPT(Exception::ERR_ITEM_NOT_FOUND, "Cannot get current directory", "FileSystem::getCurrentDirectory()");
}

} // Hoopoe