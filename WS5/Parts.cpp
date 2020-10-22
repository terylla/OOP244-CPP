/* 
Name: Tran (Teryl) La
SID: 150353175
Date: October 8th, 2019
WORKSHOP 5 IN_LAB
*/

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

	//Represent the arm force
	Arms::Arms(int armsForce) {
		if (armsForce < 1) //if parameter value less than 1
		{
			armsForce = MIN_FORCE;  //set respective force to be value of MIN_FORCE
			force = armsForce;
		}
		else force = armsForce; // else set data member to be of parameter
	}

	//Returns force of Arms
	int Arms::getForce() const {
		return force;
	}

	//Pre-fix increment
	Arms& Arms::operator++() {
		force += 10; //Arms' force will be incrememnted by 10
		return *this; // Return current obj
	}

	//Post-fix increment	
	Arms Arms::operator++(int) {
		Arms tempArms = *this; 	//Copy of current obj Arms created
		++(*this); //Current object will be incremented by 10 (call pre-fix)
		return tempArms; //Return the copy
	}

	//Plus equals(assinment)
	Arms& Arms::operator+=(int result) {
		force += result; //Curent obj increases force based on passed int parameter
		if (result < 1) //If result of operato less than 1
		{ 	
			force = 0; //Set value to 0		
		} 	
			return *this; //After, return current obj
	}






}

