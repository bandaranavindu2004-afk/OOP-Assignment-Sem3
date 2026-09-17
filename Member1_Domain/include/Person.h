#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream> 

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
    void getInfo() const; 
    bool checkPassword(std::string password) const;

    // Integration with Member 3's Utilities
    friend std::ostream& operator<<(std::ostream& os, const Person& p);
};
#endif