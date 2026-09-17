#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>
#include <iostream> 

class Lecturer;
class Student;
class TimeTable; 
class AttendanceRegister;

class Course {
private:
    std::string Code;
    std::string Title;
    int Credits;
    int Capacity;
    Lecturer* assignedLecturer;
    std::vector<Student*> enrolledStudents;
    
    // Composition pointers
    TimeTable* courseTimetable;
    AttendanceRegister* courseRegister;

public:
    Course(std::string code, std::string title, int credits, int cap, Lecturer* lec);
    virtual ~Course() = default;

    virtual std::string calculateGrade() = 0; 

    void addStudent(Student* student);
    void removeStudent(Student* student);
    
    const TimeTable& getTimetable() const; 
    AttendanceRegister* getAttendanceRegister() const; 
    double getAttendancePercentage(std::string studentId) const;

    // Integration with Member 3's Utilities
    friend std::ostream& operator<<(std::ostream& os, const Course& c);
};
#endif