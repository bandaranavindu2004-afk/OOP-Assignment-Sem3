#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"
#include <vector>
#include <string>

class Course; // Forward declaration for Member 1's Course class

class Lecturer : public Person {
private:
    static int LecturerNumber;
    std::vector<Course*> assignedCourses;

public:
    Lecturer(std::string id, std::string name, std::string email, std::string password);
    void displayDashboard() override;
    
    // We will add the Attendance capture methods later once Member 2 finishes their engine
};

#endif