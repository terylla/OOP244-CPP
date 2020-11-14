

#ifndef SDDS_SCHOOL_H__
#define SDDS_SCHOOL_H__
#include "Subject.h"

namespace sdds
{
	struct School
	{
		int m_noOfSubjects;
		Subject* m_subjects;
		char* m_name;
	};

	void read(School& Sch);
	int report(const School& Sch);
	void freeMem(School& Sch);
}
#endif // !
