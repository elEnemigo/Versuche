#include <iostream>

using namespace std;

int Variablen();
int Strukturen();
int Felder();

int main()
{
    std::cout << "Variablen.cpp" << std::endl;
    std::cout << "------------------------------" << std::endl;
    Variablen();

    std::cout << "\n\nStrukturen.cpp" << std::endl;
    std::cout << "------------------------------" << std::endl;
    Strukturen();

    std::cout << "\n\nFelder.cpp" << std::endl;
    std::cout << "------------------------------" << std::endl;
    Felder();

    return 0;
}
