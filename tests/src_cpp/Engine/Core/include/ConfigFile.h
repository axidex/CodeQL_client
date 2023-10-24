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


#ifndef __HOOPOE_ENGINE_CORE_CONFIGFILE_H__
#define __HOOPOE_ENGINE_CORE_CONFIGFILE_H__

#include <map>
#include <fstream>

#include "CoreHeaders.h"
#include "DataStream.h"
#include "FileSystem.h"

#include "../../Utils/include/String.h"

namespace Hoopoe
{

typedef std::multimap<String, String> SettingsMultiMap;
typedef std::map<String, SettingsMultiMap> SettingsBySection;

class ConfigFile
{
public:
    #define HE_ALL_CONFIG_SECTIONS "__ALL"
    #define HE_BLANK_CONFIG_SECTION ""

    ConfigFile() {}
    ConfigFile(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);

    void load(const String& filename, const String& separators = "\t:=", bool trimWhiteSpace = true);
    const String& getSetting(const String& key, const String& section = HE_ALL_CONFIG_SECTIONS, const String& defaultValue = "") const;
    const SettingsBySection& getSettingsBySection();

private:
    SettingsBySection mSettings;
}; // ConfigFile

} // Hoopoe

#endif // __HOOPOE_ENGINE_CORE_CONFIGFILE_H__