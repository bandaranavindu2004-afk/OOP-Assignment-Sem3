#include "../include/EnrollmentCart.h"
#include "../../Member1_Domain/include/Course.h"
#include "../../Member1_Domain/include/Student.h"
#include "../include/Exceptions.h"
#include <iostream>

using namespace std;


// Add a course to the cart
void EnrollmentCart::addCourse(Course* course)
{
    selectedCourses.push_back(course);
}


// Remove a course from the cart
void EnrollmentCart::removeCourse(Course* course)
{
    for (auto it = selectedCourses.begin(); it != selectedCourses.end(); ++it)
    {
        if (*it == course)
        {
            selectedCourses.erase(it);
            return;
        }
    }
}


// Show all selected course codes
vector<string> EnrollmentCart::showAllCourses()
{
    vector<string> courses;

    for (Course* course : selectedCourses)
    {
        if (course != nullptr)
        {
            courses.push_back(course->getCode());
        }
    }

    return courses;
}


// Finalize registration
bool EnrollmentCart::finalizeRegistration(Student* student)
{
    if (selectedCourses.empty()) return false;

    for (Course* course : selectedCourses) {
        try {
            student->enrollInCourse(course);
            course->addStudent(student);
        } catch (const UniversityException& e) {
                cout << "Enrollment failed for " << course->getCode() 
                      << ": " << e.what() << endl;
            return false;  
        }
    }
    selectedCourses.clear();
    return true;
}