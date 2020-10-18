/*
Name: Tran (Teryl) La
SID: 150353175
WORKSHOP 3 AT_HOME
SEPTEMBER 29th, 2019
*/

#define _CRT_SECURE_NO_WARNINGS_
#ifndef _SDDS_MARK_H__
#define _SDDS_MARK_H__

#include <iostream>

namespace sdds {
	const int DSP_RAW = 1;
	const int DSP_PERCENT = 2;
	const int DSP_ASIS = 3;
	const int DSP_UNDEFINED = -1;
	const int DSP_GPA = 4;
	const int DSP_LETTER = 5;

	class Mark {
	private:
		int m_displayMode; // holds how mark displays
		double m_mark; // actual mark given for assessment
		int m_outOf; // maximum value for mark
		void flushKeyboard()const; // read 1 char at a time using cin.get() until newline
		//AT_HOME
		char m_name[51];
		void prnLetter() const;
	public:
		void set(int displayMode); // sets m_displayMode to value of incoming argument (displayMode)
		void set(double mark, int outOf = 1); // sets m_mark and m_outOf to corresponding arguments
		//void setEmpty();
		bool isEmpty()const;
		int percent()const;
		double rawValue()const;
		bool read(const char* prompt);
		//std::ostream& display() const;
		//AT_HOME
		void set(const char* name);
		void set(const char* name, double rawMark, int outof = 1);
		void setEmpty();
		bool readName(const char* prompt, int maxLen = 50);
		void changeOutOf(int value);
		double GPA()const;
		double letterBasedGPA() const;
		std::ostream& display(int width = 55)const;
	};

}
#endif // !_SDDS_MARK_H__




