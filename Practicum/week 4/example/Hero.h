#pragma once

class Hero {
private:
	double mHealth;
	double mAttack;

	void copyDynamic(char* destination, const char* source);
public:
	char* mWeapon;
	char* mName;

	void heal(double healthToAdd);
	void hurt(double healthToTake);
	double takeWeapon(char* newWeapon, double newWeaponAttack);
	void print() const;

	double getHealth() const;
	double getAttack() const;

	void setHealth(double newHealth);
	void setAttack(double newAttack);

	Hero(); 
	// Hero(double, double, char*, char*); //constructor with parameters
	~Hero(); 
	Hero(const Hero& rhs); 
	Hero& operator=(const Hero& rhs);
};
