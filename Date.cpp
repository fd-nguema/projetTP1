#include "Date.h"

bool isDate(int day, int month, int year){
if (year < 0) return false;
if ((day < 1) || (day > 31)) return false;
if ((month < 1) || (month > 12)) return false;
if ((month == 2) && (day > 28)) return false;
if (((month == 4) || (month == 6) || (month == 9)
|| (month == 11)) && (day > 30)) return false;
return true;
}

int get_days_in_month(int month){
    if ((month < 1) || (month > 12)) throw std::invalid_argument("Invalid month : " + std::to_string(month));
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) return 31;
    if (month == 4 || month == 6 || month == 9 || month == 11) return 30;
    return 28;
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

bool Date::operator < (const Date& other) const{
    if (year_ < other.year()) return true;
    if ((year_ == other.year()) && (month_ < other.month())) return true;
    if ((year_ == other.year()) && (month_ == other.month()) && (day_ < other.day())) return true;
    return false;
}

Date Date::operator + (int days) const {
    int new_day = day_ + days;
    int new_month = month_;
    int new_year = year_;
    int days_in_month = get_days_in_month(new_month);
    while (new_day > days_in_month) {
    new_day -= days_in_month;
    ++new_month;
    if (new_month > 12){
        new_month = 1;
        ++new_year;
    }
    days_in_month = get_days_in_month(new_month);
    }
    return Date(new_day, new_month, new_year);
}


