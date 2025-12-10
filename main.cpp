#include <iostream>
#include "Book.h"

int main() {
    try {
        Date publication_date1(8, 6, 1949);
        Book book1("1984", "George Orwell", "philosophique", publication_date1, "978-2-07-046369-5");
        std::cout << "titre : " << book1.title() << std::endl <<
                    "auteur : " << book1.author() << std::endl <<
                    "genre : " << book1.genre() << std::endl << 
                    "date de publication : " << book1.publicationDate() << std::endl <<
                    "isbn : " << book1.isbn() << std::endl;
        Book book2("", "George Orwell", "philosophique", publication_date1, "978-2-07-046369-5");
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}

