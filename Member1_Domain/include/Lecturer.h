#ifndef LECTURER_H
#define LECTURER_H

#include "Person.h"
#include <vector>
#include <string>
#include "../../Member2_Domain/include/TimeSlot.h" 

class Course; 
class AttendanceCapture;

class Lecturer : public Person {
private:
    static int LecturerNumber;
    std::vector<Course*> assignedCourses;

public:
    Lecturer(std::string name, std::string email, std::string password);
    ~Lecturer() override = default;

    void displayDashboard() override;
    std::vector<Course*> displayAssignedCourses() const;
    void openAttendanceSession(Course* course, TimeSlot slot, int duration, AttendanceCapture* capture);
    void closeAttendanceSession(Course* course);
};
#endif