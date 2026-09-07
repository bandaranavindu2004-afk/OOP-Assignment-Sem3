#ifndef COURSE_H
#define COURSE_H

#include <string>
#include <vector>

class Lecturer; // Forward declaration
class Student;  // Forward declaration

class Course {
protected:
    std::string Code;
    std::string Title;
    int Credits;
    int Capacity;
    Lecturer* assignedLecturer;
    std::vector<Student*> enrolledStudents;

public:
    Course(std::string code, std::string title, int credits, int capacity, Lecturer* lec);
    virtual ~Course() = default;

    // Pure virtual function making this an abstract class
    virtual std::string calculateGrade() = 0;

    void addStudent(Student* student);
    std::string getCode() const;
};

#endif