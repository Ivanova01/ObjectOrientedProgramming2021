#pragma once

struct Student
{
	int mId;
	char* mFirstName;
	char* mLastName;
	char* mFacultyNumber;
	int mAge;
	char* mSpecialty;
	char* mFaculty;
};

void initStudent(Student& student);
void clearDynamic(Student& student);
void writeStudents(const char* filename, Student* students, size_t numStudents);
Student* readStudents(const char* filename, size_t& numReadStudents);
void printStudents(Student* students, size_t numStudents);

