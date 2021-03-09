#include "Student.h"
#define STUDENTS_FOR_THE_DAY 2

void write()
{
	Student* students = new Student[STUDENTS_FOR_THE_DAY];

	for (int i = 0; i < STUDENTS_FOR_THE_DAY; i++)
	{
		initStudent(students[i]);
	}

	writeStudents("studentsDB.bin", students, STUDENTS_FOR_THE_DAY);

	printStudents(students, STUDENTS_FOR_THE_DAY);

	for (int i = 0; i < STUDENTS_FOR_THE_DAY; i++)
	{
		clearDynamic(students[i]);
	}
	delete[] students;
}

void read()
{
	size_t n;

	Student* students = readStudents("studentsDB.bin", n);

	printStudents(students, n);

	for (int i = 0; i < n; i++)
	{
		clearDynamic(students[i]);
	}
	delete[] students;
}

int main()
{
	//write();
	 read();
	
	return 0;
}