#include "../include/Person.h"
#include <iostream>

Person::Person(std::string id, std::string name, std::string email, std::string password)
    : ID(id), Name(name), Email(email), Password(password) {}

std::string Person::getID() const {
    return ID;
}

void Person::getInfo() const {
    std::cout << "ID: " << ID << " | Name: " << Name << " | Email: " << Email << std::endl;
}

bool Person::checkPassword(std::string password) const {
    return Password == password;
}

std::string Person::getName() const {
    return this->Name;
}

std::string Person::getEmail() const {
    return Email;
}

std::string Person::getPassword() const {
    return Password;
}