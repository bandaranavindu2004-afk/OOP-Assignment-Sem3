#ifndef ENROLLMENTCART_H
#define ENROLLMENTCART_H

#include <string>
#include <vector>
#include "Course.h"
using namespace std;



class EnrollmentCart{
    private:
    string studentId;
    vector<Course*> selectedCourses;

    public:
    void addCourse(Course* course);
    void removeCourse(Course* course);
    vector<string> showAllCourses();
    bool finalizeRegistration();

};

#endif