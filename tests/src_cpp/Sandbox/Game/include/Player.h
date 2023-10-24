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


#ifndef __SANDBOX_GAME_PLAYER_H__
#define __SANDBOX_GAME_PLAYER_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

#include "../include/Creature.h"
#include "../include/Location.h"

namespace Hoopoe 
{

class Player : public Creature 
{
public:
    Player();
    Player(
        int id,
        string name,
        double intelligence,
        double strenght,
        double stamina,
        double agility,
        double spirit,
        double accuracy,
        double armor,
        double mastery,
        Location *location
    );

    Location get_location();

    void set_location(Location &location);
private:
    Location *location;
};

}

#endif
