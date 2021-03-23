#include <iostream>
#include <fstream>
#include "../BankAccount.cpp"

bool transferBankAccountsFromTextToBinary(const char *inputFileName, const char *outputFileName)
{
    std::ifstream inputFile(inputFileName, std::ios::in);

    if (!inputFile.is_open())
    {
        std::cout << "Input file cannot be opened!" << std::endl;
        return false;
    }

    std::ofstream outputFile(outputFileName, std::ios::out | std::ios::binary | std::ios::trunc);
    if (!outputFile)
    {
        std::cout << "Output file cannot be opened!" << std::endl;
        return false;
    }

    BankAccount current;

    while (inputFile)
    {
        inputFile >> current.money;
        inputFile.ignore();
        inputFile.getline(current.BIC, BIC_SIZE);
        inputFile.getline(current.IBAN, IBAN_SIZE);

        if (inputFile)
        {
            std::cout << "current: " << std::endl;
            printInfo(current);

            outputFile.write(reinterpret_cast<const char *>(&current), sizeof(current));
        }
        else
        {
            if (inputFile.eof())
            {
                std::cout << "End of file reached!" << std::endl;
            }
            else
            {
                inputFile.clear();
            }
        }
    }

    inputFile.close();
    outputFile.close();

    return true;
}

int main()
{
    std::ofstream os("BankAccount.dat", std::ios::binary);
    if (!os.is_open())
    {
        std::cerr << "Error opening file!" << std::endl;
        return -1;
    }
    BankAccount ba{500, "BARCGB22", "BG18RZBB91550123456789"};

    serializeBankAccount(ba, os);
    os.close();

    // write a whole bunch of bank accounts
    // const int NUMBER_OF_BANK_ACCOUNTS = 8;
    // BankAccount aWholeBank[NUMBER_OF_BANK_ACCOUNTS];
    // for (size_t i = 0; i < NUMBER_OF_BANK_ACCOUNTS; i++)
    // {
    //     std::cin >> aWholeBank[i].money;
    //     std::cin.ignore();
    //     std::cin.getline(aWholeBank[i].BIC, BIC_SIZE);
    //     std::cin.getline(aWholeBank[i].IBAN, IBAN_SIZE);
    // }
    // os.open("TheWholeBank.dat", std::ios::binary | std::ios::trunc);
    // if (!os.is_open())
    // {
    //     std::cerr << "Error opening file!" << std::endl;
    //     return -1;
    // }
    // os.write((char *)aWholeBank, NUMBER_OF_BANK_ACCOUNTS * sizeof(BankAccount));
    // os.close();

    if (transferBankAccountsFromTextToBinary("input", "TheWholeBank.dat"))
    {
        std::cout << "Successfully moved input from text to binary file\n";
    }
    else
    {
        std::cout << "Moving failed!\n";
    }
    return 0;
}