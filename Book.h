#ifndef BOOK_H
#define BOOK_H

#include <string>
#include "Date.h"

class Book{
    private:
        std::string title_;
        std::string author_;
        std::string genre_;
        Date publication_date_;
        std::string isbn_;
    
    public:
        Book(const std::string& title, const std::string& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn);
        std::string title() const;
        std::string author() const;
        std::string genre() const;
        std::string publicationDate() const;
        std::string isbn() const;
};

bool isBook(const std::string& title, const std::string& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn);

#endif