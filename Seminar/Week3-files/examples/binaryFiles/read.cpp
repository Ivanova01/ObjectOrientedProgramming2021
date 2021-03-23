#include <iostream>
#include <fstream>
#include "../BankAccount.cpp"

int main()
{
    // Simple example
    std::ifstream is("BankAccount.dat", std::ios::binary);
    if (!is.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    BankAccount ba;

    deserializeBankAccount(ba, is);
    is.close();
    printInfo(ba);

    // read the third bank account
    const int NUMBER_OF_BANK_ACCOUNTS = 8;
    const int WANTED_BANK_ACCOUNT = 3;
    BankAccount Bank[NUMBER_OF_BANK_ACCOUNTS];
    is.open("TheWholeBank.dat", std::ios::binary);
    if (!is.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    is.read((char *)Bank, NUMBER_OF_BANK_ACCOUNTS * sizeof(BankAccount));
    for (size_t i = 0; i < NUMBER_OF_BANK_ACCOUNTS; i++)
    {
        printInfo(Bank[i]);
    }
    BankAccount wantedBankAccount;
    is.clear();
    is.seekg(sizeof(BankAccount) * WANTED_BANK_ACCOUNT, std::ios::beg);
    deserializeBankAccount(wantedBankAccount, is);
    std::cout << "The " << WANTED_BANK_ACCOUNT + 1 << "th bank account is: \n";
    printInfo(wantedBankAccount);

    is.clear();
    is.seekg(0, std::ios::end);
    std::cout << "The size of the file is: " << is.tellg() << std::endl;

    is.clear();
    is.seekg(0, std::ios::beg);
    std::cout << "Read the whole file without knowing the size: " << std::endl;
    BankAccount temp;
    while (!is)
    {
        deserializeBankAccount(temp, is);
        printInfo(temp);
    }

    is.close();
    return 0;
}