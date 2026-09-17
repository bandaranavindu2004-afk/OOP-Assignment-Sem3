#ifndef LAB_H
#define LAB_H
#include "Course.h"
#include <string>

class Lab : public Course {
private:
    std::string Prerequisites;
public:
    Lab(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq);
    std::string calculateGrading() override; // FIXED: Matches UML
};
#endif