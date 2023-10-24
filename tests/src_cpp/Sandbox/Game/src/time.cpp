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


#include "../include/time.h"

namespace Hoopoe {

	int count_of_steps = 2628000; // 2628000 - 50 years / 52560 - 1 year / 1008 - 1 week / 144 - 1 day / 6 - 1 hour
	int steps_left = 1628000;

	int get_period(period_type type) {
		int steps_passed = count_of_steps - steps_left;
		switch(type) {
		case STEPS:
			return steps_passed;
		case MINS:
			return steps_passed * 10;
		case HOURS:
			return steps_passed / 6;
		case DAYS:
			return steps_passed / 144;
		case YEARS:
			return steps_passed / 52560;
		}

		return -1;
	}

	string get_age() {
		string age = "";

		if(get_period(YEARS) > 0) {
			stringstream temp;
			temp << get_period(YEARS);
			age += temp.str();

			if(get_period(YEARS) == 1) {
				age += " год";
			} else if(get_period(YEARS) > 1 && get_period(YEARS) < 5) {
				age += " года";
			} else {
				age += " лет";
			}
		}

		if(get_period(STEPS) - get_period(YEARS) * 52560 > 0) {
			int current_steps = get_period(STEPS) - get_period(YEARS) * 52560;

			if(current_steps >= 144) {
				int current_days = current_steps / 144;;

				if(get_period(YEARS) >= 1) {
					age += " ";
				}

				stringstream temp;
				temp << current_days;
				age += temp.str();

				if(current_days % 10 == 1) {
					age += " день";
				} else if(current_days % 10 > 1 && current_days % 10 < 5) {
					age += " дня";
				} else {
					age += " дней";
				}

				current_steps -= current_days * 144;
			}

			if(current_steps / 6 > 0) {
				int current_hours = current_steps / 6;

				if(get_period(YEARS) >= 1 || get_period(DAYS) >= 1) {
					age += " ";
				}

				stringstream temp;
				temp << current_hours;
				age += temp.str();

				if(current_hours == 1 || current_hours == 21) {
					age += " час";
				} else if(current_hours < 5 && current_hours > 21){
					age += " часов";
				} else {
					age += " часа";
				}

				current_steps -= current_hours * 6;
			}

			if(current_steps * 10 > 0) {
				int current_mins = current_steps * 10 ;

				if(get_period(YEARS) >= 1 || get_period(DAYS) >= 1 || get_period(HOURS) >= 1) {
					age += " ";
				}

				stringstream temp;
				temp << current_mins;
				age += temp.str();

				if(current_mins % 10 == 1) {
					age += " минута";
				} else if(current_mins % 10 > 1 && current_mins % 10 < 5){
					age += " минуты";
				} else {
					age += " минут";
				}
			}
		}

		return age;
	}

	string get_time() {
		string current_time = "";
		int temp_steps = get_period(STEPS);
		int temp_hours = 0;
		int temp_mins = 0;

		if(get_period(YEARS) > 0) {
			temp_steps -= get_period(YEARS) * 52560;
		}

		if(temp_steps > 144) {
			temp_steps = temp_steps % 144;
		}

		temp_mins = temp_steps * 10;

		if(temp_mins > 59) {
			temp_hours = temp_mins / 60;
			temp_mins -= temp_hours * 60;
		}

		if(temp_hours < 10) {
			current_time += "0";
		}

		stringstream temp_1;
		temp_1 << temp_hours;
		current_time += temp_1.str();

		current_time += ":";

		if(temp_mins < 10) {
			current_time += "0";
		}

		stringstream temp_2;
		temp_2 << temp_mins;
		current_time += temp_2.str();

		return current_time;
	}

}
