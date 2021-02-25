#include <iostream>
#include <fstream>

int main() {
    std::ifstream mash("mash.txt"); //check

    char ch;
    int words = 0;
    int lines = 1;
    int symbols = 0;
    while (mash)
    {
        mash.get(ch); //mash >> ch;
        if (!mash.fail()) // За случая когато трябва да прочетем 1 символ и сме на края на файла (тогава четем eof)
        {    
            symbols++;
            if (ch == '\n')
            {
                lines++;
            }
            if (ch == '\t' || ch == ' ' || ch == '\n')
            {
                words++;
            }
        }
    }

    if (ch != '\t' || ch != ' ' || ch != '\n') { //изкуствана логина за последната дума, ако файлът не завършва с нов ред брои 1 дума по-малко
        
        words++;
    }
    
    std::cout << "Words " << words << " lines " << lines << " symbols " << symbols << std::endl;

    mash.close();
    
    return 0;
}