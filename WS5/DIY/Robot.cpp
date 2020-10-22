/*
Name: Tran (Teryl) La
SID: 150353175
Date: October 10th, 2019
WORKSHOP 5 AT_HOME
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
	Robot::Robot(const char* name, int force, int speed, int durable) {
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
		arms = Arms(force); //set value by use Arms 1 arg constructor to data member
		legs = Legs(speed); // ^
	}


	//display function
	ostream& Robot::display() const {
		if (*this) {
			cout << "This Robot isn't operational" << endl;
		}
		else {
			cout << "***Robot Summary***" << endl;
			cout << "Nickname: " << nickname << endl;
			cout << "Arm Power: " << arms.getForce() << endl;
			cout << "Durability: " << durability << endl;
			cout << "Legs: " << legs.getSpeed() << endl;
		}
		return cout;
	}

	//Define behaviour of converting Robot into bool value
	Robot::operator bool() const {
		return nickname[0] == '\0' || durability < 0;
	}

	//return copy of instance of Arms of current obj
	Arms Robot::getArms() const {
		Arms temp = this->arms;
		return temp;
	}

	//return copy of instance of Legs of current obj
	Legs Robot::getLegs() const {
		Legs temp = this->legs;
		return temp;
	}

	//Minus equal assignment
	Robot& Robot::operator-=(int value) {
		durability -= value; //current obj have durability lowered by int parameter passed in
		if (value < 1) {
			durability = 0;
		} return *this;
	}

	void box(Robot& robotOne, Robot& robotTwo) {
		cout << "Attempting to begin a Robot boxing match" << endl;

		//if Robots are in an empty state (not operational) then no bout
		if (robotOne || robotTwo) {
			cout << "At least one of the Robots isn't operational. No bout will be had." << endl;
		}

		//if Robots can fight then..
		else {
			cout << "Both participants are operational... beginning the bout" << endl;

			//LOOP: while both robots are operational
			while (!robotOne && !robotTwo) {

				//if robotOne is faster
				if (robotOne.getLegs() > robotTwo.getLegs()) {
					robotTwo -= robotOne.getArms().getForce(); //force of Arms reduce durability of weaker robot

					//if first strike reduces durability to 0 then no fight back
					//otherwise attack back, same effect
					if (!robotTwo) {
						robotOne -= robotTwo.getArms().getForce();
					}
				}
				else {
						robotOne -= robotTwo.getArms().getForce();
					 if (!robotOne) {
						robotTwo -= robotOne.getArms().getForce();
					}
				}
			} 
			cout << "The bout has concluded... the winner is: " << endl;
			if (!robotOne) {
				robotOne.display();
			} 
			else {
				robotTwo.display();
			}
		}
	}
}
