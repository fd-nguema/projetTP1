#include "Library.h"

std::vector<Borrow> Library::borrows; 

Library::Library(std::vector<Book>& books, std::vector<Author>& authors, std::vector<Reader>& readers):books_(books), authors_(authors), readers_(readers) {
    bool problem = false;
    while (problem)
    {
        for (auto it = books.begin(); it != books.end(); it++){
        if (!isBook((*it).title(), (*it).author(), (*it).genre(), (*it).publicationDate(), (*it).isbn())){
            throw std::invalid_argument("Invalid book :\n" + (*it).title() + "\n" + (*it).author().id() + " " + (*it).author().firstname() + " " + (*it).author().lastname() + " " + (*it).author().birthday().date() + "\n" + (*it).genre() + "\n" + (*it).publicationDate().date() + "\n" + (*it).isbn());
            problem = true;
        }
        }
        for (auto it = authors.begin(); it != authors.end(); it++){
            if (!isAuthor((*it).id(), (*it).firstname(), (*it).lastname(), (*it).birthday())){
                throw std::invalid_argument("Invalid author :\n" + (*it).id() + "\n" + (*it).firstname() + "\n" + (*it).lastname() + "\n" + (*it).birthday().date());
                problem = true;
            }       
        }
         for (auto it = readers.begin(); it != readers.end(); it++){
            if (!isReader((*it).id(), (*it).firstname(), (*it).lastname(), (*it).birthday())){
                throw std::invalid_argument("Invalid reader :\n" + (*it).id() + "\n" + (*it).firstname() + "\n" + (*it).lastname() + "\n" + (*it).birthday().date());
                problem = true;
            }       
        }
    }
}

std::vector<Book>& Library::books() const{
    return books_;
}        

std::vector<Author>& Library::authors() const{
    return authors_;
}

std::vector<Reader>& Library::readers() const{
    return readers_;
}

void Library::addBook(const Book& new_book) const{
    books_.push_back(new_book);
}

void Library::addAuthor(const Author& new_author) const{
    authors_.push_back(new_author);
}

void Library::addReader(const Reader& new_reader) const{
    readers_.push_back(new_reader);
}

void Library::borrowing(const Date& borrow_date, Book& loaned_book, Reader& borrower) const{
    Borrow new_borrow(borrow_date, loaned_book, borrower);
    borrows.push_back(new_borrow);
}