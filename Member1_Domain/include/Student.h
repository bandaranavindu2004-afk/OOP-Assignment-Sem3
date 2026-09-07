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
    Student(std::string id, std::string name, std::string email, std::string password, std::string major);

    void displayDashboard() override;

    void enrollCourse(std::string courseCode);
    std::vector<std::string> getEnrolledCourses() const;
};

#endif