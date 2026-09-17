#ifndef ENROLLMENTCART_H
#define ENROLLMENTCART_H

#include <string>
#include <vector>
#include "../../Member1_Domain/include/Course.h"
using namespace std;



class EnrollmentCart{
    private:
    string studentId;
    vector<Course*> selectedCourses;

    public:
    void addCourse(Course* course);
    void removeCourse(Course* course);
    vector<string> showAllCourses();
    bool finalizeRegistration(Student* student);

};

#endif