#ifndef LECTURE_H
#define LECTURE_H
#include "Course.h"
#include <string>

class Lecture : public Course {
private:
    std::string Prerequisites;
public:
    Lecture(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq);
    std::string calculateGrade() override;
};
#endif 