#include <iostream>
#include <fstream>

int main() {
    std::ofstream mash("mash.txt"); //check
    mash << '1' << ' ' << '2' << '\n' << '1';
    

    mash.close();
    
    return 0;
}