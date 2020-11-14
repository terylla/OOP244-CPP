
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
