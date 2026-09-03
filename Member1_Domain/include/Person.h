#ifndef PERSON_H
#define PERSON_H

#include <string>

class Person {
private:
    std::string ID;
    std::string Name;
    std::string Email;
    std::string Password;

public:
    Person(std::string id, std::string name, std::string email, std::string password);
    virtual ~Person() = default;
    virtual void displayDashboard() = 0;
    std::string getID() const;
    bool checkPassword(std::string password) const;
};

#endif