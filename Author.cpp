#include "Author.h"

Author::Author(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday) :
    id_(id), firstname_(firstname), lastname_(lastname), birthday_(birthday) {
    if ((id == "" || (firstname == "" && lastname == "") || !(isDate(birthday.day(), birthday.month(), birthday.year()))))
    throw std::invalid_argument("Author can't be defined like this :\n" + id + "\n" + firstname + "\n" + 
        lastname + "\n" + std::to_string(birthday.day()) + "/" + std::to_string(birthday.month()) + "/" +
        std::to_string(birthday.year()));
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

std::string Author::birthday() const{
    return birthday_.date();
}


