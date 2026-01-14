#ifndef READER_H
#define READER_H

#include <vector>
#include "Date.h"
#include "Book.h"

class Reader{
    private:
        std::string id_;
        std::string firstname_;
        std::string lastname_;
        Date birthday_;
        std::vector<std::string>& history_;
    public:
        static std::vector<std::string> readers_id;
        Reader(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday, std::vector<std::string>& history);
        std::string id() const;
        std::string firstname() const;
        std::string lastname() const;
        Date birthday() const;
        std::vector<std::string>& history() const;
};

bool isReader(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday);
std::ostream& operator << (std::ostream& os, const Reader& reader);

#endif
