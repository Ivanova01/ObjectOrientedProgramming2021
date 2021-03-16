#include "Hero.h"
#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>

#define STRING_MAX_SIZE 50

void Hero::heal(double healthToAdd) {
	double newHealth = mHealth + healthToAdd;
	mHealth = (newHealth > 100) ? 100 : newHealth;
}

void Hero::hurt(double healthToTake) {
	double newHealth = mHealth - healthToTake;
	mHealth = (newHealth < 0) ? 0 : newHealth;
}

double Hero::takeWeapon(char* weaponToBeTaken, double attack) {
	unsigned int biggerSize = std::max(strlen(mWeapon), strlen(weaponToBeTaken));
	delete[] mWeapon;
	mWeapon = new char[biggerSize + 1];

	strcpy(mWeapon, weaponToBeTaken);
	mAttack = attack;
	return mAttack;
}

void Hero::print() const {
	std::cout << "===== Hero information =====" << std::endl;
	std::cout << "Name: " << mName << std::endl;
	std::cout << "Weapon: " << mWeapon << std::endl;
	std::cout << "Attack: " << mAttack << std::endl;
	std::cout << "Health: " << mHealth << std::endl;
	std::cout << "============================" << std::endl;
}

double Hero::getHealth() const {
	return mHealth;
}

double Hero::getAttack() const {
	return mAttack;
}

void Hero::setHealth(double newHealth) {
	mHealth = newHealth;
}

void Hero::setAttack(double newAttack) {
	mAttack = newAttack;
}

Hero::Hero() {
	std::cout << "Entering default constr...";

	mName = new char[STRING_MAX_SIZE];
	std::cout << "Enter hero's name: ";
	std::cin.getline(mName, STRING_MAX_SIZE);

	mWeapon = new char[STRING_MAX_SIZE];
	std::cout << "Enter hero's weapon: ";
	std::cin.getline(mWeapon, STRING_MAX_SIZE);

	mHealth = 100;

	std::cout << "Enter weapon's strength: ";
	std::cin >> mAttack;
	std::cin.ignore();
}

Hero::~Hero() {
	delete[] mName;
	delete[] mWeapon;
}

Hero::Hero(const Hero& rhs) {
	mName = new char[STRING_MAX_SIZE];
	strcpy(mName, rhs.mName);

	mWeapon = new char[STRING_MAX_SIZE];
	strcpy(mWeapon, rhs.mWeapon);

	mHealth = rhs.mHealth;
	mAttack = rhs.mAttack;
}

Hero& Hero::operator=(const Hero& rhs)
{
	if (this != &rhs) {
		copyDynamic(mName, rhs.mName);
		copyDynamic(mWeapon, rhs.mWeapon);

		mAttack = rhs.mAttack;
		mHealth = rhs.mHealth;
	}
	return *this;
}

void Hero::copyDynamic(char* destination, const char* source)
{
	size_t bufferSize = strlen(source);
	delete[] destination;
	destination = new char[bufferSize + 1];
	strcpy(destination, source);
}