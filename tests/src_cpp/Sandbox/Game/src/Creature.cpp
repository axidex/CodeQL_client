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


#include "../include/Creature.h"

namespace Hoopoe {

    void Creature::calculate_stats() {
        hp = stamina * 2;
        energy = stamina*2 - armor*0.2;
        mana = intelligence * 10;
        magic_resist = intelligence * 0.2;
        attack_blocking = strenght * 0.1;
        crit = accuracy / (accuracy+1330);
        melee_attack_power = strenght * 2;
        range_attack_power = agility * 2;
        magic_power = intelligence * 2;
        physical_damage_decrease = armor / (armor+505);
        hp_per_step = spirit + stamina*2;
        energy_per_step = spirit + stamina*0.2;
        mana_per_step = spirit + intelligence*0.2;
        parry = mastery / (mastery+400);
        dodge = agility / (agility+1000);
        hit_chance = accuracy / (accuracy+30);
    }

    int Creature::get_id() { return this->id; }
    string Creature::get_name() { return this->name; }
    double Creature::get_hp() { return this->hp; }
    double Creature::get_energy() { return this->energy; }
    double Creature::get_mana() { return this->mana; }
    double Creature::get_intelligence() { return this->intelligence; }
    double Creature::get_strenght() { return this->strenght; }
    double Creature::get_stamina() { return this->stamina; }
    double Creature::get_agility() { return this->agility; }
    double Creature::get_spirit() { return this->spirit; }
    double Creature::get_accuracy() { return this->accuracy; }
    double Creature::get_armor() { return this->armor; }
    double Creature::get_mastery() { return this->mastery; }
    double Creature::get_magic_resist() { return this->magic_resist; }
    double Creature::get_attack_blocking() { return this->attack_blocking; }
    double Creature::get_crit() { return this->crit; }
    double Creature::get_melee_attack_power() { return this->melee_attack_power; }
    double Creature::get_range_attack_power() { return this->range_attack_power; }
    double Creature::get_magic_power() { return this->magic_power; }
    double Creature::get_physical_damage_decrease() { return this->physical_damage_decrease; }
    double Creature::get_hp_per_step() { return this->hp_per_step; }
    double Creature::get_energy_per_step() { return this->energy_per_step; }
    double Creature::get_mana_per_step() { return this->mana_per_step; }
    double Creature::get_parry() { return this->parry; }
    double Creature::get_dodge() { return this->dodge; }
    double Creature::get_hit_chance() { return this->hit_chance; }
    double Creature::get_armor_penetration() { return this->armor_penetration; }

    void Creature::set_id(int id) { this->id = id; }
    void Creature::set_name(string name) { this->name = name; }
    void Creature::set_hp(double hp) { this->hp = hp; }
    void Creature::set_energy(double energy) { this->energy = energy; }
    void Creature::set_mana(double mana) { this->mana = mana; }
    void Creature::set_intelligence(double intelligence) { this->intelligence = intelligence; }
    void Creature::set_strenght(double strenght) { this->strenght = strenght; }
    void Creature::set_stamina(double stamina) { this->stamina = stamina; }
    void Creature::set_agility(double agility) { this->agility = agility; }
    void Creature::set_spirit(double spirit) { this->spirit = spirit; }
    void Creature::set_accuracy(double accuracy) { this->accuracy = accuracy; }
    void Creature::set_armor(double armor) { this->armor = armor; }
    void Creature::set_mastery(double mastery) { this->mastery = mastery; }
    void Creature::set_magic_resist(double magic_resist) { this->magic_resist = magic_resist; }
    void Creature::set_attack_blocking(double attack_blocking) { this->attack_blocking = attack_blocking; }
    void Creature::set_crit(double crit) { this->crit = crit; }
    void Creature::set_melee_attack_power(double melee_attack_power) { this->melee_attack_power = melee_attack_power; }
    void Creature::set_range_attack_power(double range_attack_power) { this->range_attack_power = range_attack_power; }
    void Creature::set_magic_power(double magic_power) { this->magic_power = magic_power; }
    void Creature::set_physical_damage_decrease(double physical_damage_decrease) { this->physical_damage_decrease = physical_damage_decrease; }
    void Creature::set_hp_per_step(double hp_per_step) { this->hp_per_step = hp_per_step; }
    void Creature::set_energy_per_step(double energy_per_step) { this->energy_per_step = energy_per_step; }
    void Creature::set_mana_per_step(double mana_per_step) { this->mana_per_step = mana_per_step; }
    void Creature::set_parry(double parry) { this->parry = parry; }
    void Creature::set_dodge(double dodge) { this->dodge = dodge; }
    void Creature::set_hit_chance(double hit_chance) { this->hit_chance = hit_chance; }
    void Creature::set_armor_penetration(double armor_penetration) { this->armor_penetration = armor_penetration; }

    Creature::Creature() {
        int id = -1;
        string name = "";
        double intelligence = -1;
        double strenght = -1;
        double stamina = -1;
        double agility = -1;
        double spirit = -1;
        double accuracy = -1;
        double armor = -1;
        double mastery = -1;
    }

    Creature::Creature(
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
    ) {
        this->id = id;
        this->name = name;
        this->intelligence = intelligence;
        this->strenght = strenght;
        this->stamina = stamina;
        this->agility = agility;
        this->accuracy = accuracy;
        this->armor = armor;
        this->mastery = mastery;

        this->calculate_stats();
    }

    Creature::Creature(
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
        double magic_resist,
        double armor_penetration
    ) {
        this->id = id;
        this->name = name;
        this->intelligence = intelligence;
        this->strenght = strenght;
        this->stamina = stamina;
        this->agility = agility;
        this->accuracy = accuracy;
        this->armor = armor;
        this->mastery = mastery;
        this->magic_resist = magic_resist;
        this->armor_penetration = armor_penetration;

        this->calculate_stats();
    }

}
