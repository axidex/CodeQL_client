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


#include "../include/DialoguesTool.h"

namespace Hoopoe 
{

vector<string> v_i_dialogues;
vector<Dialogue> v_dialogues;

vector<int> convert_dialogue_index(string index, int n, vector<int> nums) 
{
	if(index[n] == '\0') 
	{
		string num_1 = "";
		int num_2 = 0;
		
		for(int i = 0; i < n; ++i) {
			num_1 += index[0];
			index.erase(0, 1);
		}
		
		stringstream geek(num_1);
		geek >> num_2;
		nums.push_back(num_2);
		
		return nums;
	}
	
	if(index[n] == '_') 
	{
		string num_1 = "";
		int num_2 = 0;
		
		for(int i = 0; i < n; ++i) {
			num_1 += index[0];
			index.erase(0, 1);
		}
		
		if(index[0] == '_') { index.erase(0, 1); }
		
		stringstream geek(num_1);
		geek >> num_2;
		nums.push_back(num_2);
		
		n = 0;
		return convert_dialogue_index(index, n, nums);
	}
	
	++n;
	return convert_dialogue_index(index, n, nums);
}

void add_dialogue(string index, string dialogue_text, size_t count, ...) 
{
	v_i_dialogues.push_back(index);
	
	vector<Option> v_Options;
	
	va_list args;
	va_start(args, count);
	for(size_t i = 0; i < count; ++i) {
		char* str = va_arg(args, char*);
		
		v_Options.push_back(Option(string(str), Dialogue()));
	}

	va_end(args);
	
	v_dialogues.push_back(Dialogue(dialogue_text, v_Options));
}

void collect_dialogues() 
{	  
	for(int i = v_i_dialogues.size() - 1; i > 0; --i) 
	{
		vector<int> temp = convert_dialogue_index(v_i_dialogues.back(), 0, vector<int>());
		
		int index = 0;
		for(int j = temp.size() - 2; j > 0; --j) {
			index += temp[j];
		}
		
		v_dialogues[index].set_option(temp.back() - 1, Option(v_dialogues[index].get_option(temp.back() - 1).get_text(), v_dialogues[i]));
		
		v_i_dialogues.pop_back();
	}
	
	converse(v_dialogues[0]);
}

}
