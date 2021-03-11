#include <iostream>

struct simpleStruct
{
    char symbol; //can't initialize variables here //char symbol = 'a';
    int number;
    float floatingPointNumber;
};

int main()
{
    const int EXAMPLE_INT = 25;
    const char EXAMPLE_CHAR = 'a';
    const float EXAMPLE_FLOAT = 15.34f;
    simpleStruct struct1;          //declare struct1
    struct1.symbol = EXAMPLE_CHAR; //access variables of structs via .
    std::cout << "Struct 1's symbol: " << struct1.symbol << std::endl;

    simpleStruct struct2 = {EXAMPLE_CHAR, EXAMPLE_INT, EXAMPLE_FLOAT}; // initialize during declaration
    std::cout << "Struct 2's symbol: " << struct2.symbol << std::endl;
    std::cout << "Struct 2's number: " << struct2.number << std::endl;
    std::cout << "Struct 2's floatingPointNumber: " << struct2.floatingPointNumber << std::endl;

    simpleStruct array[EXAMPLE_INT]; //array of structs
    array[0].floatingPointNumber = EXAMPLE_FLOAT;
    std::cout << "Array[0]'s floatingPointNumber: " << array[0].floatingPointNumber << std::endl;

    simpleStruct *pointer = &struct1;
    std::cout << "Struct 1's symbol: " << (*pointer).symbol << std::endl; //same as
    std::cout << "Struct 1's symbol: " << pointer->symbol << std::endl;   // we can use -> instead of (*pointer).

    return 0;
}