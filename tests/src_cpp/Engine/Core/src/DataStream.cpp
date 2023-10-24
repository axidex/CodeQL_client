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


#include "DataStream.h"

namespace Hoopoe
{

template <typename T> DataStream& DataStream::operator >>(T& val)
{
    read(static_cast<void*>(&val), sizeof(T));
    return *this;
}

String DataStream::getLine(bool trimAfter)
{
    char tmpBuf[HOOPOE_STREAM_TEMP_SIZE];
    String retString;
    size_t readCount;

    // Keep looping while not hitting delimiter
    while ((readCount = read(tmpBuf, HOOPOE_STREAM_TEMP_SIZE-1)) != 0)
    {
        // Terminate string
        tmpBuf[readCount] = '\0';

        char* p = strchr(tmpBuf, '\n');
        if (p != NULL)
        {
            // Reposition backwards
            skip(static_cast<long>(p + 1 - tmpBuf - readCount));
            *p = '\0';
        }

        retString += tmpBuf;

        if (p != NULL)
        {
            // Trim off trailing CR if this was a CR/LF entry
            if (retString.length() && retString[retString.length()-1] == '\r')
            {
                retString.erase(retString.length()-1, 1);
            }

            // Found terminator, break out
            break;
        }
    }

    if (trimAfter)
    {
        Utils::String::trim(retString);
    }

    return retString;
}

size_t DataStream::readLine(char* buf, size_t maxCount, const String& delim)
{
    // Deal with both Unix and Windows
    bool trimCR = false;
    if (delim.find_first_of('\n') != String::npos)
    {
        trimCR = true;
    }

    char tmpBuf[HOOPOE_STREAM_TEMP_SIZE];
    size_t chunkSize = std::min(maxCount, static_cast<size_t>(HOOPOE_STREAM_TEMP_SIZE)-1);
    size_t totalCount = 0;
    size_t readCount; 
    while (chunkSize && (readCount = read(tmpBuf, chunkSize)) != 0)
    {
        // Terminate
        tmpBuf[readCount] = '\0';

        // Find first delimiter
        size_t pos = strcspn(tmpBuf, delim.c_str());

        if (pos < readCount)
        {
            // Found terminator, reposition backwards
            skip(static_cast<long>((pos + 1 - readCount)));
        }

        // Are we genuinely copying?
        if (buf)
        {
            memcpy(buf+totalCount, tmpBuf, pos);
        }
        totalCount += pos;

        if (pos < readCount)
        {
            // Trim off trailing CR if this was a CR/LF entry
            if (trimCR && totalCount && buf && buf[totalCount-1] == '\r')
            {
                --totalCount;
            }

            // Found terminator, break out
            break;
        }

        // Adjust chunkSize for next time
        chunkSize = std::min(maxCount-totalCount, static_cast<size_t>(HOOPOE_STREAM_TEMP_SIZE)-1);
    }

    // Terminate
    if(buf)
        buf[totalCount] = '\0';

    return totalCount;
}

size_t DataStream::skipLine(const String& delim)
{
    char tmpBuf[HOOPOE_STREAM_TEMP_SIZE];
    size_t total = 0;
    size_t readCount;
    // Keep looping while not hitting delimiter
    while ((readCount = read(tmpBuf, HOOPOE_STREAM_TEMP_SIZE-1)) != 0)
    {
        // Terminate string
        tmpBuf[readCount] = '\0';

        // Find first delimiter
        size_t pos = strcspn(tmpBuf, delim.c_str());

        if (pos < readCount)
        {
            // Found terminator, reposition backwards
            skip(static_cast<long>(pos + 1 - readCount));

            total += pos + 1;

            // break out
            break;
        }

        total += readCount;
    }

    return total;
}

String DataStream::getAsString()
{
    // Read the entire buffer - ideally in one read, but if the size of
    // the buffer is unknown, do multiple fixed size reads.
    size_t bufSize = (mSize > 0 ? mSize : 4096);
    char* pBuf = HE_ALLOC_T(char, bufSize);

    // Ensure read from begin of stream
    seek(0);
    String result;
    while (!eof())
    {
        size_t nr = read(pBuf, bufSize);
        result.append(pBuf, nr);
    }

    HE_FREE(pBuf);
    return result;
}


FileStream::FileStream(std::ifstream* s, bool freeOnClose)
    : DataStream(), mInStream(s), mFStreamRO(s), mFStream(0), mFreeOnClose(freeOnClose)
{
    // calculate the size
    mInStream->seekg(0, std::ios_base::end);
    mSize = static_cast<size_t>(mInStream->tellg());
    mInStream->seekg(0, std::ios_base::beg);
    determineAccess();
}

FileStream::FileStream(const String& name, 
    std::ifstream* s, bool freeOnClose)
    : DataStream(name), mInStream(s), mFStreamRO(s), mFStream(0), mFreeOnClose(freeOnClose)
{
    // calculate the size
    mInStream->seekg(0, std::ios_base::end);
    mSize = static_cast<size_t>(mInStream->tellg());
    mInStream->seekg(0, std::ios_base::beg);
    determineAccess();
}

FileStream::FileStream(const String& name, 
    std::ifstream* s, size_t inSize, bool freeOnClose)
    : DataStream(name), mInStream(s), mFStreamRO(s), mFStream(0), mFreeOnClose(freeOnClose)
{
    // Size is passed in
    mSize = inSize;
    determineAccess();
}

FileStream::FileStream(std::fstream* s, bool freeOnClose)
    : DataStream(false), mInStream(s), mFStreamRO(0), mFStream(s), mFreeOnClose(freeOnClose)
{
    // writeable!
    // calculate the size
    mInStream->seekg(0, std::ios_base::end);
    mSize = static_cast<size_t>(mInStream->tellg());
    mInStream->seekg(0, std::ios_base::beg);
    determineAccess();

}

FileStream::FileStream(const String& name, 
    std::fstream* s, bool freeOnClose)
    : DataStream(name, false), mInStream(s), mFStreamRO(0), mFStream(s), mFreeOnClose(freeOnClose)
{
    // writeable!
    // calculate the size
    mInStream->seekg(0, std::ios_base::end);
    mSize = static_cast<size_t>(mInStream->tellg());
    mInStream->seekg(0, std::ios_base::beg);
    determineAccess();
}

FileStream::FileStream(const String& name, 
    std::fstream* s, size_t inSize, bool freeOnClose)
    : DataStream(name, false), mInStream(s), mFStreamRO(0), mFStream(s), mFreeOnClose(freeOnClose)
{
    // writeable!
    // Size is passed in
    mSize = inSize;
    determineAccess();
}

void FileStream::determineAccess()
{
    mAccess = 0;
    if (mInStream)
        mAccess |= READ;
    if (mFStream)
        mAccess |= WRITE;
}

FileStream::~FileStream()
{
    close();
}

size_t FileStream::read(void* buf, size_t count)
{
    mInStream->read(static_cast<char*>(buf), static_cast<std::streamsize>(count));
    return static_cast<size_t>(mInStream->gcount());
}

size_t FileStream::write(const void* buf, size_t count)
{
    size_t written = 0;
    if (isWriteable() && mFStream)
    {
        mFStream->write(static_cast<const char*>(buf), static_cast<std::streamsize>(count));
        written = count;
    }
    return written;
}

size_t FileStream::readLine(char* buf, size_t maxCount, const String& delim)
{
    if (delim.empty())
    {
        HE_EXCEPT(Exception::ERR_INVALIDPARAMS, "No delimiter provided",
            "FileStreamDataStream::readLine");
    }
    if (delim.size() > 1)
    {
        HE_CORE_WARN("FileStreamDataStream::readLine - using only first delimiter");
    }
    
    // Deal with both Unix and Windows LFs
    bool trimCR = false;
    if (delim.at(0) == '\n') 
    {
        trimCR = true;
    }
    // maxCount + 1 since count excludes terminator in getline
    mInStream->getline(buf, static_cast<std::streamsize>(maxCount+1), delim.at(0));
    size_t ret = static_cast<size_t>(mInStream->gcount());

    if (mInStream->eof()) 
    {
        // no problem
    }
    else if (mInStream->fail())
    {
        // Did we fail because of maxCount hit? No - no terminating character
        // in included in the count in this case
        if (ret == maxCount)
        {
            // clear failbit for next time 
            mInStream->clear();
        }
        else
        {
            HE_EXCEPT(Exception::ERR_INTERNAL_ERROR, "Streaming error occurred", "FileStreamDataStream::readLine");
        }
    }
    else 
    {
        --ret;
    }

    // trim off CR if we found CR/LF
    if (trimCR && ret && buf[ret-1] == '\r')
    {
        --ret;
        buf[ret] = '\0';
    }
    return ret;
}

void FileStream::skip(long count)
{    
    mInStream->clear(); //Clear fail status in case eof was set
    mInStream->seekg(static_cast<std::ifstream::pos_type>(count), std::ios::cur);
}

void FileStream::seek(size_t pos)
{
    mInStream->clear(); //Clear fail status in case eof was set
    mInStream->seekg(static_cast<std::streamoff>(pos), std::ios::beg);
}

size_t FileStream::tell() const
{
    mInStream->clear(); //Clear fail status in case eof was set
    return static_cast<size_t>(mInStream->tellg());
}

bool FileStream::eof() const
{
    return mInStream->eof();
}

void FileStream::close()
{
    mAccess = 0;
    if (mInStream)
    {
        // Unfortunately, there is no file-specific shared class hierarchy between fstream and ifstream (!!)
        if (mFStreamRO)
            mFStreamRO->close();
        if (mFStream)
        {
            mFStream->flush();
            mFStream->close();
        }

        if (mFreeOnClose)
        {
            // delete the stream too
            HE_DELETE(mFStreamRO);
            HE_DELETE(mFStream);
        }

        mInStream = 0;
        mFStreamRO = 0; 
        mFStream = 0; 
    }
}

} // Hoopoe