// principles of OOP
// abstraction, capsolation, inheritance, polymorphism

#include <iostream>
#include <cstring>

// overloading vs overriding

// 1) overloading - same return type, same name, but different parameters
void print(char *string)
{
	std::cout << string << std::endl;
}

void print(std::string string)
{
	std::cout << string << std::endl;
}

// setters & getters

class BankAccount
{
public:
	// default constructor
	BankAccount()
	{
		std::cout << "Default constructor triggered...\n";
		this->amount = 0;
		this->owner = nullptr;
	}

	BankAccount(int amount, char *owner)
	{
		std::cout << "Constructor triggered...\n";
		this->amount = amount;
		int size = strlen(owner) + 1;
		this->owner = new char[size];
		strcpy_s(this->owner, size, owner);
	}

	// copy constructor
	BankAccount(const BankAccount &other)
	{
		std::cout << "Copy constructor triggered...\n";
		// taking care of amount
		this->amount = other.amount;
		// taking care of owner
		int size = strlen(other.owner) + 1;
		this->owner = new char[size];
		strcpy_s(this->owner, size, other.owner);
	}

	// operator overloading
	// rhs - right hand side
	BankAccount &operator=(const BankAccount &rhs)
	{
		// this - address of the current object - 0xFF04521
		std::cout << "Operator = triggered...\n";
		if (this != &rhs)
		{
			std::cout << "Operator = copying...\n";
			this->amount = rhs.amount;
			delete[] owner;
			int size = strlen(rhs.owner) + 1;
			this->owner = new char[size];
			strcpy_s(this->owner, size, rhs.owner);
		}
		return *this;
	}

	// comparator
	// {
	//
	// < 0 if first < second
	// 0 if first == second
	// > 0 if first > second
	// }
	bool operator==(const BankAccount &rhs)
	{
		return strcmp(this->owner, rhs.owner) == 0;
	}

	~BankAccount()
	{
		if (this->owner)
		{
			std::cout << this->owner << " 's account is being deleted...\n";
		}
		std::cout << "Destructor triggered...\n";
		delete[] owner;
	}

	// methods
	// getter
	int getAmount()
	{
		return this->amount;
	}

	// setter
	void setAmount(int amount)
	{
		if (amount < 0)
		{
			return;
		}
		this->amount = amount;
	}

private:
	// fields
	// member variable - mAmount
	int amount;
	char *owner;
};

class CreditCard
{
};

int main()
{
	// access modifiers - public, private, protected
	// the rule of three - the big three - copy constructor, operator =, destructor
	// operator overloading
	char ivan[] = "Ivan";
	char magi[] = "Magi";
	BankAccount ivansAccount(10, ivan);
	BankAccount magisAccount(20, magi);
	{
		BankAccount ivansNewAccount = ivansAccount;
	}
	BankAccount *testAccount = new BankAccount(magisAccount);
	delete testAccount;
	ivansAccount.setAmount(-100);
	std::cout << "ivan has " << ivansAccount.getAmount() << std::endl;
	std::cout << "magi has " << magisAccount.getAmount() << std::endl;

	BankAccount peshosBankAccount = ivansAccount; // will trigger copy constructor
	BankAccount penkasBankAccount(magisAccount);  // will trigger copy constructor

	BankAccount goshosAccount;
	std::cout << "gosho has " << goshosAccount.getAmount() << std::endl;
	// do sth with gosho...
	// goshosAccount.operator=(ivansAccount); same as below
	goshosAccount = ivansAccount;
	goshosAccount = goshosAccount;
	// goshosAccount.operator=(ivansAccount.operator=(magisAccount));
	goshosAccount = ivansAccount = magisAccount;
	peshosBankAccount = ivansAccount;
	// +, -, *, [], =, ==, >>, << - operators
	if (ivansAccount == magisAccount)
	{
		std::cout << "Wait a second?...\n";
	}

	return 0;
}
