#ifndef LOGINUSER_H
#define LOGINUSER_H

#include "../../Member1_Domain/include/Person.h"
#include "Repository.h"
using namespace std;

class LoginUser{
    public:
    void displayLoginPage();
    void getData(Repository<Person>& userRepo);
    
};

#endif