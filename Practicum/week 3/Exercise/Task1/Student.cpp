#include "Student.h"
#define STRING_FIELD_MAX 50
#include <iostream>
#include <fstream>
#include <cstring>

size_t studentsCounter = 0;

void initStudent(Student& student)
{
	student.mId = ++studentsCounter;

	student.mFirstName = new char[STRING_FIELD_MAX];
	std::cout << "Input student first name:";
	std::cin >> student.mFirstName;

	student.mLastName = new char[STRING_FIELD_MAX];
	std::cout << "Input student last name:";
	std::cin >> student.mLastName;

	student.mFacultyNumber = new char[STRING_FIELD_MAX];
	std::cout << "Input student faculty number:";
	std::cin >> student.mFacultyNumber;

	std::cout << "Input student age:";
	std::cin >> student.mAge;

	student.mSpecialty = new char[STRING_FIELD_MAX];
	std::cout << "Input student specialty:";
	std::cin >> student.mSpecialty;

	student.mFaculty = new char[STRING_FIELD_MAX];
	std::cout << "Input student faculty:";
	std::cin >> student.mFaculty;
}

void clearDynamic(Student& student)
{
	delete[] student.mFirstName;
	delete[] student.mLastName;
	delete[] student.mFacultyNumber;
	delete[] student.mSpecialty;
	delete[] student.mFaculty;
}

void printStudents(Student* students, size_t numStudents)
{
	for (size_t i = 0; i < numStudents; i++)
	{
		std::cout << "\n----------------------------------\n";
		std::cout << "Student ID:" << students[i].mId << '\n';

		std::cout << "Student F Name:" << students[i].mFirstName << '\n';
		std::cout << "Student L Name:" << students[i].mLastName << '\n';
		std::cout << "Student F Number:" << students[i].mFacultyNumber << '\n';
		std::cout << "Student Age:" << students[i].mAge << '\n';
		std::cout << "Student Specialty:" << students[i].mSpecialty << '\n';
		std::cout << "Student Faculty:" << students[i].mFaculty << '\n';
		std::cout << "\n----------------------------------\n";
	}
}

void writeStudents(const char* filename, Student* students, size_t numStudents)
{
	std::ofstream out(filename, std::ios::binary);

	out.write((char*)&numStudents, sizeof(size_t));

	/*
	 * numStudents
	 * Student1
	 * Student2
	 *
	 *
	 */
	
	/*
		int mId;
		char* mFirstName;
		char* mLastName;
		char* mFacultyNumber;
		int mAge;
		char* mSpecialty;
		char* mFaculty;
	 */

	/* mId
	 * len(mFirstName) mFirstName
	 *
	 * 
	 */

	int bufferSize;
	
	for (size_t i = 0; i < numStudents; i++)
	{
		out.write((char*)&students[i].mId, sizeof(int));

		bufferSize = std::strlen(students[i].mFirstName);
		out.write((char*)&bufferSize, sizeof(int));
		out.write(students[i].mFirstName, sizeof(char) * bufferSize);

		bufferSize = std::strlen(students[i].mLastName);
		out.write((char*)&bufferSize, sizeof(int));
		out.write(students[i].mLastName, sizeof(char) * bufferSize);

		bufferSize = std::strlen(students[i].mFacultyNumber);
		out.write((char*)&bufferSize, sizeof(int));
		out.write(students[i].mFacultyNumber, sizeof(char) * bufferSize);

		out.write((char*)&students[i].mAge, sizeof(int));

		bufferSize = std::strlen(students[i].mSpecialty);
		out.write((char*)&bufferSize, sizeof(int));
		out.write(students[i].mSpecialty, sizeof(char) * bufferSize);

		bufferSize = std::strlen(students[i].mFaculty);
		out.write((char*)&bufferSize, sizeof(int));
		out.write(students[i].mFaculty, sizeof(char) * bufferSize);
	}
	
	out.close();
}

Student* readStudents(const char* filename, size_t& numReadStudents)
{
	std::ifstream in(filename, std::ios::binary);

	in.read((char*)&numReadStudents, sizeof(size_t));

	studentsCounter += numReadStudents;

	/*
	 * numStudents
	 * Student1
	 * Student2
	 *
	 *
	 */

	 /*
		 int mId;
		 char* mFirstName;
		 char* mLastName;
		 char* mFacultyNumber;
		 int mAge;
		 char* mSpecialty;
		 char* mFaculty;
	  */

	  /* mId
	   * len(mFirstName) mFirstName
	   *
	   *
	   */

	Student* students = new Student[numReadStudents];

	int bufferSize;
	
	for(size_t i = 0; i < numReadStudents; i++)
	{
		in.read((char*)&students[i].mId, sizeof(int));

		in.read((char*)&bufferSize, sizeof(int));
		students[i].mFirstName = new char[bufferSize + 1];
		in.read(students[i].mFirstName, sizeof(char) * bufferSize);
		students[i].mFirstName[bufferSize] = 0;

		in.read((char*)&bufferSize, sizeof(int));
		students[i].mLastName = new char[bufferSize + 1];
		in.read(students[i].mLastName, sizeof(char) * bufferSize);
		students[i].mLastName[bufferSize] = 0;

		in.read((char*)&bufferSize, sizeof(int));
		students[i].mFacultyNumber = new char[bufferSize + 1];
		in.read(students[i].mFacultyNumber, sizeof(char) * bufferSize);
		students[i].mFacultyNumber[bufferSize] = 0;

		in.read((char*)&students[i].mAge, sizeof(int));
		
		in.read((char*)&bufferSize, sizeof(int));
		students[i].mSpecialty = new char[bufferSize + 1];
		in.read(students[i].mSpecialty, sizeof(char) * bufferSize);
		students[i].mSpecialty[bufferSize] = 0;

		in.read((char*)&bufferSize, sizeof(int));
		students[i].mFaculty = new char[bufferSize + 1];
		in.read(students[i].mFaculty, sizeof(char) * bufferSize);
		students[i].mFaculty[bufferSize] = 0;
	}

	in.close();

	return students;
}