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


#include "Exception.h"

namespace Hoopoe 
{

Exception::Exception(const String& description, const String& source) :
    Exception(description, source, "", "", 0)
{}

Exception::Exception(
        const String& description, 
        const String& source, 
        const char* typeName, 
        const char* file, 
        long line   
    ) :
        description(description),
        source(source),
        typeName(typeName),
        file(file),
        line(line)
{
    StringStream ss;

    ss << this->typeName << ": "
        << this->description
        << " in " << this->source;

    if( line > 0 )
    {
        ss << " at " << this->file << " (line " << this->line << ")";
    }

    fullDesc = ss.str();
}

Exception::Exception(const Exception& rhs) :   
    description(rhs.description),
    source(rhs.source),  
    typeName(rhs.typeName),
    file(rhs.file),
    line(rhs.line)
{}

} // Hoopoe