#include "Book.h"


bool isBook(const std::string& title, const std::string& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn){
    if (title == "" || author == "" || genre == "" 
        || !(isDate(publication_date.day(), publication_date.month(), publication_date.year())) || isbn == "") return false;
    return true;
}

Book::Book(const std::string& title, const std::string& author, const std::string& genre, 
            const Date& publication_date, const std::string& isbn) : title_(title), author_(author),
            genre_(genre), publication_date_(publication_date), isbn_(isbn) {
    if (!isBook(title, author, genre, publication_date, isbn)) 
        throw std::invalid_argument("Invalid Book :\n" + title + "\n" + author + "\n" + genre + "\n" +
            std::to_string(publication_date.day()) + "/" + std::to_string(publication_date.month()) + 
            "/" + std::to_string(publication_date.year()) + "\n" + isbn);
}

std::string Book::title() const{
    return title_;
}

std::string Book::author() const{
    return author_;
}

std::string Book::genre() const{
    return genre_;
}

std::string Book::publicationDate() const{
    return publication_date_.date();
}

std::string Book::isbn() const{
    return isbn_;
}
