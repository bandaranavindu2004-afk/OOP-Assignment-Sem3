#include "../include/Course.h"
#include <iostream>

Course::Course(std::string code, std::string title, int credits, int capacity, Lecturer* lec)
    : Code(code), Title(title), Credits(credits), Capacity(capacity), assignedLecturer(lec) {}

// Enrolment Logic: Check capacity before adding a student
void Course::addStudent(Student* student) {
    if (enrolledStudents.size() < Capacity) {
        enrolledStudents.push_back(student);
        std::cout << "Student successfully added to " << Code << std::endl;
    } else {
        std::cout << "Enrollment failed: Course capacity reached!" << std::endl;
    }
}

std::string Course::getCode() const {
    return Code;
}