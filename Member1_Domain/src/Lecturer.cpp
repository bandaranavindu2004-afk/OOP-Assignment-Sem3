#include "../include/Lecturer.h"
#include <iostream>

// Pulling in Member 2's actual header
#include "../../Member2_Domain/include/TimeSlot.h"

int Lecturer::LecturerNumber = 0;

Lecturer::Lecturer(std::string name, std::string email, std::string password)
    : Person("LEC-" + std::to_string(++LecturerNumber), name, email, password) {}

void Lecturer::displayDashboard() {
    std::cout << "=== Lecturer Dashboard ===" << std::endl;
    std::cout << "Lecturer ID: " << getID() << std::endl;
}

std::vector<Course*> Lecturer::displayAssignedCourses() const {
    return assignedCourses;
}

void Lecturer::openAttendanceSession(Course* course, TimeSlot slot, int duration, AttendanceCapture* capture) {
    std::cout << "Attendance session opened." << std::endl;
}

void Lecturer::closeAttendanceSession(Course* course) {
    std::cout << "Attendance session closed." << std::endl;
}