#ifndef BORROW_H
#define BORROW_H

#include "Date.h"
#include "Book.h"
#include "Author.h"
#include "Reader.h"

class Borrow{
    private:
        Date borrow_date_;
        Book& loaned_book_;
        Reader& borrower_;
    public:
        Borrow(const Date& borrow_date, Book& loaned_book, Reader& borrower);
        Date borrowDate() const;
        std::string bookIsbn() const;
        std::string borrowerId() const;
};

bool isAvailable(const Date& borrow_date, const Book& loaned_book);

#endif
