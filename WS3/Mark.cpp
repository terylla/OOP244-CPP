/*
Name: Tran (Teryl) La
SID: 150353175
WORKSHOP 3 IN_LAB
SEPTEMBER 24th, 2019
*/

#include <iostream>
#include "Mark.h"
using namespace std;

namespace sdds {

	//Read 1 char at time using cin.get() until newline
	void Mark::flushKeyboard()const {
		char chr;
		do {
			chr = cin.get();
		} while (chr != '\n');
	}

	// sets m_displayMode to value of displayMode
	void Mark::set(int displayMode) {
		m_displayMode = displayMode;
	}

	// set m_mark and m_outOf to corresponding arguments
	void Mark::set(double mark, int outOf) {
		m_mark = mark;
		m_outOf = outOf;
	}

	//set variables to certain values
	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
	}

	//set Mark object to empty state
	bool Mark::isEmpty()const {
		bool empty = false;
		if (m_mark == -1 /*&& m_displayMode == DSP_UNDEFINED && m_outOf == 100)*/) {
			empty = true;
		}
		return empty;
	}

	//divides m_mark by m_outOf, then *100 and +0.5...cast outcome to int and returns it
	int Mark::percent()const {
		double outcome;
		outcome = (((m_mark / m_outOf) * 100) + 0.5);
		return double(outcome);
	}

	//returns result of m_mark divided by m_outOf
	double Mark::rawValue()const {
		return m_mark / m_outOf;
	}

	//read values accordingly
	bool Mark::read(const char* prompt) {
		bool success = true;
		cout << prompt;
		cin >> m_mark;
		cin.ignore();
		cin >> m_outOf;
		if (cin.fail()) {
			cin.clear();
			setEmpty();
			//flushKeyboard();
			success = false;
		}
			flushKeyboard();
			return success;
	}

	//display values accordingly
	ostream& Mark::display() const  {
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
			else if (m_displayMode == DSP_RAW) {
				cout << rawValue();
			}
			else if (m_displayMode == DSP_PERCENT) {
				cout << "%" << percent();
			}
			else if (m_displayMode == DSP_ASIS) {
				cout << m_mark << "/" << m_outOf;
			}
			else if (m_displayMode == DSP_UNDEFINED) {
				cout << "Display mode not set!";
			}
			else {
				cout << "Invalid Mark Display setting!";
			}
		return cout;
	}

}
