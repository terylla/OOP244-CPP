/* 
Name: Tran (Teryl) La
SID: 150353175
Date: October 8th, 2019
WORKSHOP 5 IN_LAB
*/

// Robot.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Robot.h"

using namespace std;

namespace sdds
{
	//Default constructor
	Robot::Robot() {
		nickname[0] = '\0';
		durability = 0;
		arms = 0;
	}

	//3-agrument constructor
	Robot::Robot(const char* name, int force, int durable) {
		// if nullptr or empty
		if (name == nullptr || name == '\0') { 
			Robot(); //set to safe empty state
		}
		else { 
			//set data members to the values of parameters
			strcpy(nickname, name);
			durability = durable;
			arms = force;
		}
		
		//If string from parameter > NICK_MAX_LEN
		if (strlen(name) > NICK_MAX_LEN) {
			strncpy(nickname, name, NICK_MAX_LEN + 1); //copy over NICK_MAX_LEN with nullbyte
		}
		//if durability value provided less than 1
		else if (durable < 1) {
			durability = 100; //set durability data member to 100
		}
			Arms(arms); //set value by use Arms 1 arg constructor to data member
			//arms = Arms(force);
			//Arms(force);
	}

	//display function
	ostream& Robot::display() const {
		//if (Robot()) {
		if (*this){
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
		} 
		return cout;
	}

	//Define behaviour of converting Robot into bool value
	Robot::operator bool() const {
		bool notEmpty = false;
		if (nickname[0] == '\0' && durability == 0) 
		 { 
			notEmpty = true; 
		}
		 return notEmpty; 
	}
}