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


#ifndef __HOOPOE_ENGINE_CORE_MEMORY_H__
#define __HOOPOE_ENGINE_CORE_MEMORY_H__

#define HE_ALLOC(bytes) (void*)new char[bytes]
#define HE_ALLOC_T(T, count) (T*)new char[(count) * sizeof(T)]
#define HE_FREE(ptr) delete[] (char*)ptr

#define HE_NEW_T(T) new T
#define HE_NEW_ARRAY_T(T, count) new T[count]
#define HE_DELETE(ptr) delete ptr
#define HE_DELETE_ARRAY(ptr) delete[] ptr

#endif // __HOOPOE_ENGINE_CORE_MEMORY_H__