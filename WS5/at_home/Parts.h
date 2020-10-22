/*
Name: Tran (Teryl) La
SID: 150353175
Date: October 10th, 2019
WORKSHOP 5 AT_HOME
*/

#ifndef _SDDS_PARTS_H__
#define _SDDS_PARTS_H__

namespace sdds
{
	const int MIN_FORCE = 50;
	const int MIN_SPEED = 25;

	class Arms
	{
	private:
		int force = 0; //amount of punch power
	public:
		Arms(); //default constr
		Arms(int armsForce); // 1 argument constructor
		int getForce() const;
		Arms& operator++();
		Arms operator++(int);
		Arms& operator+=(int);
	};

	//AT_HOME
	class Legs {
	private:
		int speed; // speed in the Legs
	public:
		Legs(); // default constr
		Legs(int legSpeed); //1 argu constr
		int getSpeed() const;
		Legs& operator -=(int);
	};

	//Global helper operators
	bool operator>(const Legs& legsOne, const Legs& legsTwo);
	bool operator<(const Legs& legsOne, const Legs& legsTwo);
	bool operator>(const Arms& armsOne, const Arms& armsTwo);
	bool operator<(const Arms& armsOne, const Arms& armsTwo);
}

#endif // !_SDDS_PARTS_H__


// Parts.h


