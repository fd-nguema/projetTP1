#include <iostream>
#include "Reader.h"

int main() {
    try {
        Date my_birthday(10, 10, 2007);
        std::vector<std::string> emptyHistory;
        Reader me("fNguema", "Nguema", "François", my_birthday, emptyHistory);
        std::cout << "id : " << me.id() << std::endl <<
                    "nom : " << me.firstname() << std::endl <<
                    "prénom : " << me.lastname() << std::endl <<
                    "date de naissance : " << me.birthday() << std::endl;
        std::cout << "historique : " << std::endl;
        me.history();
        Reader other("fNguema", "Nguema", "François", my_birthday, emptyHistory);
        std::cout << other.id() << std::endl;
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}

