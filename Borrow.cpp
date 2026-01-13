#include "Borrow.h"

bool isAvailable(const Date& borrow_date, const Book& loaned_book){
    if (loaned_book.borrowHistory().size() == 0 && loaned_book.status() == true) return true;
    else if ((!loaned_book.borrowHistory().empty()) && ((loaned_book.borrowHistory().back() + 14) < borrow_date)) return true;//on considère que le livre est rendu au plus tard deux semaines plus tard
    return false;
}

Borrow::Borrow(const Date& borrow_date, Book& loaned_book, Reader& borrower):borrow_date_(borrow_date), loaned_book_(loaned_book), borrower_(borrower){
    if (!(isDate(borrow_date.day(), borrow_date.month(), borrow_date.year())) || !(isBook(loaned_book.title(), loaned_book.author(), loaned_book.genre(), loaned_book.publicationDate(), loaned_book.isbn())) || !(isReader(borrower.id(), borrower.firstname(), borrower.lastname(), borrower.birthday())) || !(isAvailable(borrow_date, loaned_book)))
        throw std::invalid_argument("This borrow can't be done :\n" + borrow_date.date() + "\n" + loaned_book.isbn() + "\n" + borrower.id() + "\n");
    
    loaned_book.available();
    loaned_book.unavailable();
    loaned_book.borrowHistory().push_back(borrow_date);
    borrower.history().push_back(loaned_book.isbn());
}


Date Borrow::borrowDate() const{
    return borrow_date_;
}

std::string Borrow::bookIsbn() const{
    return loaned_book_.isbn();
}

std::string Borrow::borrowerId() const{
    return borrower_.id();
}
