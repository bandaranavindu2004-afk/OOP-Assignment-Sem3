#include "../include/Administrator.h"
#include <iostream>

int Administrator::AdministratorNumber = 0;

Administrator::Administrator(std::string id,
                             std::string name,
                             std::string email,
                             std::string password)
    : Person(id, name, email, password)
{
    if (id.rfind("ADM-", 0) == 0)
    {
        int number = std::stoi(id.substr(4));

        if (number > AdministratorNumber)
        {
            AdministratorNumber = number;
        }
    }
}
void Administrator::displayDashboard() {
    std::cout << "=== Administrator Dashboard ===" << std::endl;
    std::cout << "Admin ID: " << getID() << std::endl;
}

void Administrator::createUser(Repository<Person>& userRepo) {
    std::cout << "Creating user..." << std::endl;
}
void Administrator::updateUser(Repository<Person>& userRepo) {
    std::cout << "Updating user..." << std::endl;
}
void Administrator::removeUser(Repository<Person>& userRepo) {
    std::cout << "Removing user..." << std::endl;
}
void Administrator::createCourse(Repository<Course>& courseRepo) {
    std::cout << "Creating course..." << std::endl;
}
void Administrator::editCourse(Repository<Course>& courseRepo) {
    std::cout << "Editing course..." << std::endl;
}
void Administrator::removeCourse(Repository<Course>& courseRepo) {
    std::cout << "Removing course..." << std::endl;
}
void Administrator::getEnrollmentReport(Repository<Course>& courseRepo) {
    std::cout << "Generating enrollment report..." << std::endl;
}