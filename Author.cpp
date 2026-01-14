#include "Author.h"

bool isAuthor(const std::string& id, const std::string firstname, const std::string& lastname, const Date& birthday){
    if (id == "" || (firstname == "" && lastname == "") || !isDate(birthday.day(), birthday.month(), birthday.year())) return false;
    return true;
}

std::ostream& operator << (std::ostream& os, const Author& author) {
    os << "id : " + author.id() + " | " + "firstname : " + author.firstname() + " | " + "lastname : " + author.lastname() + " | " + "birthday : " + author.birthday().date() + "\n";
    return os;
}

Author::Author(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday) :
    id_(id), firstname_(firstname), lastname_(lastname), birthday_(birthday) {
    if (!isAuthor(id, firstname, lastname, birthday))
        throw std::invalid_argument("Author can't be defined like this :\n" + id + "\n" + firstname + "\n" + lastname + "\n" + birthday.date());
}

std::string Author::id() const{
    return id_;
}

std::string Author::firstname() const{
    return firstname_;
}

std::string Author::lastname() const{
    return lastname_;
}

Date Author::birthday() const{
    return birthday_;
}


