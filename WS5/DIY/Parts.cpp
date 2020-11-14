

// Parts.cpp
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Parts.h"

using namespace std;

namespace sdds
{
	//Default constructor
	Arms::Arms() {
		force = 0;
	}

	//Default constructor
	Legs::Legs() {
		speed = 0;
	}


	//Represent the arm force
	Arms::Arms(int armsForce) {
		if (armsForce < 1) //if parameter value less than 1
		{
			armsForce = MIN_FORCE;  //set respective force to be value of MIN_FORCE
			force = armsForce;
		}
		else force = armsForce; // else set data member to be of parameter
	}

	//Represent the leg's speed
	Legs::Legs(int legSpeed) {
		if (legSpeed < 1) {
			legSpeed = MIN_SPEED;
			speed = legSpeed;
		}
		else speed = legSpeed;
	}

	//Returns force of Arms
	int Arms::getForce() const {
		return force;
	}

	//Return speed of Legs
	int Legs::getSpeed() const {
		return speed;
	}

	// ARMS Pre-fix increment
	Arms& Arms::operator++() {
		force += 10; //Arms' force will be incrememnted by 10
		return *this; // Return current obj
	}

	// ARMS Post-fix increment	
	Arms Arms::operator++(int) {
		Arms tempArms = *this; 	//Copy of current obj Arms created
		++(*this); //Current object will be incremented by 10 (call pre-fix)
		return tempArms; //Return the copy
	}

	// ARMS Plus equals(assinment)
	Arms& Arms::operator+=(int result) {
		force += result; //Curent obj increases force based on passed int parameter
		if (force < 1) //If result of operato less than 1
		{
			force = 0; //Set value to 0		
		}
		return *this; //After, return current obj
	}

	// LEGS minus equals
	Legs& Legs::operator-=(int result) {
		speed -= result;
		if (speed < 1) {
			speed = 0;
		} 
		return *this;
	}

	bool operator>(const Legs& legsOne, const Legs& legsTwo) {
		return legsOne.getSpeed() > legsTwo.getSpeed();
	}

	bool operator<(const Legs& legsOne, const Legs& legsTwo) {
		return legsOne.getSpeed() < legsTwo.getSpeed();
	}


	bool operator>(const Arms& armsOne, const Arms& armsTwo) {
		return armsOne.getForce() > armsTwo.getForce();
	}

	bool operator<(const Arms& armsOne, const Arms& armsTwo) {
		return armsOne.getForce() < armsTwo.getForce();
	}
}

// THIS WORKS TOO
//	// LEGS if legsOne faster then true
//	bool operator>(const Legs& legsOne, const Legs& legsTwo) {
//		bool faster = true;
//		if (legsOne.getSpeed() < legsTwo.getSpeed()) {
//			faster = false;
//		} return faster;
//	}
//
//	//LEGS if legsOne slower then true
//	bool operator<(const Legs& legsOne, const Legs& legsTwo) {
//		bool slower = true;
//		if (legsOne.getSpeed() > legsTwo.getSpeed()) {
//			slower = false;
//		} return slower;
//	}
//
//	//ARMS if armsOne has more force then true
//	bool operator>(const Arms& armsOne, const Arms& armsTwo) {
//		bool greater = true;
//		if (armsOne.getForce() < armsTwo.getForce()) {
//			greater = false;
//		} return greater;
//	}
//
//	//ARMS if armsOne has less force then true
//	bool operator<(const Arms& armsOne, const Arms& armsTwo) {	
//		bool weaker = true;
//		if (armsOne.getForce() > armsTwo.getForce()) {
//			weaker = false;
//		} return weaker;
//	}
//}

