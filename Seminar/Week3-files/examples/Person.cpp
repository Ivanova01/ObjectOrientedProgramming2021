#include <cstring>
#include "Person.h"

const int MAX_SIZE = 1024;

void copyDynamic(char *&dest, const char *source)
{
    int size = strlen(source) + 1;
    dest = new char[size];
    strcpy(dest, source);
}

void initializePerson(Person &p, char *name, int age)
{
    p.age = age;
    copyDynamic(p.name, name);
}

void deletePerson(Person &p)
{
    delete[] p.name;
}

void printInfo(const Person &p, std::ostream &os)
{
    os << p.name << " " << p.age << std::endl;
}

void readInfo(Person &p, std::istream &is)
{
    char buffer[MAX_SIZE];
    is.getline(buffer, MAX_SIZE, ' ');
    copyDynamic(p.name, buffer);
    is >> p.age;
}