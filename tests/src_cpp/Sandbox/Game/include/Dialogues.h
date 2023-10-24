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


#ifndef __SANDBOX_GAME_DIALOGUES_H__
#define __SANDBOX_GAME_DIALOGUES_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

namespace Hoopoe 
{

class Option;

class Dialogue 
{
public:
	Dialogue();
	Dialogue(string &text, vector<Option> options);

	bool exist();

	string get_text();
	Option get_option(int index);
	vector<Option> get_options();
	void set_option(int index, Option option);

	void echo_dialogue();
	void echo_options();
	void echo();

private:
	string text;
	vector<Option> options;
};

class Option 
{
public:
	Option();
	Option(string text, Dialogue next_dialogue);

	bool exist();

	Dialogue get_next_dialogue();
	string get_text();
private:
	Dialogue next_dialogue;
	string text;
};

void converse(Dialogue dialogue);

}

#endif
