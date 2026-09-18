#include "../include/Course.h"
#include "../include/Student.h"  
#include "../include/Lecturer.h" 

#include "../../Member2_Domain/include/Timetable.h" 
#include "../../Member2_Domain/include/AttendanceRegister.h"

#include <algorithm>
#include <iostream> 

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

std::string Course::getCode() const {
    return Code;
}
std::string Course::getTitle() const {
    return Title;
}

int Course::getCreditValue() const {
    return CreditValue;
}

int Course::getCapacity() const {
    return Capacity;
}

Lecturer* Course::getAssignedLecturer() const {
    return assignedLecturer;
}

bool Course::hasCapacity() const {
    return enrolledStudents.size() < Capacity;
}

void Course::addStudent(Student* student) {
    if (enrolledStudents.size() < Capacity) {
        enrolledStudents.push_back(student);
    }
}

void Course::removeStudent(Student* student) {
    enrolledStudents.erase(std::remove(enrolledStudents.begin(), enrolledStudents.end(), student), enrolledStudents.end());
}

const Timetable& Course::getTimetable() const {
    return *timetable; 
}

AttendanceRegister& Course::getAttendanceRegister() {
    return *attendanceRegister; 
}