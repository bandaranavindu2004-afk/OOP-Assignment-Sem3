#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

#include "Person.h"
#include "Course.h"
#include "TimeTable.h"

using namespace std;

ostream& operator<<(ostream& os, const Person& p);
ostream& operator<<(ostream& os, const Course& c);
ostream& operator<<(ostream& os, const TimeTable& tt);

#endif