#include "../include/Course.h"
#include <algorithm>
#include <iostream> 

// Pulling in Member 2's headers
#include "../../Member2_Domain/include/TimeTable.h"
#include "../../Member2_Domain/include/AttendanceRegister.h"

Course::Course(std::string code, std::string title, int credits, int cap, Lecturer* lec)
    : Code(code), Title(title), CreditValue(credits), Capacity(cap), assignedLecturer(lec),
      timetable(nullptr), attendanceRegister(nullptr) {} 

void Course::displayInfo() const {
    std::cout << "Course Code: " << Code << "\n"
              << "Title: " << Title << "\n"
              << "Credits: " << CreditValue << "\n"
              << "Capacity: " << Capacity << "\n"
              << "Enrolled Students: " << enrolledStudents.size() << "/" << Capacity << "\n";
}

void Course::addStudent(Student* student) {
    if (enrolledStudents.size() < Capacity) {
        enrolledStudents.push_back(student);
    }
}

void Course::removeStudent(Student* student) {
    enrolledStudents.erase(std::remove(enrolledStudents.begin(), enrolledStudents.end(), student), enrolledStudents.end());
}

const TimeTable& Course::getTimetable() const {
    return *timetable; // Returns reference as required
}

AttendanceRegister& Course::getAttendanceRegister() {
    return *attendanceRegister; 
}

double Course::getAttendancePercentage(std::string studentId) const {
    return 0.0; 
}