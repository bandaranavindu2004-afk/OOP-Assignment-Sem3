#include "../include/Person.h"

// Constructor implementation using an initialization list
Person::Person(std::string id, std::string name, std::string email, std::string password)
    : ID(id), Name(name), Email(email), Password(password) {}

// Return the user's ID
std::string Person::getID() const {
    return ID;
}

// Check if the provided password matches the stored password
bool Person::checkPassword(std::string password) const {
    return this->Password == password;
}

// Note: displayDashboard() is pure virtual in the header (= 0), 
// so we do not implement it here; it belongs in the derived classes.