
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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

	//set Mark object to empty state
	bool Mark::isEmpty()const {
		bool empty = false;
		if (m_mark == -1) {
			empty = true;
		}
		return empty;
	}

	//divides m_mark by m_outOf, then *100 and +0.5...cast outcome to int and returns it
	int Mark::percent()const {
		double outcome;
		outcome = (((m_mark / m_outOf) * 100) + 0.5);
		return int(outcome);
	}

	//returns result of m_mark divided by m_outOf
	double Mark::rawValue()const {
		return m_mark / (double)m_outOf;
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

	//AT_HOME 

	//Prints letter grade equivalent of the mark
	void Mark::prnLetter()const {
		if (m_mark != -1) {
			if (0 <= percent() && percent() <= 49) { cout << "F"; }
			else if (50 <= percent() && percent() <= 54) { cout << "D"; }
			else if (55 <= percent() && percent() <= 59) { cout << "D+"; }
			else if (60 <= percent() && percent() <= 64) { cout << "C"; }
			else if (65 <= percent() && percent() <= 69) { cout << "C+"; }
			else if (70 <= percent() && percent() <= 74) { cout << "B"; }
			else if (75 <= percent() && percent() <= 79) { cout << "B+"; }
			else if (80 <= percent() && percent() <= 89) { cout << "A"; }
			else if (90 <= percent() && percent() <= 100) { cout << "A+"; }
			else if (percent() > 100) { cout << "?"; }
		}
		else cout << "";
	}

	//Set m_name to content pointed by name to max 50 char
	void Mark::set(const char* name) {
		strcpy(m_name, name);
		//m_name[strlen(name)] = '\0';
	}

	//Calls set(const char*) then set(double, int)
	void Mark::set(const char* name, double rawMark, int outof) {
		set(name);
		set(rawMark, outof);
		//set(m_mark, m_outOf);
	}

	//set variables to certain values
	void Mark::setEmpty() {
		m_displayMode = DSP_UNDEFINED;
		m_mark = -1;
		m_outOf = 100;
		m_name[0] = '\0';
	}

	//print promp then read maxLen
	bool Mark::readName(const char* prompt, int maxLen) {
		bool limit = true;
		cout << prompt; //print prompt
		/*if (maxLen > 50) {

			m_name[maxLen];
			cin >> m_name;
		}
		else maxLen = 50;*/
		cin.getline(m_name, maxLen + 1);
		if (cin.fail()) {
			cin.clear();	
			flushKeyboard();
			m_name[0] = '\0'; // set m_name to empty
			limit = false;
		}	
		return limit;
	}

	//Change value of m_outOf to incoming argument, then adjust value of m_mark
	void Mark::changeOutOf(int value) {
		if (value < 1)	m_mark = -1;
		//static_cast<double>(value);
		m_mark = m_mark * ((double)value / m_outOf);
		m_outOf = value;
	}

	//Return exact GPA of mark (rawValue()*4)
	double Mark::GPA() const {
		return (rawValue() * 4);
	}

	//Return GPA value of mark based on letter grade (not GPA() function)
	double Mark::letterBasedGPA() const {
		double tempGPA = 0;
		if (0 <= percent() && percent() <= 49) { tempGPA = 0.0; }
		else if (50 <= percent() && percent() <= 54) {  tempGPA = 1.0; }
		else if (55 <= percent() && percent() <= 59) {  tempGPA = 1.5; }
		else if (60 <= percent() && percent() <= 64) {  tempGPA = 2.0; }
		else if (65 <= percent() && percent() <= 69) {  tempGPA = 2.5; }
		else if (70 <= percent() && percent() <= 74) {  tempGPA = 3.0; }
		else if (75 <= percent() && percent() <= 79) {  tempGPA = 3.5; }
		else if (80 <= percent() && percent() <= 89) {  tempGPA = 4.0; }
		else if (90 <= percent() && percent() <= 100) {  tempGPA = 4.0; }
		return tempGPA;
	}

	//display values accordingly
	ostream& Mark::display(int width) const {
		if (isEmpty()) {
			cout << "Empty Mark object!";
		}
		else {
			if (strcmp(m_name, "")) {
				cout.width(width);
				cout.fill('.');
				cout.setf(ios::left);
				cout << m_name;
				cout.unsetf(ios::left);
			}
				if (m_displayMode == DSP_RAW) {
					cout.precision(2);
					cout << rawValue();
				}
				else if (m_displayMode == DSP_PERCENT) {
					cout << "%" << percent();
				}
				else if (m_displayMode == DSP_ASIS) {
					cout.precision(1);
					cout << m_mark << "/" << m_outOf;
				}
				else if (m_displayMode == DSP_LETTER) {
					prnLetter();
				}
				else if (m_displayMode == DSP_GPA) {
					cout.setf(ios::fixed);
					cout.precision(1);
					cout << GPA();
				}
				else if (m_displayMode == DSP_UNDEFINED) {
					cout << "Display mode not set!";
				}
				else {
					cout << "Invalid Mark Display setting!";
				}
			}
	return cout;	
	}
}
