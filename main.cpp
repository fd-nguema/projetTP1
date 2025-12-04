#include <iostream>
#include "Date.h"

int main() {
    try {
        Date date1(4, 12, 2025);
        std::cout << "Date1 : " << date1.date() << std::endl;
        Date date2(32, 23, 1000);
        std::cout << "Date2 : " << date2.date() << std::endl;
        Date date3(15, 15, 2025);
        std::cout << "Date3 : " << date3.date() << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}

