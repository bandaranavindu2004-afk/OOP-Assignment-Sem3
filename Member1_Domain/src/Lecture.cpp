#include "../include/Lecture.h"

Lecture::Lecture(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq)
    : Course(code, title, credits, cap, lec), Prerequisites(prereq) {}

std::string Lecture::calculateGrading() {
    return "Lecture Grade";
}
std::string Lecture::getPrerequisites() const
{
    return Prerequisites;
}
