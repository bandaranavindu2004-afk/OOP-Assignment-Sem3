#include "../include/Lecturer.h"
#include <iostream>

int Lecturer::LecturerNumber = 0;

Lecturer::Lecturer(std::string id,
                   std::string name,
                   std::string email,
                   std::string password)
    : Person(id, name, email, password)
{
    if (id.rfind("LEC-", 0) == 0)
    {
        int number = std::stoi(id.substr(4));

        if (number > LecturerNumber)
        {
            LecturerNumber = number;
        }
    }
}

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