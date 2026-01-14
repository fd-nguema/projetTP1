#ifndef LIBRARY_H
#define LIBRARY_H

#include "Date.h"
#include "Book.h"
#include "Author.h"
#include "Reader.h"
#include "Borrow.h"

#include <vector>

class Library{
    private:
        std::vector<Book>& books_;
        std::vector<Author>& authors_;
        std::vector<Reader>& readers_;
    public:
        static std::vector<Borrow> borrows;
        Library(std::vector<Book>& books, std::vector<Author>& authors, std::vector<Reader>& readers);
        std::vector<Book>& books() const;
        std::vector<Author>& authors() const;
        std::vector<Reader>& readers() const;
        void addBook(const Book& new_book) const;
        void addAuthor(const Author& new_author) const;
        void addReader(const Reader& new_reader) const;
        void borrowing(const Date& borrow_date, Book& loaned_book, Reader& borrower) const;
};

#endif