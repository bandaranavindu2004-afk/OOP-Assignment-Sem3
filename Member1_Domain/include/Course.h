#ifndef COURSE_H
#define COURSE_H
#include <string>
#include <vector>

class Lecturer;
class Student;
class Timetable;  
class AttendanceRegister;

class Course {
private:
    std::string Code;
    std::string Title;
    int CreditValue; 
    int Capacity;
    Lecturer* assignedLecturer;
    std::vector<Student*> enrolledStudents;
    
    Timetable* timetable; 
    AttendanceRegister* attendanceRegister; 

public:
    Course(std::string code, std::string title, int credits, int cap, Lecturer* lec);
    virtual ~Course() = default;

    virtual std::string calculateGrading() = 0; 

    void displayInfo() const; 
    
    std::string getCode() const;
    bool hasCapacity() const;

    void addStudent(Student* student);
    void removeStudent(Student* student);
    
    const Timetable& getTimetable() const; 
    AttendanceRegister& getAttendanceRegister(); 
};
#endif