
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Flower.h"
#include "utils.h"
using namespace std;

namespace sdds {

	//default constructor for safe empty state
	Flower::Flower() {
		f_name[0] = '\0';
		f_colour[0] = '\0';
		f_price = 0;
	}

	//3 parameters used to initialize new Flower object
	Flower::Flower(const char* name, const char* colour, double price) {
		//if ( (name == nullptr) &&  (colour == nullptr) && (price <= 0)) {
		//	*this = Flower();
		//}
		//else //if valid, new dynamic memory
		//{
		//	f_name = new char;
		//	strcpy(f_name, name);
		//	f_colour = new char;
		//	strcpy(f_colour, colour);
		//	f_price = price;
		//}
		bool valid = (name == nullptr) && (colour == nullptr) && (price <= 0);
		if (!valid) {
			Flower();
		}
		else { 
			f_name = new char[0];
			memcpy(f_name, name, NAME_MAX_LEN);
			f_colour = new char[0];
			memcpy(f_colour, colour, COL_MAX_LEN);
			//f_price = new double;
			f_price = price;
		}
	}
	
	//Deallocate memory
	Flower::~Flower() {
		delete[] f_name;
		delete[] f_colour;
		//delete f_price;
		if (f_name == nullptr) {
			cout << "An unknown flower has departed..." << endl;
		}
		else {
			cout << f_colour << f_name << " has departed..." << endl;
		}
	}

	//Query function returns name of Flower
	const char* Flower::name() const {
		return f_name;
	}

	//Query function returns colour of Flower
	const char* Flower::colour() const {
		return f_colour;
	}

	//Query function returns colour of Flower
	double Flower::price() const {
		return f_price;
	}

	//Returns True if Flower is empty or else False
	bool Flower::isEmpty()const {
		bool valid = f_name == nullptr && f_colour == nullptr && f_price == 0;
		return !valid;
		//bool empty = true;
		//if (f_name != nullptr /*&& f_colour == '\0' && f_price == 0*/) {
		//	empty = false;
		//}
		//else return empty;
	}

	//Set Flower object to empty state
	void Flower::setEmpty() {
		Flower();
	}

	//Set nane of Flower using data entered from a user
	//Prompt will prompt the user prior to accepting user data for name
	//If user enters data of an invalid length [25], prompted of error and try again
	void Flower::setName(const char* prompt) {
		cout << prompt;
		char name[NAME_MAX_LEN + 1];
		read(f_name, NAME_MAX_LEN, "A flower's name is limited to 25 characters... Try again: ");
		copystr(f_name, name, NAME_MAX_LEN);
	}

	//Similar to setName
	void Flower::setColour(const char* prompt) {
		cout << prompt;
		char colour[COL_MAX_LEN + 1];
		read(f_colour, COL_MAX_LEN, "A flower's colour is limited to 15 characters... Try again: ");
		copystr(f_colour, colour, COL_MAX_LEN);
	}

	//Price cannot be less or equal to zero
	void Flower::setPrice(const char* prompt){
		cout << prompt;
		cin >> f_price;
		if (cin.fail() || f_price <= 0) {
			cout << "A flower's price is a non-negative number... Try again: ";
			cin.clear();
			cin.ignore(1000, '\n');
		}
	/*	if ((double)f_price <= 0.0) {
			cout << "A flower's price is a non-negative number... Try again: ";
			cin >> f_price;
		}
		else {
			cin >> f_price;
		}*/
		//read(f_price, unsigned(1), "A flower's price is a non-negative number... Try again: ");
	}

	void Flower::setFlower() {
		cout << "The beginning of a new flower..." << endl;
		setName("Enter the flower's name... : ");
		setColour("Enter the flower's colour... : ");
		setPrice("Enter the flower's price... : ");
		cout << "The flower's current details..." << endl;
		display();
	}

	ostream& Flower::display() const {
		if (isEmpty()) {
			cout << "This is an empty flower..." << endl;
		}
		else {
			cout << "Flower: " << f_colour << f_name << "Price: " << f_price << endl;
		}
		return cout;
	}

	
}