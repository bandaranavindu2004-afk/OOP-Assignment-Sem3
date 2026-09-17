#include "../include/Student.h"
#include "../include/Course.h" 
#include "../../Member2_Domain/include/TimeTable.h" 
#include "../../Member2_Domain/include/TimeSlot.h" 

#include "../../Member3_Domain/include/Exceptions.h" 

#include <iostream>
#include <vector>

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
    if (!course->hasCapacity()) {
        throw EnrollmentException(); 
    }

    std::vector<TimeSlot> newCourseSlots = course->getTimetable().getTimeSlots();
    
    for (Course* existingCourse : enrolledCourses) {
        std::vector<TimeSlot> existingSlots = existingCourse->getTimetable().getTimeSlots();
        
        for (const TimeSlot& newSlot : newCourseSlots) {
            for (const TimeSlot& existingSlot : existingSlots) {
                if (newSlot == existingSlot) { 
                    throw TimetableClashException();
                }
            }
        }
    }

    enrolledCourses.push_back(course);
    course->addStudent(this); 
}

void Student::viewTimetable() const {
    std::cout << "Displaying student timetable..." << std::endl;
}

void Student::checkInAttendance(std::string code) {
    std::cout << "Checking in with attendance code: " << code << std::endl;
}