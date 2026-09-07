#include "../include/Lecture.h"

Lecture::Lecture(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq)
    : Course(code, title, credits, cap, lec), Prerequisites(prereq) {}

std::string Lecture::calculateGrade() {
    return "Lecture Grade: Calculated from Final Exam and Midterms.";
} 