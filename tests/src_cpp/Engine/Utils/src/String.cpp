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


#include "String.h"

namespace Hoopoe { namespace Utils {

void String::trim(Hoopoe::String& str, bool left, bool right)
{
    static const Hoopoe::String delims = " \t\r\n";
    if(right)
        str.erase(str.find_last_not_of(delims)+1); // trim right
    if(left)
        str.erase(0, str.find_first_not_of(delims)); // trim left
}

} // Utils
} // Hoopoe