#include "../include/Student.h"
#include <iostream>

// Constructor calling the base Person constructor
Student::Student(std::string id, std::string name, std::string email, std::string password, std::string major)
    : Person(id, name, email, password), major(major) {}

// Implement the dashboard display for students
void Student::displayDashboard() {
    std::cout << "=== Student Dashboard ===" << std::endl;
    std::cout << "Name: " << getID() << std::endl; // or use a getName() if added later
    std::cout << "Major: " << major << std::endl;
    std::cout << "Enrolled Courses Count: " << enrolledCourses.size() << std::endl;
}

// Add a course to the student's schedule
void Student::enrollCourse(std::string courseCode) {
    enrolledCourses.push_back(courseCode);
    std::cout << "Successfully enrolled in " << courseCode << std::endl;
}

// Return the list of enrolled courses
std::vector<std::string> Student::getEnrolledCourses() const {
    return enrolledCourses;
}