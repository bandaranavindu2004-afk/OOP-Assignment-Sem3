#ifndef PROJECT_H
#define PROJECT_H
#include "Course.h"
#include <string>

class Project : public Course {
private:
    std::string Prerequisites;
public:
    Project(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq);
    std::string calculateGrade() override;
};
#endif 