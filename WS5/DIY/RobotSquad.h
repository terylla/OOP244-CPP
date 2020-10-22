// RobotSquad.h
#ifndef _SDDS_ROBOTSQUAD_H__
#define _SDDS_ROBOTSQUAD_H__
#include "Robot.h"

namespace sdds {
	class RobotSquad {
	private:
		char r_name[10] = "No Name";
		int roster;
		int noOfRobots;
	public:
		RobotSquad(); //default constructor
		RobotSquad(const char* name, int rost, int num); 
		RobotSquad& operator+=(int);
		RobotSquad& operator--(int);
		std::ostream& display() const;
	};
}

#endif
