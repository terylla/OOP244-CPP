/* 
Name: Tran (Teryl) La
SID: 150353175
Date: October 8th, 2019
WORKSHOP 5 IN_LAB
*/

// Robot.h
#ifndef _SDDS_ROBOT_H__
#define _SDDS_ROBOT_H__
#include "Parts.h"

namespace sdds
{
	const int NICK_MAX_LEN = 10;

	class Robot
	{
	private:
		char nickname[NICK_MAX_LEN + 1];
		int durability;
		Arms arms;

	public:
		Robot(); 
		Robot(const char* name, int force, int durable);
		std::ostream& display() const;
		operator bool() const;
	};
}

#endif // !_SDDS_PARTS_H__
