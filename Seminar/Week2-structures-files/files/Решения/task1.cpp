#include <iostream>
#include <fstream>

int main()
{
    const int n = 2, m = 2;
    std::ofstream os("text.txt", std::ios::trunc); //trunc and out are default
    if (!os)
    {
        //ERROR
        std::cout << "Error opening file\n";
        return 1;
    }

    int number;
    //os << n << m; //вариант 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cin >> number;
            os << number << " ";
        }
        os << std::endl;
    }

    os.close();

    return 0;
}