

#include <iostream>
#include "Subject.h"  
#include "utils.h"
#include "School.h"

using namespace std;

namespace sdds {


	void read(School& Sch) {

		Sch.m_name = new char[61]; // DyAl. memory in Sch.m_name and copy local array in it
		cout << "Please enter the name of the school:\n> ";
		read(Sch.m_name, 60, "Name is too long, only 60 characters allowed!\nRedo Entry: "); //read name of School
		cout << "Please enter the number of subjects offered by " << Sch.m_name << ": ";
		read(Sch.m_noOfSubjects, 2, 50, "Invalid Number of subjects, 2<=ENTRY<=50\nRedo Entry: "); //Pass reference of Sch.m_noOfSubjects in read
		Sch.m_subjects = new Subject[Sch.m_noOfSubjects]; //DyAl array of Subjects to size of int just read ^
		int i;
		for ( i = 0; i < Sch.m_noOfSubjects; i++) { //Loop to repeat to number of Subjects		
			cout << i + 1 << ") ------------------------------" << endl; //Print sequence numver and separator before each read function
			read(Sch.m_subjects[i]); //Call read function on each element for reading each Subjec
		}
	}

	//Print total enrollment
	int report(const School & Sch) {
		cout << Sch.m_name << endl;
		cout << "Subject Enrollments" << endl;
		int totalEnrollment = 0;
		int i;
		for (i = 0; i < Sch.m_noOfSubjects; i++) {
			totalEnrollment = totalEnrollment + report(Sch.m_subjects[i]);
		}
		cout << "Total enrollment: " << totalEnrollment << endl;
		return totalEnrollment;
	}

	//Deallocate memory
	void freeMem(School& Sch){
		delete[] Sch.m_name;
		int i;
		for (i = 0; i < Sch.m_noOfSubjects; i++) {
			freeMem(Sch.m_subjects[i]);
		}
		delete[] Sch.m_subjects;
	}
}
