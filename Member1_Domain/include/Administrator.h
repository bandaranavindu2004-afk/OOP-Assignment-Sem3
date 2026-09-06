#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include "Person.h"
#include <string>

class Administrator : public Person {
private:
    static int AdministratorNumber;

public:
    Administrator(std::string id, std::string name, std::string email, std::string password);
    void displayDashboard() override;
};

#endif