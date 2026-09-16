#include "../include/Lab.h"

Lab::Lab(std::string code, std::string title, int credits, int cap, Lecturer* lec, std::string prereq)
    : Course(code, title, credits, cap, lec), Prerequisites(prereq) {}

std::string Lab::calculateGrade() {
    return "Lab Grade";
}