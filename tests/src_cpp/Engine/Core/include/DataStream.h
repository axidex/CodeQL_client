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


#ifndef __HOOPOE_ENGINE_CORE_DATASTREAM_H__
#define __HOOPOE_ENGINE_CORE_DATASTREAM_H__

#include <iostream>
#include <istream>
#include <fstream>
#include <memory>
#include <list>
#include <stdio.h>

#include "CoreHeaders.h"
#include "LogManager.h"

#include "../../Utils/include/String.h"

namespace Hoopoe
{

class DataStream
{
public:
    // Constructor for creating unnamed streams
    DataStream(uint16 accessMode = READ) : mSize(0), mAccess(accessMode) {}

    // Constructor for creating named streams
    DataStream(const String& name, uint16 accessMode = READ) 
        : mName(name), mSize(0), mAccess(accessMode) {}

    virtual ~DataStream() {}

    const String& getName(void) { return mName; }
    uint16 getAccessMode() const { return mAccess; }
    virtual bool isReadable() const { return (mAccess & READ) != 0; }
    virtual bool isWriteable() const { return (mAccess & WRITE) != 0; }
    template<typename T> DataStream& operator>>(T& val);
    virtual size_t read(void* buf, size_t count) = 0;
    virtual size_t write(const void* buf, size_t count)
    {
        (void)buf;
        (void)count;
        
        return 0;
    }

    virtual size_t readLine(char* buf, size_t maxCount, const String& delim = "\n");  
    virtual String getLine(bool trimAfter = true);

    /* Returns a String containing the entire stream. */
    virtual String getAsString(void);
    virtual size_t skipLine(const String& delim = "\n");

    /* Skip a defined number of bytes. This can also be a negative value, in which case
    the file pointer rewinds a defined number of bytes. */
    virtual void skip(long count) = 0;

    /* Repositions the read point to a specified byte. */
    virtual void seek(size_t pos) = 0;
    
    /* Returns the current byte offset from beginning */
    virtual size_t tell(void) const = 0;
    virtual bool eof(void) const = 0;
    size_t size(void) const { return mSize; }
    virtual void close(void) = 0;

protected:
    enum AccessMode
    {
        READ = 1, 
        WRITE = 2
    };

    String mName;       
    size_t mSize;
    uint16 mAccess;

    #define HOOPOE_STREAM_TEMP_SIZE 128
}; // DataStream

typedef SharedPtr<DataStream> DataStreamPtr;

class FileStream : public DataStream
{
public:
    /* Construct a read-only stream from an STL stream */
    FileStream(std::ifstream* s, bool freeOnClose = true);

    /* Construct a read-write stream from an STL stream */
    FileStream(std::fstream* s, bool freeOnClose = true);

    /* Construct named read-only stream from an STL stream */
    FileStream(const String& name, std::ifstream* s, bool freeOnClose = true);

    /* Construct named read-write stream from an STL stream */
    FileStream(const String& name, std::fstream* s, bool freeOnClose = true);

    /* Construct named read-only stream from an STL stream, and tell it the size */
    FileStream(const String& name, 
        std::ifstream* s, 
        size_t size, 
        bool freeOnClose = true);

    /* Construct named read-write stream from an STL stream, and tell it the size */
    FileStream(const String& name, 
        std::fstream* s, 
        size_t size, 
        bool freeOnClose = true);

    ~FileStream();

    size_t read(void* buf, size_t count);
    size_t write(const void* buf, size_t count);
    size_t readLine(char* buf, size_t maxCount, const String& delim = "\n");
    void skip(long count);
    void seek(size_t pos);
    size_t tell(void) const;
    bool eof(void) const;
    void close(void);

private:  
    std::istream* mInStream;    // Reference to source stream (read)
    std::ifstream* mFStreamRO;  // Reference to source file stream (read-only)
    std::fstream* mFStream;     // Reference to source file stream (read-write)
    bool mFreeOnClose;  

    void determineAccess();
    
}; // FileStream

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_DATASTREAM_H__