#ifndef TIME_TABLE_H
#define TIME_TABLE_H

#include <vector>
#include <iostream>
#include "TimeSlot.h"
using namespace std;

class TimeTable {
private:
    vector<TimeSlot> slots;

public:
    TimeTable();

    void addSlot(TimeSlot slot);
    vector<TimeSlot> getSlots() const;
    void displayTable() const;

    // Operator Overloading
    TimeTable& operator+=(const TimeSlot& slot); // Add slot with +=
    TimeSlot operator[](int index) const;        // Access slot with []
    
    // Stream Insertion Operator
    friend ostream& operator<<(ostream& os, const TimeTable& table);
};

#endif