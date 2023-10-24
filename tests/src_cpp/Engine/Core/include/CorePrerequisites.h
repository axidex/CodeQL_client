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


#ifndef __HOOPOE_ENGINE_CORE_COREPREREQUISITES_H__
#define __HOOPOE_ENGINE_CORE_COREPREREQUISITES_H__

#define HE_ASYNC            0
#define HE_DEBUG_MODE       1
#define HE_ASSERT_MODE      1
#define HE_BENCHMARK_MODE   1

namespace Hoopoe
{

class ConfigFile;
class DataStream;
template<class T> class SharedPtr;
typedef SharedPtr<DataStream> DataStreamPtr;

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_COREPREREQUISITES_H__