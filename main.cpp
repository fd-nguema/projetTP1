#include <iostream>
#include "Book.h"
#include "Author.h"

int main() {
    try {
        Date publication_date1(8, 6, 1949);
        Date birthday_author1(25, 6, 1903);
        Author author1("gOrwell", "Orwell", "George", birthday_author1);
        Book book1("1984", author1, "philosophique", publication_date1, "978-2-07-046369-5");
        std::cout << "titre : " << book1.title() << std::endl <<
                    "auteur : " << book1.author() << std::endl <<
                    "genre : " << book1.genre() << std::endl << 
                    "date de publication : " << book1.publicationDate() << std::endl <<
                    "isbn : " << book1.isbn() << std::endl;
        std::cout << "id : " << author1.id() << std::endl <<
                    "nom : " << author1.firstname() << std::endl <<
                    "prénom : " << author1.lastname() << std::endl <<
                    "date de naissance : " << author1.birthday() << std::endl;
        Author author2("gOrwell", "", "", birthday_author1);
        Book book2("", author1, "philosophique", publication_date1, "978-2-07-046369-5");
        
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}

