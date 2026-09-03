#ifndef STUDENT_H
#define STUDENT_H

#include "Person.h"
#include <vector>
#include <string>

class Student : public Person {
private:
    std::string major;
    std::vector<std::string> enrolledCourses;

public:
    // Constructor
    Student(std::string id, std::string name, std::string email, std::string password, std::string major);

    // Override the pure virtual dashboard method
    void displayDashboard() override;

    // Student-specific methods
    void enrollCourse(std::string courseCode);
    std::vector<std::string> getEnrolledCourses() const;
};

#endif