#ifndef AUTHOR_H
#define AUTHOR_H

#include <string>
#include "Date.h"

class Author{
    private:
        std::string id_;
        std::string firstname_;
        std::string lastname_;
        Date birthday_;
    public:
        Author(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday);
        std::string id() const;
        std::string firstname() const;
        std::string lastname() const;
        Date birthday() const;    
    };

bool isAuthor(const std::string& id, const std::string firstname, const std::string& lastname, const Date& birthday);
std::ostream& operator << (std::ostream& os, const Author& author);

#endif