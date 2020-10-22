#ifndef _SDDS_FLOWER_H__
#define _SDDS_FLOWER_H__

namespace sdds {
	const int NAME_MAX_LEN = 25;
	const int COL_MAX_LEN = 15;

	class Flower {
	private:
		char* f_name; //name of flower
		char* f_colour; //colour of flower
		double f_price; //price of flower
	public:
		Flower(); // default constructor to set Flower object to safe empty state
		~Flower();
		Flower(const char* name, const char* colour, double price);
		const char* name() const;
		const char* colour() const;
		double price() const;
		bool isEmpty() const;
		void setEmpty();
		void setName(const char* prompt);
		void setColour(const char* prompt);
		void setPrice(const char* prompt);
		void setFlower();
		std::ostream& display() const;
	};
}
#endif