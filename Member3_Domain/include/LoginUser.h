#ifndef LOGINUSER_H
#define LOGINUSER_H

#include "Person.h"
#include "Repository.h"
using namespace std;

class LoginUser{
    public:
    void displayLoginPage();
    void getData(Repository<Person>& userRepo);
    
};

#endif