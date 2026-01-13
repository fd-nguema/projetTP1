#include "Book.h"

#include <iostream>

bool isBook(const std::string& title, const Author& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn){
    if (title == "" || (author.firstname() == "" && author.lastname() == "") || genre == "" 
        || !(isDate(publication_date.day(), publication_date.month(), publication_date.year())) || isbn == "") return false;
    return true;
}

Book::Book(const std::string& title, const Author& author, const std::string& genre, const Date& publication_date, const std::string& isbn, bool status, std::vector<Date>& borrow_history) : title_(title), author_(author), genre_(genre), publication_date_(publication_date), isbn_(isbn), status_(true), borrow_history_(borrow_history) {
    if (!(isBook(title, author, genre, publication_date, isbn))) 
        throw std::invalid_argument("Invalid Book :\n" + title + "\n" + author.firstname() + " " + author.lastname() + "\n" + genre + "\n" +
            std::to_string(publication_date.day()) + "/" + std::to_string(publication_date.month()) + 
            "/" + std::to_string(publication_date.year()) + "\n" + isbn);
}

std::string Book::title() const{
    return title_;
}

Author Book::author() const{
    return author_;
}

std::string Book::genre() const{
    return genre_;
}

Date Book::publicationDate() const{
    return publication_date_;
}

std::string Book::isbn() const{
    return isbn_;
}

bool Book::status() const{
    return status_;
}

std::vector<Date>& Book::borrowHistory() const{
    return borrow_history_;
}

void Book::available(){
    status_ = true;
}

void Book::unavailable(){
    status_ = false;
}