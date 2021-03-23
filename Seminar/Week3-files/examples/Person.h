#ifndef PERSON_H
#define PERSON_H

struct Person
{
    char *name;
    int age;
};

void copyDynamic(char *&dest, const char *source);

void initializePerson(Person &p, char *name, int age);

void deletePerson(Person &p);
void printInfo(const Person &p, std::ostream &os);
void readInfo(Person &p, std::istream &os);
#endif