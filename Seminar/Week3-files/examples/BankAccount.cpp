#include "BankAccount.h"

void serializeBankAccount(const BankAccount &ba, std::ofstream &os)
{
    os.write((char *)&ba, sizeof(BankAccount));
}

void deserializeBankAccount(BankAccount &ba, std::ifstream &is)
{
    is.read((char *)&ba, sizeof(BankAccount));
}

void printInfo(const BankAccount &ba)
{
    std::cout << ba.money << " leva, " << ba.BIC << " is its BIC and " << ba.IBAN << " is its IBAN!" << std::endl;
}