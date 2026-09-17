#include "../include/LoginUser.h"
#include "../include/Repository.h"
#include "../../Member1_Domain/include/Person.h"

#include <iostream>
#include <string>

using namespace std;


void LoginUser::displayLoginPage()
{
    cout << "       LOGIN PAGE       " << endl;
}


void LoginUser::getData(Repository<Person>& userRepo)
{
    string id;
    string password;

    cout << "Enter ID: ";
    cin >> id;

    cout << "Enter Password: ";
    cin >> password;

    Person* user = userRepo.find(id);

    if (user != nullptr && user->checkPassword(password))
    {
        cout << "Login successful." << endl;
    }
    else
    {
        cout << "Invalid ID or Password." << endl;
    }
}