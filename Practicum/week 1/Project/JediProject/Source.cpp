#include <iostream>
#include "Jedi.h"

void initializeSaber(Jedi& jedi)
{
	jedi.lightSaber.color = new char[20];

	std::cout << "Input jedi's light saber color:";
	std::cin >> jedi.lightSaber.color;

	int choice;
	
	std::cout << "Input jedi's light saber type:\n";
	std::cout << "1 - Single bladed\n";
	std::cout << "2 - Double bladed\n";
	std::cout << "3 - Cross guard\n";
	std::cin >> choice;

	switch (choice)
	{
		case 1: jedi.lightSaber.type = SINGLE_BLADED; break;
		case 2: jedi.lightSaber.type = DOUBLE_BLADED; break;
		case 3: jedi.lightSaber.type = CROSS_GUARD; break;

		default:
			std::cerr << "Not supported type!\n";
	}
}

void initializeJedi(Jedi& jedi)
{
	jedi.name = new char[50];

	std::cout << "Input jedi name:";
	std::cin >> jedi.name;

	std::cout << "Input jedi age:";
	std::cin >> jedi.age;

	std::cout << "Input jedi strength:";
	std::cin >> jedi.strength;

	initializeSaber(jedi);
}

void printSaber(LightSaber lightSaber)
{
	std::cout << "Saber Color: " << lightSaber.color << '\n';
	std::cout << "Saber Type: " ;

	switch (lightSaber.type)
	{
		case SINGLE_BLADED: std::cout << "Single bladed\n"; break;
		case DOUBLE_BLADED: std::cout << "Double bladed\n"; break;
		case CROSS_GUARD: std::cout << "Cross guard\n"; break;

		default: 
		std::cout << "N/A\n";
	}
}

void printJedi(Jedi& jedi)
{
	std::cout << "Name: " << jedi.name << '\n';
	std::cout << "Age:" << jedi.age << '\n';
	std::cout << "Strength: " << jedi.strength << '\n';

	printSaber(jedi.lightSaber);
}

void killJedi(Jedi& jedi)
{
	delete[] jedi.name;
	delete[] jedi.lightSaber.color;
}

int main()
{
	Jedi jedi;
	initializeJedi(jedi);
	printJedi(jedi);

	killJedi(jedi);
	return 0;
}