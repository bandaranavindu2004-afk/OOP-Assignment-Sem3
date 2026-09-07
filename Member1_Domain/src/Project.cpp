#include "../include/Project.h"

Project::Project(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq)
    : Course(code, title, credits, cap, lec), Prerequisites(prereq) {}

std::string Project::calculateGrade() {
    return "Project Grade: Calculated from Final Presentation and Report.";
} 