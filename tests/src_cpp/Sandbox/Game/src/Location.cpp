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


#include "../include/Location.h"

namespace Hoopoe {

	Location::Location() { index = -1; location_name = ""; type = UNKOWN; }
	Location::Location(int index, string location_name, Location_type type) {
		this->index = index;
		this->location_name = location_name;
		this->type = type;
	}

	Location::Location(int index, string location_name, Location_type type, vector<a_location> &a_locations) {
		this->index = index;
		this->location_name = location_name;
		this->type = type;
		this->a_locations = a_locations;
	}

	int Location::get_index() { return this->index; }
	string Location::get_location_name() { return this->location_name; }
	Location_type Location::get_type() { return this->type; }
	vector<a_location> Location::get_a_locations() { return this->a_locations; }

	void Location::set_index(int index) { this->index = index; }
	void Location::set_location_name(string location_name) { this->location_name = location_name; }
	void Location::set_type(Location_type type) { this->type = type; }
	void Location::set_a_locations(vector<a_location> &a_locations) { this->a_locations = a_locations; }
	void Location::set_a_location(Location &location) {
		this->index = location.get_index();
		this->location_name = location.get_location_name();
		this->type = location.get_type();
		this->a_locations = location.get_a_locations();
	}

	void Location::echo_a_locations() {
		for(int i = 0; i < a_locations.size(); ++i) {
			cout << (i+1) << ") " << a_locations[i].location->get_location_name();
			if(a_locations.at(i).require_steps % 10 == 1) {
				cout << " - " << a_locations.at(i).require_steps << " ход";
			} else if(a_locations.at(i).require_steps % 10 > 1 && a_locations.at(i).require_steps % 10 < 5) {
				cout << " - " << a_locations.at(i).require_steps << " хода";
			} else {
				cout << " - " << a_locations.at(i).require_steps << " ходов";
			}

			cout << endl;
		}
	}

	a_location::a_location() {}

	a_location::a_location(Location *location, int require_steps) {
		this->location = location;
		this->require_steps = require_steps;
	}

}
