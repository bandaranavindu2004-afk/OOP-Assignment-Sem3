#include "../include/Course.h"
#include <algorithm>

// Pulling in Member 2's headers
#include "../../Member2_Domain/include/TimeTable.h"
#include "../../Member2_Domain/include/AttendanceRegister.h"

Course::Course(std::string code, std::string title, int credits, int cap, Lecturer* lec)
    : Code(code), Title(title), Credits(credits), Capacity(cap), assignedLecturer(lec),
      courseTimetable(nullptr), courseRegister(nullptr) {} 

void Course::addStudent(Student* student) {
    if (enrolledStudents.size() < Capacity) {
        enrolledStudents.push_back(student);
    }
}

void Course::removeStudent(Student* student) {
    enrolledStudents.erase(std::remove(enrolledStudents.begin(), enrolledStudents.end(), student), enrolledStudents.end());
}

const TimeTable& Course::getTimetable() const {
    return *courseTimetable; 
}

AttendanceRegister* Course::getAttendanceRegister() const {
    return courseRegister; 
}

double Course::getAttendancePercentage(std::string studentId) const {
    return 0.0; 
}