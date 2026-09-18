#include "../include/Course.h"
#include "../include/Student.h"
#include "../include/Lecturer.h"

#include "../../Member2_Domain/include/Timetable.h"
#include "../../Member2_Domain/include/AttendanceRegister.h"

#include <algorithm>
#include <iostream>


Course::Course(std::string code,
               std::string title,
               int credits,
               int cap,
               Lecturer* lec)
    : Code(code),
      Title(title),
      CreditValue(credits),
      Capacity(cap),
      assignedLecturer(lec),
      timetable(new Timetable()),
      attendanceRegister(new AttendanceRegister())
{
}


Course::~Course()
{
    delete timetable;
    delete attendanceRegister;
}


void Course::displayInfo() const
{
    std::cout << "Course Code: " << Code << "\n"
              << "Title: " << Title << "\n"
              << "Credits: " << CreditValue << "\n"
              << "Capacity: " << Capacity << "\n"
              << "Enrolled Students: "
              << enrolledStudents.size()
              << "/" << Capacity << "\n";
}


std::string Course::getCode() const
{
    return Code;
}


std::string Course::getTitle() const
{
    return Title;
}


int Course::getCreditValue() const
{
    return CreditValue;
}


int Course::getCapacity() const
{
    return Capacity;
}


Lecturer* Course::getAssignedLecturer() const
{
    return assignedLecturer;
}


bool Course::hasCapacity() const
{
    return enrolledStudents.size() < static_cast<size_t>(Capacity);
}


void Course::setTitle(std::string title)
{
    Title = title;
}


void Course::setCreditValue(int credits)
{
    CreditValue = credits;
}


void Course::setCapacity(int cap)
{
    if (cap >= static_cast<int>(enrolledStudents.size()))
    {
        Capacity = cap;
    }
    else
    {
        std::cout
            << "Error: New capacity cannot be less than currently enrolled students ("
            << enrolledStudents.size()
            << ")!"
            << std::endl;
    }
}


void Course::setAssignedLecturer(Lecturer* lec)
{
    assignedLecturer = lec;
}


void Course::addStudent(Student* student)
{
    if (student == nullptr)
        return;

    // Avoid duplicate students
    if (std::find(enrolledStudents.begin(),
                  enrolledStudents.end(),
                  student) != enrolledStudents.end())
    {
        return;
    }

    if (hasCapacity())
    {
        enrolledStudents.push_back(student);
    }
}


void Course::removeStudent(Student* student)
{
    enrolledStudents.erase(
        std::remove(
            enrolledStudents.begin(),
            enrolledStudents.end(),
            student),
        enrolledStudents.end());
}


const Timetable& Course::getTimetable() const
{
    return *timetable;
}


AttendanceRegister& Course::getAttendanceRegister()
{
    return *attendanceRegister;
}