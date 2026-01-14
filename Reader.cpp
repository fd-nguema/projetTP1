#include "Reader.h"

#include <iostream>

std::vector<std::string> Reader::readers_id;

bool isReader(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday){
    if (id == "" || (firstname == "" && lastname == "") || !(isDate(birthday.day(), birthday.month(), birthday.year()))) return false;
    return true;
}

std::ostream& operator << (std::ostream& os, const Reader& reader){
    os << "id : " + reader.id() + " | " + "firstname : " + reader.firstname() + " | " + "lastname : " + reader.lastname() + " | " + "birthday : " + reader.birthday().date() + "\n";
    return os;
}

Reader::Reader(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday, std::vector<std::string>& history) :
    id_(id), firstname_(firstname), lastname_(lastname), birthday_(birthday), history_(history)
{
    if (!(isReader(id, firstname, lastname, birthday)))
        throw std::invalid_argument("The reader can't be defined like this :\n" + id + "\n" + firstname + "\n" + 
        lastname + "\n" + birthday.date() + "\n");
    
    static int counter = 0;

    for (auto it = Reader::readers_id.begin(); it != Reader::readers_id.end(); it++){
        if (*it == id){
            counter++;
            id_ = id + std::to_string(counter++);
        }
    }
    Reader::readers_id.push_back(id);      
        
}

std::string Reader::id() const{
    return id_;
}

std::string Reader::firstname() const{
    return firstname_;
}

std::string Reader::lastname() const{
    return lastname_;
}

Date Reader::birthday() const{
    return birthday_;
}

std::vector<std::string>& Reader::history() const{
    return history_;
}
