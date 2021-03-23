#include <iostream>
#include <fstream>
#include "../Person.cpp"

int main()
{
    Person ivan{nullptr, 0};
    initializePerson(ivan, "Ivan", 24);
    printInfo(ivan, std::cout);
    std::ofstream os("Person.txt");
    if (!os.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    printInfo(ivan, os);
    os.close();
    deletePerson(ivan);
    return 0;
}