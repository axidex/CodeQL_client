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


#ifndef __HOOPOE_ENGINE_CORE_EXCEPTION_H__
#define __HOOPOE_ENGINE_CORE_EXCEPTION_H__

#include <exception>
#include <cassert>

#include "Types.h"

namespace Hoopoe
{

class Exception : public std::exception 
{
public:
    enum ExceptionCodes 
    {
        ERR_CANNOT_WRITE_TO_FILE,
        ERR_INVALID_STATE,
        ERR_INVALIDPARAMS,
        ERR_RENDERINGAPI_ERROR,
        ERR_DUPLICATE_ITEM,
        ERR_ITEM_NOT_FOUND = ERR_DUPLICATE_ITEM,
        ERR_FILE_NOT_FOUND,
        ERR_INTERNAL_ERROR,
        ERR_RT_ASSERTION_FAILED,
        ERR_NOT_IMPLEMENTED,
        ERR_INVALID_CALL
    };

    Exception(const String& description, const String& source);
    Exception(const String& description, const String& source, const char* typeName, const char* file, long line);
    Exception(const Exception& rhs);

    ~Exception() throw() {}

    const String& getFullDescription(void) const { return fullDesc; }
    const String& getSource() const { return source; }
    const char* getFile() const { return file; }
    long getLine() const { return line; }
    const String& getDescription(void) const { return description; }
    const char* what() const throw() { return fullDesc.c_str(); }

    
protected:
    long line;
    const char* typeName;
    String description;
    String source;
    const char* file;
    String fullDesc; // storage for char* returned by what()
}; // Exception

class UnimplementedException : public Exception 
{
public:
    UnimplementedException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // UnimplementedException

class FileNotFoundException : public Exception
{
public:
    FileNotFoundException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // FileNotFoundException

class IOException : public Exception
{
public:
    IOException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // IOException

class InvalidStateException : public Exception
{
public:
    InvalidStateException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // InvalidStateException

class InvalidParametersException : public Exception
{
public:
    InvalidParametersException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // InvalidParametersException

class ItemIdentityException : public Exception
{
public:
    ItemIdentityException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // ItemIdentityException

class InternalErrorException : public Exception
{
public:
    InternalErrorException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // InternalErrorException

class RenderingAPIException : public Exception
{
public:
    RenderingAPIException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // RenderingAPIException

class RuntimeAssertionException : public Exception
{
public:
    RuntimeAssertionException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // RuntimeAssertionException

class InvalidCallException : public Exception
{
public:
    InvalidCallException(const String& inDescription, const String& inSource, const char* inFile, long inLine)
        : Exception(inDescription, inSource, __FUNCTION__, inFile, inLine) {}
}; // InvalidCallException

class ExceptionFactory
{
public:
    static void throwException(
        Exception::ExceptionCodes code,
        const String& desc,
        const String& src, const char* file, long line)
    {
        _throwException(code, desc, src, file, line);
    }

private:
    /// Private constructor, no construction
    ExceptionFactory() {}
    static void _throwException(
        Exception::ExceptionCodes code,
        const String& desc, 
        const String& src, const char* file, long line)
    {
        switch (code)
        {
        case Exception::ERR_CANNOT_WRITE_TO_FILE:   throw IOException(desc, src, file, line);
        case Exception::ERR_INVALID_STATE:          throw InvalidStateException(desc, src, file, line);
        case Exception::ERR_INVALIDPARAMS:          throw InvalidParametersException(desc, src, file, line);
        case Exception::ERR_RENDERINGAPI_ERROR:     throw RenderingAPIException(desc, src, file, line);
        case Exception::ERR_DUPLICATE_ITEM:         throw ItemIdentityException(desc, src, file, line);
        case Exception::ERR_FILE_NOT_FOUND:         throw FileNotFoundException(desc, src, file, line);
        case Exception::ERR_INTERNAL_ERROR:         throw InternalErrorException(desc, src, file, line);
        case Exception::ERR_RT_ASSERTION_FAILED:    throw RuntimeAssertionException(desc, src, file, line);
        case Exception::ERR_NOT_IMPLEMENTED:        throw UnimplementedException(desc, src, file, line);
        case Exception::ERR_INVALID_CALL:           throw InvalidCallException(desc, src, file, line);
        default:                                    throw Exception(desc, src, "Exception", file, line);
        }
    }
}; // ExceptionFactory

} // Hoopoe

#ifndef HE_EXCEPT
    #define HE_EXCEPT_3(code, desc, src)  Hoopoe::ExceptionFactory::throwException(code, desc, src, __FILE__, __LINE__)
    #define HE_EXCEPT_2(code, desc)       Hoopoe::ExceptionFactory::throwException(code, desc, __FUNCTION__, __FILE__, __LINE__)
    #define HE_EXCEPT_CHOOSER(arg1, arg2, arg3, arg4, ...) arg4
    #define HE_EXPAND(x) x // MSVC workaround
    #define HE_EXCEPT(...) HE_EXPAND(HE_EXCEPT_CHOOSER(__VA_ARGS__, HE_EXCEPT_3, HE_EXCEPT_2)(__VA_ARGS__))
#endif

#if HE_ASSERT_MODE == 1
    #define HE_ASSERT(exp, msg) if(!(exp)) HE_EXCEPT_2(Hoopoe::Exception::ERR_RT_ASSERTION_FAILED, (#exp " failed. " msg))
#else
    #define HE_ASSERT(exp, msg)
#endif

#endif