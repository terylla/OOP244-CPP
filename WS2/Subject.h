/*
Name: Tran (Teryl) La
SID: 150353175
Date: Sept 22, 2019
WORKSHOP 2 AT_HOME
*/

#ifndef SDDS_SUBJECT_H__
#define SDDS_SUBJECT_H__
namespace sdds
{
	struct Subject
	{
		int* m_noOfSections;
		int* m_noOfStdsInSecs;
		char* m_subjectName;
	};

	void read(char* name);
	void read(int& num);
	void read(int noOfStu[], int sect);
	void read(Subject&);
	int report(const Subject&);
	void freeMem(Subject&);
}
#endif // !