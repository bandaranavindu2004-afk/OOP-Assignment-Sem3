#include "EnrollmentCart.h"
#include "Course.h"

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
bool EnrollmentCart::finalizeRegistration()
{
    if (selectedCourses.empty())
    {
        return false;
    }

    return true;
}