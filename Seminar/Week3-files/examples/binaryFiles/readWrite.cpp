#include <iostream>
#include <fstream>
#include "../BankAccount.cpp"

void reset(std::fstream &file)
{
    file.clear();
    file.seekg(0, std::ios::beg);
}

void showBinaryFileContent(std::fstream &file)
{
    if (!file)
    {
        return;
    }

    BankAccount current;
    while (file)
    {
        file.read(reinterpret_cast<char *>(&current), sizeof(BankAccount));

        // The number of characters extracted by the previous unformatted input function dispatched for this stream.
        if (file.gcount() == sizeof(BankAccount))
        {
            printInfo(current);
        }
    }

    reset(file);
}

long long countNumbersStoredInFile(std::fstream &file)
{
    if (!file)
    {
        return 0;
    }

    // set the get pointer at the end of the file
    file.seekg(0, std::ios::end);

    // this is how we can get the size of the file
    std::streamoff sizeOfFile = file.tellg();

    // check if the size of the file % size of int == 0
    long long count = sizeOfFile / sizeof(BankAccount);

    reset(file);

    return count;
}

void changeBankAccount(std::fstream &file, size_t index, BankAccount newValue)
{
    if (!file)
    {
        return;
    }

    long long count = countNumbersStoredInFile(file);

    if (index >= count)
    {
        std::cout << "Invalid position in the file!" << std::endl;
        return;
    }

    size_t changePosition = index * sizeof(BankAccount);

    file.seekp(changePosition, std::ios::beg);
    std::cout << "Put position: " << file.tellp() << std::endl;

    file.write(reinterpret_cast<const char *>(&newValue), sizeof(BankAccount));
}

int main()
{
    const char *fileName = "TheWholeBank.dat";

    std::fstream file(fileName, std::ios::in | std::ios::out | std::ios::binary);
    if (!file)
    {
        std::cout << "File cannot be opened!" << std::endl;
        return -1;
    }

    showBinaryFileContent(file);

    std::cout << "\n--- Modify the 3rd bank account" << std::endl;
    changeBankAccount(file, 2, BankAccount{500, "BARCGB22", "BG18RZBB91550123456789"});

    reset(file);
    showBinaryFileContent(file);

    file.close();
    return 0;
}