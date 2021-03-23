#ifndef BANK_ACCOUNT_H
#define BANK_ACCOUNT_H
#include <fstream>

const int IBAN_SIZE = 23;
const int BIC_SIZE = 9;

struct BankAccount
{
    int money;
    char BIC[BIC_SIZE];
    char IBAN[IBAN_SIZE];
};

void serializeBankAccount(const BankAccount &ba, std::ofstream &os);
void deserializeBankAccount(BankAccount &ba, std::ifstream &is);
void printInfo(const BankAccount &ba);

#endif // BANK_ACCOUNT_H