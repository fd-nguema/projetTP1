#include "Date.h"

bool isDate(int day, int month, int year) {
if (year < 0) return false;
if ((day < 1) || (day > 31)) return false;
if ((month < 1) || (month > 12)) return false;
if ((month == 2) && (day > 28)) return false;
if (((month == 4) || (month == 6) || (month == 9)
|| (month == 11)) && (day > 30)) return false;
return true;
}

Date::Date(int day, int month, int year): day_(day), month_(month), year_(year){
    if (!isDate(day, month, year)) {
        throw std::invalid_argument("Invalid date: " + std::to_string(day) + "/"
    + std::to_string(month) + "/" + std::to_string(year));
}
}

int Date::day() const{
    return day_;
}

int Date::month() const{
    return month_;
}

int Date::year() const{
    return year_;
}

std::string Date::date() const{
    return std::to_string(day_) + "/" + std::to_string(month_) + "/" + std::to_string(year_);
}
