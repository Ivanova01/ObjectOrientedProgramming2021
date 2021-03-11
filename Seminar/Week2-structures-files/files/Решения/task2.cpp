#include <iostream>
#include <fstream>

int main() {
    const int n = 2, m = 2; // за по лесно приемаме, че знаем размерността на матрицата, друг вариант би бил да записваме m & n на първия ред от файл
    char fileName[32];
    std::cin.getline(fileName, 32);
    std::ifstream is(fileName);
    if (!is)
    {
        //ERROR
        std::cout << "Error opening file" << fileName << "\n";
        return 0;
    }
    
    //is >> m >> n; //вариант 2
    int matrix[m][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            //валидация за eof
            is >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << std::endl;
    }


    is.close();
    return 0;
}