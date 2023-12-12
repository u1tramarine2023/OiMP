#include <iostream>
#include <fstream>
#include "headers.h"

int main() {
    std::ifstream file("text.txt");

    if (!file)
    {
        std::cout << "Error file!\n";
    }

    Tax taxes;
    taxes.ReadAll(file);
    file.close();
    std::cout << "...................Incomes.......................\n";
    taxes.PrintAll(std::cout);

    taxes.TotalTax();
    std::cout << ".......Incomes sorted by amount of tax.........\n";
    taxes.sortAmount();
    taxes.PrintAll(std::cout);
}
