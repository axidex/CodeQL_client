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


#ifndef __HOOPOE_ENGINE_CORE_PLATFORM_H__
#define __HOOPOE_ENGINE_CORE_PLATFORM_H__

/*
 * It defines some of the following constants:
 *
 * HE_IS_WIN32          Win32 any kind
 * HE_IS_WIN32_NT       Windows NT/XP
 *
 * HE_IS_UNIX           UNIX any kind
 * HE_IS_BSD            BSD UNIX any kind
 * HE_IS_LINUX          Linux
 * HE_IS_MACOS          MacOS/X
 */
#if     defined(_MSC_VER) ||    \
        defined(__WIN32) ||     \
        defined(__WIN32__) ||   \
        defined(_WIN32) ||      \
        defined(WIN32) ||       \
        defined(__WINNT) ||     \
        defined(__WINNT__) ||   \
        defined(__WINNT)

#   define HE_IS_WIN32          1
#   define HE_IS_WIN32_NT       1

#elif defined(__linux) || defined(__linux__)

#   define HE_IS_UNIX           1
#   define HE_IS_LINUX          1

#elif defined(__APPLE__)

#   define HE_IS_UNIX           1
#   define HE_IS_BSD            1
#   define HE_IS_MACOS          1

#else

#   error Cannot determine OS type

#endif // if

#endif // __HOOPOE_ENGINE_CORE_PLATFORM_H__