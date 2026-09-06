#include "../include/Administrator.h"
#include <iostream>

// Initialize the static variable
int Administrator::AdministratorNumber = 0;

Administrator::Administrator(std::string id, std::string name, std::string email, std::string password)
    : Person(id, name, email, password) {
    AdministratorNumber++; 
}

void Administrator::displayDashboard() {
    std::cout << "=== Administrator Dashboard ===" << std::endl;
    std::cout << "Admin ID: " << getID() << std::endl;
    std::cout << "System access level: Maximum" << std::endl;
}