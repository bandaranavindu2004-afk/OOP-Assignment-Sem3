#ifndef TIME_SLOT_H
#define TIME_SLOT_H

#include <string>
#include <iostream>
using namespace std;

class TimeSlot {
private:
    string startTime;
    int durationMinutes;

public:
    // default constructor
    TimeSlot();

    //parameterized constructor
    TimeSlot(std::string start, int duration);

    string getStartTime() const;
    int getDurationMinutes() const;
    string getSlotDetails() const;

    // Operator Overloading
    bool operator==(const TimeSlot& other) const;
    
    // Friend function
    friend ostream& operator<<(ostream& os, const TimeSlot& slot);
};

#endif