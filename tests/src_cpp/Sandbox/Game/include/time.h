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


#ifndef __SANDBOX_GAME_TIME_H__
#define __SANDBOX_GAME_TIME_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace Hoopoe 
{

enum period_type 
{
	STEPS,
	MINS,
	HOURS,
	DAYS,
	YEARS
};

int get_period(period_type type);
string get_age();
string get_time();

}

#endif
