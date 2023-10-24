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


#ifndef __SANDBOX_GAME_CREATURE_H__
#define __SANDBOX_GAME_CREATURE_H__

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

namespace Hoopoe 
{

class Creature 
{
public:
    Creature();
    Creature(
        int id,
        string name,
        double intelligence,
        double strenght,
        double stamina,
        double agility,
        double spirit,
        double accuracy,
        double armor,
        double mastery
    );

    Creature(int id, 
        string name, 
        double intelligence, 
        double strenght, 
        double stamina, 
        double agility, 
        double spirit, 
        double accuracy, 
        double armor, 
        double mastery, 
        double magic_resist, 
        double armor_penetration
    );

    int get_id();
    int get_age();
    string get_name();
    double get_hp();
    double get_energy();
    double get_mana();
    double get_intelligence();
    double get_strenght();
    double get_stamina();
    double get_agility();
    double get_spirit();
    double get_accuracy();
    double get_armor();
    double get_mastery();
    double get_magic_resist();
    double get_attack_blocking();
    double get_crit();
    double get_melee_attack_power();
    double get_range_attack_power();
    double get_magic_power();
    double get_physical_damage_decrease();
    double get_hp_per_step();
    double get_energy_per_step();
    double get_mana_per_step();
    double get_parry();
    double get_dodge();
    double get_hit_chance();
    double get_armor_penetration();

    void set_id(int id);
    void set_age(int age);
    void set_name(string name);
    void set_hp(double hp);
    void set_energy(double energy);
    void set_mana(double mana);
    void set_intelligence(double intelligence);
    void set_strenght(double strenght);
    void set_stamina(double stamina);
    void set_agility(double agility);
    void set_spirit(double spirit);
    void set_accuracy(double accuracy);
    void set_armor(double armor);
    void set_mastery(double mastery);
    void set_magic_resist(double magic_resist);
    void set_attack_blocking(double attack_blocking);
    void set_crit(double crit);
    void set_melee_attack_power(double melee_attack_power);
    void set_range_attack_power(double range_attack_power);
    void set_magic_power(double magic_power);
    void set_physical_damage_decrease(double physical_damage_decrease);
    void set_hp_per_step(double hp_per_step);
    void set_energy_per_step(double energy_per_step);
    void set_mana_per_step(double mana_per_step);
    void set_parry(double parry);
    void set_dodge(double dodge);
    void set_hit_chance(double hit_chance);
    void set_armor_penetration(double armor_penetration);

    void calculate_stats();
private:
    int id;
    string name;

    double hp; // stamina * 10
    double energy; // stamina*2 - armor*0.2
    double mana; // intelligence * 10

    double intelligence; // 1 intelligence = 2 magic_power, 10 mana, 0.2 mana_per_step, 0.2 magic_resist; 0 default;
    double strenght; // 1 strenght = 2 melee_attack_power, 0.1 attack_blocking; 5 default;
    double stamina; // 1 stamina = 10 hp, 2 energy, 0.2 energy_per_step, 0.2 hp_per_step; 10 default;
    double agility; // 1 agility = 2 range_attack_power, 0.09% dodge; 5 default;
    double spirit; // 1 spirit = 1 hp_per_step, 1 energy_per_step, 1 mana_per_step; 0 default;
    double accuracy; // 1 accuracy = ~0.3% hit_chance, 0.07% crit; 70 default;
    double mastery; // 1 mastery = ~0.2% parry

    double armor; // 1 armor = ~0.1% physical_damage_decrease, -0.2 energy;
    double magic_resist; // 1 magic_resist = magic_damage - 1;
    double attack_blocking; // 1 attack_blocking = physical_damage - 1;

    double crit; // crit = accuracy/(accuracy+1330); crit = damage * 3.5; 5% default
    double melee_attack_power; // strenght * 2
    double range_attack_power; // agility * 2
    double magic_power; // intelligence * 2
    double physical_damage_decrease; // physical_damage_decrease = armor/(armor+505)
    double hp_per_step; // spirit + stamina*0.2
    double energy_per_step; // spirit + stamina*0.2
    double mana_per_step; // spirit + intelligence*0.2
    double parry; // parry = mastery/(mastery+400)
    double dodge; // dodge = agility/(agility+1000)
    double hit_chance; // hit_chance = accuracy/(accuracy+30); 70% default
    double armor_penetration; // armor = armor * armor_penetration
};

}

#endif
