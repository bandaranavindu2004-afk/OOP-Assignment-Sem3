#ifndef UTILITIES_H
#define UTILITIES_H

#include <iostream>

#include "../../Member1_Domain/include/Person.h"
#include "../../Member1_Domain/include/Course.h"
#include "../../Member2_Domain/include/TimeTable.h"

using namespace std;

ostream& operator<<(ostream& os, const Person& p);
ostream& operator<<(ostream& os, const Course& c);
ostream& operator<<(ostream& os, const TimeTable& tt);

#endif