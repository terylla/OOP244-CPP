/*
Name: Tran (Teryl) La
SID: 150353175
WORKSHOP 3 IN_LAB
SEPTEMBER 24th, 2019
*/

#ifndef _SDDS_MARK_H__
#define _SDDS_MARK_H__

#include <iostream>
using namespace std;

namespace sdds {
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;

	class Mark {
	private:
		int m_displayMode; // holds how mark displays
		double m_mark; // actual mark given for assessment
		int m_outOf; // maximum value for mark
		void flushKeyboard()const; // read 1 char at a time using cin.get() until newline
	public:
		void set(int displayMode); // sets m_displayMode to value of incoming argument (displayMode)
		void set(double mark, int outOf = 1); // sets m_mark and m_outOf to corresponding arguments
		void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		std::ostream& display() const;
	};

}
#endif // !_SDDS_MARK_H__




