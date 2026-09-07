#include "../include/Person.h"

Person::Person(std::string id, std::string name, std::string email, std::string password)
    : ID(id), Name(name), Email(email), Password(password) {}

std::string Person::getID() const {
    return ID;
}

bool Person::checkPassword(std::string password) const {
    return this->Password == password;
}
