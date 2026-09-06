#include "../include/Lecturer.h"
#include <iostream>

// Initialize the static variable
int Lecturer::LecturerNumber = 0;

Lecturer::Lecturer(std::string id, std::string name, std::string email, std::string password)
    : Person(id, name, email, password) {
    LecturerNumber++; // Auto-increment when a new lecturer is created
}

void Lecturer::displayDashboard() {
    std::cout << "=== Lecturer Dashboard ===" << std::endl;
    std::cout << "Lecturer ID: " << getID() << std::endl;
    std::cout << "Total Assigned Courses: " << assignedCourses.size() << std::endl;
}