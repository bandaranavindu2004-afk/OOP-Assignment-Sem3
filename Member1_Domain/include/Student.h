#ifndef STUDENT_H
#define STUDENT_H
#include "Person.h"
#include <vector>
#include <string>

class Course; 

class Student : public Person {
private:
    static int StudentNumber; 
    std::vector<Course*> enrolledCourses;

public:

    Student(std::string id,
            std::string name,
            std::string email,
            std::string password);

    ~Student() override = default;

    void displayDashboard() override;
    std::vector<Course*> displayEnrolledCourses() const;
    void enrollInCourse(Course* course);
    void viewTimetable() const;
    void checkInAttendance(std::string code);
};
#endif