#ifndef DATE_H
#define DATE_H

#include <string>
#include <stdexcept>

class Date{
    public:
        Date(int day, int month, int year);
        int day() const;
        int month() const;
        int year() const;
        std::string date() const;
    private:
        int day_;
        int month_;
        int year_;
};

bool isDate(int day, int month, int year);

#endif