#include <iostream>
#include <fstream>

bool isOdd(int number) {
    return number % 2 == 1;
}

int main() {
    std::ofstream odds("oddNumbers.txt"); //check
    std::ofstream evens("evenNumbers.txt"); //check

    int low, high;
    std::cin >> low >> high;
    //check

    for (int i = low; i < high; i++)
    {
        if (isOdd(i))
        {
            odds << i << " ";
        } else
        {
            evens << i << " ";
        }
    }
    odds.close();
    evens.close();
    
    return 0;
}