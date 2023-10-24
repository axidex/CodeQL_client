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


#include <Hoopoe.h>
#include <stdio.h>

#include "Game/GameHeaders.h"

class Sandbox : public Hoopoe::Application 
{
public:
    Sandbox() 
    {
        HE_CLIENT_INFO("Ok.");
    }

    ~Sandbox() {}
};

Hoopoe::Application* Hoopoe::CreateApplication() 
{
    return new Sandbox();
}


// Location northland(1, "Североземье", TOWN);
// Location crossroads(2, "Златоземье", CROSSROADS);

// a_location n_to_crossroads(&crossroads, 2);
// a_location c_to_northland(&northland, 2);

// vector<a_location> v_northland; v_northland.push_back(n_to_crossroads);
// vector<a_location> v_crossroads; v_crossroads.push_back(c_to_northland);

// northland.set_a_locations(v_northland);
// crossroads.set_a_locations(v_crossroads);

// Player player(1, "Ворвол", 10, 5, 10, 5, 0, 70, 0, 0, &northland);

// player.get_location().echo_a_locations();

// int num;
// while(true) {
//     cin >> num;
//     switch(num) {
//     case 1:
//         player.set_location(*player.get_location().get_a_locations()[0].location);
//         break;
//     }

//     player.get_location().echo_a_locations();
// }


/*
add_dialogue("1", "� ������� ���������... �� �����������...", 3, "������������, ��������!", "����� � ����, ������!", "���� ���� ��������, ���!");

add_dialogue("1_1", "� ������ ����� ����� ��������� �������\n����� ���������� � ����� ���!", 1, "��� ����������. ������ ������.");
add_dialogue("1_2", "���� ��� �����. �� ����� ��� ���������, � �� ������ ���� ��������. �� ����� ��� ������, �� ����� ���� ��������?", 4, "������ ���, � ����� ����� �� ���", "� ������ ��, � ���� ���-�� �� �����������", "������ ���� ��������, ������ ��� ���������, ��� ���� � ���� ������", "����� ������ ����� ����� �� ��� �����?");
add_dialogue("1_3", "��� ����� �� ��, �������? �� � ��� ���� �������� �� ���� ������.", 1, "��� ����������. ������ ������.");

add_dialogue("1_2_1", "� ��� ��� ������� ��� � �������", 1, "��� ����������. ������ ������.");
add_dialogue("1_2_2", "�� ��� �� �����������, ������ ����������", 1, "��� ����������. ������ ������.");
add_dialogue("1_2_3", "����� ����������, ����� �������� ��������� ������ ������ �� 9999�. ������ ���������� �� QIWI +79097906796", 1, "�����������! �� ������� ����� � ����!");
add_dialogue("1_2_4", "��� ��� ����� ���������. ������� �� ��� ����, � ����� �� ���� ������.", 1, "��� ����������. ������ ������.");

collect_dialogues();
*/
