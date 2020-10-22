// RobotSquad.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "RobotSquad.h"

using namespace std;

namespace sdds {

	//default constructor
	RobotSquad::RobotSquad() {
		r_name[0] = '\0';
		roster = 0;
		noOfRobots = 0;
	}

	RobotSquad::RobotSquad(const char* name, int rost, int num) {
		if (name == nullptr && rost == 0 && num == 0) {
			RobotSquad();
		}
		else {
			strcpy(r_name, name);
			roster = rost;
			noOfRobots = num;
		}
	}

	ostream& RobotSquad::display() const {
		if (roster == 0) {
			cout << "Squad **" << r_name << "** has no members" << endl;
		}
		else {
			cout << "***Squad Summary***" << endl;
			cout << "Name: " << r_name << endl;
			cout << "Roster Count: " << noOfRobots << endl;
			cout << "Roster: " << endl;
			Robot.display();
		}
	}
}