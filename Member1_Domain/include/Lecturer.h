#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"
#include <vector>
#include <string>

class Course; 

class Lecturer : public Person {
private:
    static int LecturerNumber;
    std::vector<Course*> assignedCourses;

public:
    Lecturer(std::string id, std::string name, std::string email, std::string password);
    void displayDashboard() override;
    
};

#endif