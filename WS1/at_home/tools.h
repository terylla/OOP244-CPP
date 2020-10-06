/*
Name: Tran (Teryl) La
SID: 150353175
OOP244 - NCC - FALL 2019
WORKSHOP 1 - At home
*/

#ifndef _SDDS_TOOLS_H__
#define _SDDS_TOOLS_H__


namespace sdds
{
	// Performs a fool-proof integer entry
	int getInt(int min, int max);

	// moves the cursor backwards
	void goBack(int n);

	// displays the user interface menu
	int menu(int noOfSamples);

	// Draws a line and adds a label if provided
	void line(int n, const char* label = nullptr);
}
#endif // !_TOOLS_H__