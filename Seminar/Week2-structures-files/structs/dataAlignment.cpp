#include <iostream>

// Alignment requirements
// (typical 32 bit machine)

// char         1 byte
// short int    2 bytes
// int          4 bytes
// double       8 bytes

// structure A
struct structA
{
    char c;
    short int s;
};

// structure B
struct structB
{
    short int s;
    char c;
    int i;
};

// structure C
struct structC
{
    char c;
    double d;
    int s;
};

// structure D
struct structD
{
    double d;
    int s;
    char c;
};

int main()
{
    std::cout << "Size of structA " << sizeof(structA) << std::endl; //4
    std::cout << "Size of structB " << sizeof(structB) << std::endl; //8
    std::cout << "Size of structC " << sizeof(structC) << std::endl; //24
    std::cout << "Size of structD " << sizeof(structD) << std::endl; //16

    return 0;
}