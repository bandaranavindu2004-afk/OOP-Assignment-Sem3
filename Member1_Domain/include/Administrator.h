#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H
#include "Person.h"
#include <string>

template <typename T> class Repository;
class Course;

class Administrator : public Person {
private:
    static int AdministratorNumber;

public:
    Administrator(std::string id,std::string name,std::string email,std::string password);

    void displayDashboard() override;
    
    // Repository Operations
    void createUser(Repository<Person>& userRepo);
    void updateUser(Repository<Person>& userRepo);
    void removeUser(Repository<Person>& userRepo);
    void createCourse(Repository<Course>& courseRepo);
    void editCourse(Repository<Course>& courseRepo);
    void removeCourse(Repository<Course>& courseRepo);
    void getEnrollmentReport(Repository<Course>& courseRepo);
};
#endif