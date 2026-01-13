#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

#include "Date.h"
#include "Author.h"

class Book{
    private:
        std::string title_;
        Author author_;
        std::string genre_;
        Date publication_date_;
        std::string isbn_;
        bool status_;
        std::vector<Date>& borrow_history_;
    public:
        Book(const std::string& title, const Author& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn, bool status, std::vector<Date>& borrow_history);
        std::string title() const;
        Author author() const;
        std::string genre() const;
        Date publicationDate() const;
        std::string isbn() const;
        bool status() const;
        void available();
        void unavailable();
        std::vector<Date>& borrowHistory() const;
};

bool isBook(const std::string& title, const Author& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn);

#endif