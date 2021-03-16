#include <iostream>
#include <fstream>

int main() {
    std::ifstream mash("mash.txt"); //check

    char ch;
    std::cin >> ch;
    int row = 1, col = 0;
    char curr;
    while (mash.get(curr))
    {
        col++;

        if (curr == ch)
        {
            std::cout << "Row, col: " << row << " " << col << std::endl;
        }

        if (curr == '\n')
        {
            row++;
            col = 0;
        }
    }

    mash.close();
    
    return 0;
}