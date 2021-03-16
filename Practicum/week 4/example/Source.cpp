#include <iostream>
#include "Hero.h"

#define STRING_MAX_SIZE 50

int main() {
	Hero hero;
	hero.print();

	Hero secondHero(hero);
	secondHero.print();

	std::cout << "Enter weapon to be taken: ";
	char* weaponName = new char[STRING_MAX_SIZE];
	std::cin.getline(weaponName, STRING_MAX_SIZE);

	std::cout << "Enter new weapon's attack: ";
	double newAttack;
	std::cin >> newAttack;

	secondHero.takeWeapon(weaponName, newAttack);
	hero.print();
	secondHero.print();

	Hero thirdHero = hero; //copy
	thirdHero = secondHero; //assignment operator

	thirdHero.print();

	return 0;
}