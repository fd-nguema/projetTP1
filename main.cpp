#include <iostream>
#include "Library.h"

int main() {
    try {
        std::vector<std::string> isbnHistory1 = {};
        std::vector<std::string> isbnHistory2 = {};
        
        std::vector<Date> borrowHistory1 = {};
        std::vector<Date> borrowHistory2 = {};
        std::vector<Date> borrowHistory3 = {};
        std::vector<Date> borrowHistory4 = {};
        std::vector<Date> borrowHistory5 = {};
        std::vector<Date> borrowHistory6 = {};
        std::vector<Date> borrowHistory7 = {};
        std::vector<Date> borrowHistory8 = {};
        std::vector<Date> borrowHistory9 = {};
        std::vector<Date> borrowHistory10 = {};

        std::vector<Book> books = {};
        std::vector<Author> authors = {};
        std::vector<Reader> readers = {};

        Library the_library(books, authors, readers);

        //Auteurs
        Date birthday_author1(25, 6, 1903);
        Author author1("gOrwell", "Orwell", "George", birthday_author1);
        the_library.addAuthor(author1);

        Date birthday_author2(26, 2, 1802);
        Author author2("vHugo", "Hugo", "Victor", birthday_author2);
        the_library.addAuthor(author2);

        Date birthday_author3(15, 1, 1622);
        Author author3("molière", "Poquelin", "Jean-Baptiste", birthday_author3);
        the_library.addAuthor(author3);

        //Livres
        bool book_status = true;

        Date publication_date1(8, 6, 1949);
        Book book1("1984", author1, "philosophique", publication_date1, "978-2-07-046369-5", book_status, borrowHistory1);
        the_library.addBook(book1);

        Date publication_date2(17, 8, 1945);
        Book book2("La Ferme des animaux", author1, "fable", publication_date2, "978-2-07-036821-1", book_status, borrowHistory2);
        the_library.addBook(book2);

        Date publication_date3(25, 4, 1938);
        Book book3("Hommage à la Catalogne", author1, "biographique", publication_date3, "978-2-07-037166-2", book_status, borrowHistory3);
        the_library.addBook(book3);

        Date publication_date4(31, 3, 1862);
        Book book4("Les Misérables", author2, "épique", publication_date4, "978-2-25-300422-6", book_status, borrowHistory4);
        the_library.addBook(book4);

        Date publication_date5(16, 3, 1831);
        Book book5("Notre-Dame de Paris", author2, "romantique", publication_date5, "978-2-25-300632-9", book_status, borrowHistory5);
        the_library.addBook(book5);

        Date publication_date6(1, 1, 1856);
        Book book6("Les Contemplations", author2, "poétique", publication_date6, "978-2-07-040918-1", book_status, borrowHistory6);
        the_library.addBook(book6);

        Date publication_date7(1, 2, 1829);
        Book book7("Le Dernier Jour d'un Condamné", author2, "romantique", publication_date7, "978-2-07-040828-3", book_status, borrowHistory7);
        the_library.addBook(book7);

        Date publication_date8(5, 2, 1669);
        Book book8("Tartuffe", author3, "comédie", publication_date8, "978-2-07-040322-6", book_status, borrowHistory8);
        the_library.addBook(book8);

        Date publication_date9(4, 6, 1666);
        Book book9("Le Misanthrope", author3, "comédie", publication_date9, "978-2-07-040325-7", book_status, borrowHistory9);
        the_library.addBook(book9);

        Date publication_date10(9, 9, 1668);
        Book book10("L'Avare", author3, "comédie", publication_date10, "978-2-07-040334-9", book_status, borrowHistory10);
        the_library.addBook(book10);

        //Lecteurs
        Date reader1_birthday(10, 10, 2007);
        Reader reader1("fNguema", "Nguema", "François", reader1_birthday, isbnHistory1);
        the_library.addReader(reader1);

        Date reader2_birthday(11, 12, 2006);
        Reader reader2("bNgoumdjeu", "Ngoumdjeu", "Bill", reader2_birthday, isbnHistory2);
        the_library.addReader(reader2);

        std::cout << "Auteurs : " << std::endl;
        for (auto it = the_library.authors().begin(); it != the_library.authors().end(); it++){
            std::cout << *it << std::endl;
        }

        std::cout << "Livres : " << std::endl;
        for (auto it = the_library.books().begin(); it != the_library.books().end(); it++){
            std::cout << *it << std::endl;
        }

        std::cout << "Lecteurs : " << std::endl;
        for (auto it = the_library.readers().begin(); it != the_library.readers().end(); it++){
            std::cout << *it << std::endl;
        }

        Date borrow_date1(10, 11, 2025);
        the_library.borrowing(borrow_date1, book1, reader1);
        the_library.borrowing(borrow_date1, book5, reader1);
        the_library.borrowing(borrow_date1, book8, reader1);

        Date borrow_date2(20, 11, 2025);
        the_library.borrowing(borrow_date2, book1, reader2);
        the_library.borrowing(borrow_date2, book10, reader2);
        the_library.borrowing(borrow_date2, book5, reader2);
    }

    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}
