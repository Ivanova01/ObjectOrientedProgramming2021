#include <iostream>
#include <fstream>
#include "../Person.cpp"

int main()
{
    Person ivan{nullptr, 0};
    std::ifstream is("Person.txt");
    if (!is.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }

    readInfo(ivan, is);
    is.close();
    printInfo(ivan, std::cout);
    deletePerson(ivan);
    return 0;
}