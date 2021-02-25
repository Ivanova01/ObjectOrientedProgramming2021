#include <iostream>
#include <cstring>

const int MAX_LENGHT = 128;
// we can also use  #define MAX_LENGHT 128

/*
we use struct to represent data with elements that are different type
*/

enum Manufacturer
{
    AUDI,
    HONDA,
    BMW
};

struct Engine
{
    char *displacement;
    double horsePower;
};

struct Car
{
    //char pointer represents the model component and will be dynamically created
    char *number;
    char *model;
    int year;
    Manufacturer manufacturer;
    Engine *engine;
};

void initializeEngine(Car &c)
{
    char input[MAX_LENGHT];
    std::cout << "Input " << c.number << "'s displacement:";
    std::cin.ignore();
    std::cin.getline(input, MAX_LENGHT);
    c.engine->displacement = new char[strlen(input)];
    // in windows we use strcpy_s
    strcpy(c.engine->displacement, input);

    std::cout << "Input " << c.number << "'s horse power:";
    std::cin >> c.engine->horsePower;
}

//initialize jedi's components
void initializeCar(Car &c)
{
    char input[MAX_LENGHT];
    std::cout << "Input car's serial number:";
    std::cin.getline(input, MAX_LENGHT);

    c.number = new char[strlen(input)];
    strcpy(c.number, input);

    int tmp;
    std::cout << "Input " << c.number << "'s manufacturer (audi - 0, honda - 1, BMW - 2):";
    std::cin >> tmp;
    c.manufacturer = (Manufacturer)tmp;

    std::cout << "Input car's model:";
    std::cin.ignore();
    std::cin.getline(input, MAX_LENGHT);

    c.model = new char[strlen(input)];
    strcpy(c.model, input);

    std::cout << "Input " << c.number << "'s year:";
    std::cin >> c.year;

    c.engine = new Engine;
    initializeEngine(c);
}

void printEngine(Engine *engine)
{
    std::cout << "Engine's displacemnt: " << engine->displacement << std::endl;
    std::cout << "Horse power: " << engine->horsePower << std::endl;
}

void printCar(Car &c)
{
    std::cout << "-----------Car-----------" << std::endl;
    std::cout << "Serial number: " << c.number << std::endl;
    std::cout << "Year: " << c.year << std::endl;
    switch (c.manufacturer)
    {
    case 0:
        std::cout << "Audi" << std::endl;
        break;
    case 1:
        std::cout << "Honda" << std::endl;
        break;
    case 2:
        std::cout << "BMW" << std::endl;
    }
    std::cout << "Model: " << c.model << std::endl;
    printEngine(c.engine);
}

//function to delete the dynamic memory
void destroyCar(Car &c)
{
    delete[] c.number;
    delete[] c.model;
    delete c.engine;
}

int main()
{
    Car myCar;

    initializeCar(myCar);
    printCar(myCar);

    //clear the dynamic memory!!!
    destroyCar(myCar);
    return 0;
}