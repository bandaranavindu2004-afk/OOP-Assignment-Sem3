#include "../include/Student.h"
#include <iostream>

int Student::StudentNumber = 0;

Student::Student(std::string name, std::string email, std::string password)
    : Person("STU-" + std::to_string(++StudentNumber), name, email, password) {}

void Student::displayDashboard() {
    std::cout << "=== Student Dashboard ===" << std::endl;
    std::cout << "Student ID: " << getID() << std::endl;
}

std::vector<Course*> Student::displayEnrolledCourses() const {
    return enrolledCourses;
}

void Student::enrollInCourse(Course* course) {
    enrolledCourses.push_back(course);
}

void Student::viewTimetable() const {
    std::cout << "Displaying student timetable..." << std::endl;
}

void Student::checkInAttendance(std::string code) {
    std::cout << "Checking in with attendance code: " << code << std::endl;
}