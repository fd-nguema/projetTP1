#include <iostream>
#include "Borrow.h"

int main() {
    try {
        std::vector<std::string> isbnHistory = {};
        std::vector<std::string> otherIsbnHistory = {};
        std::vector<Date> borrowHistory = {};

        Date borrow_date(10, 11, 2025);

        Date publication_date1(8, 6, 1949);
        Date birthday_author1(25, 6, 1903);
        Author author1("gOrwell", "Orwell", "George", birthday_author1);
        bool book1_status = true;
        Book book1("1984", author1, "philosophique", publication_date1, "978-2-07-046369-5", book1_status, borrowHistory);

        Date my_birthday(10, 10, 2007);
        Reader me("fNguema", "Nguema", "François", my_birthday, isbnHistory);
        
        Borrow my_borrow(borrow_date, book1, me);

        std::cout << "borrow date : " << borrow_date.date() << std::endl;
        std::cout << "loaned book : " << book1.title() << "," << book1.isbn() << std::endl;
        std::cout << "borrower : " << me.id() << std::endl;
        std::cout << "borrow History of book1 : " << std::endl;
        for (auto it = book1.borrowHistory().begin(); it != book1.borrowHistory().end(); it++){
            std::cout << (*it).date() << std::endl;
        }

        Date other_borrow_date(28, 11, 2025);
        Reader other("fNguema", "Nguema", "François", my_birthday, otherIsbnHistory);
        Borrow other_borrow(other_borrow_date, book1, other);

        std::cout << "borrow date : " << other_borrow.borrowDate().date() << std::endl;
        std::cout << "loaned book : " << other_borrow.bookIsbn() << std::endl;
        std::cout << "borrower : " << other_borrow.borrowerId() << std::endl;
        std::cout << "borrow History of book1 : " << std::endl;
        for (auto it = book1.borrowHistory().begin(); it != book1.borrowHistory().end(); it++){
            std::cout << (*it).date() << std::endl;
        }
    } 
    catch (const std::invalid_argument& e) {
        std::cerr << "Erreur : " << e.what() << std::endl;
    }
    return 0;
}

