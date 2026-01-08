#include "Reader.h"

#include <iostream>

std::vector<std::string> Reader::readers_id;

Reader::Reader(const std::string& id, const std::string& firstname, const std::string& lastname, const Date& birthday, std::vector<std::string>& history) :
    id_(id), firstname_(firstname), lastname_(lastname), birthday_(birthday), history_{}
    {
    if (id == "" || (firstname == "" && lastname == "") || !(isDate(birthday.day(), birthday.month(), birthday.year())))
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

std::string Reader::birthday() const{
    return birthday_.date();
}

void Reader::history(){
    for (auto it = history_.begin(); it != history_.end(); it++)
        std::cout << *it << std::endl;
}
