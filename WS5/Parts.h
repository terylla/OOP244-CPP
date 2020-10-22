/* 
Name: Tran (Teryl) La
SID: 150353175
Date: October 8th, 2019
WORKSHOP 5 IN_LAB
*/

#ifndef _SDDS_PARTS_H__
#define _SDDS_PARTS_H__

namespace sdds
{
	const int MIN_FORCE = 50;
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
}

#endif // !_SDDS_PARTS_H__


// Parts.h
