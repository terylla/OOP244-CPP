

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
		Arms arms; //instance of Arms class
		Legs legs; //instance of Legs class

	public:
		Robot();
		//Update from 3 argu to 4
		Robot(const char* name, int force, int speed, int durable);
		std::ostream& display() const;
		operator bool() const;
		//AT_HOME 
		Arms getArms() const;
		Legs getLegs() const;
		Robot& operator -=(int);
	};
	void box(Robot& robotOne, Robot& robotTwo);
}

#endif // !_SDDS_PARTS_H__
