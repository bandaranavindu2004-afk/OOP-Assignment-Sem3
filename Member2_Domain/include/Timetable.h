#ifndef TIME_TABLE_H
#define TIME_TABLE_H

#include <vector>
#include <iostream>
#include "TimeSlot.h"
using namespace std;

class Timetable {
private:
    vector<TimeSlot> slots;

public:
    Timetable();

    void addSlot(TimeSlot slot);
    vector<TimeSlot> getTimeSlots() const;
    void displayTable() const;

    // Operator Overloading
    Timetable& operator+=(const TimeSlot& slot); // Add slot with +=
    TimeSlot operator[](int index) const;        // Access slot with []
    
    // Stream Insertion Operator
    friend ostream& operator<<(ostream& os, const Timetable& table);

    bool hasClashWith(const Timetable& other) const;
};

#endif