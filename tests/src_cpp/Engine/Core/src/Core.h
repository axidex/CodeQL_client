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


#ifndef __ENGINE_CORE_H__
#define __ENGINE_CORE_H__

#include "Application.h"

extern Hoopoe::Application* Hoopoe::CreateApplication();

int main(int argc, char* argv[]) 
{
    HE_TIMER_ON

    Hoopoe::ConfigFile engineCfg(Hoopoe::FileSystem::getFullPath("hoopoe.cfg"));
    Hoopoe::LogManager::Init(engineCfg);

    HE_CORE_INFO("hoopoe.cfg loaded.");
    HE_CORE_INFO("Logging system initialized.");

    HE_CORE_INFO("All subsystems of Hoopoe Engine ver." + engineCfg.getSetting("engine_version", "General", "0") + " were initialized!");

    auto app = Hoopoe::CreateApplication();
    app->Run();
    delete app;

    return 0;
}

#endif // __ENGINE_CORE_H__