

#include <iostream>
#include "Subject.h"  
#include "utils.h"

using namespace std;
namespace sdds
{

	//Read subject name
	void read(char* subjectName) {
		cout << "Enter subject name: ";
		read(subjectName, 70, "Name is too long, only 70 characters allowed!\nRedo Entry: ");
	}

	//Read number of section
	void read(int& noOfSection) {
		cout << "Enter number of sections: ";
		read(noOfSection, 1, 10, "Invalid Number of sections, 1<=ENTRY<=10\nRedo Entry: ");
	}

	//read number of student in certain section
	void read(int noOfStu[35], int noOfSect) {
		cout << "Enter the number of students in each one of the" << " " << noOfSect << " sections:" << endl;
		int i;
		for (i = 0; i < noOfSect; i++) {
			cout << i + 1 << ": ";
			read(noOfStu[i], 5, 35, "Invalid Number of students, 5<=ENTRY<=35\nRedo Entry: ");
		}
	}

    	void read(Subject& Sub) {	
			Sub.m_subjectName = new char[71]; //Dy.allo. memory of local array into Sub.m_subjectName
			read(Sub.m_subjectName); // Read name of subject into it
			Sub.m_noOfSections = new int; //Dy.allo. an int and keep its address in Sub.m_noOfSections
			read(*Sub.m_noOfSections); // Read function passing reference of allocated int into it
			Sub.m_noOfStdsInSecs = new int[*Sub.m_noOfSections]; //Dy.allo. array of int in Sub.m_noOfstdsInsecs to size of int just read (# of sect)
			read(Sub.m_noOfStdsInSecs, *Sub.m_noOfSections); //Read # of students in each sections
	}

		
		//I GOT HELP FROM JIHEE KIM FOR THIS
		int report(const Subject& Sub) {
			int total = 0;
			int i;
			for (i = 0; i < *Sub.m_noOfSections; i++) { //First line print comma separated list of all sections
				cout << Sub.m_noOfStdsInSecs[i];
				total = total + Sub.m_noOfStdsInSecs[i];
				if (i < *Sub.m_noOfSections - 1) {
					cout << ",";
				}
				else cout << endl;
			}

			cout << Sub.m_subjectName << ": " << total << endl;  //Second line print name of subject and total enrollment

			return total; //return total enrollment
		}
		

		//Deallocate memory
		void freeMem(Subject& Sub) {
			delete[] Sub.m_subjectName;
			delete Sub.m_noOfSections;
			delete[] Sub.m_noOfStdsInSecs;
		}
}
		
		
