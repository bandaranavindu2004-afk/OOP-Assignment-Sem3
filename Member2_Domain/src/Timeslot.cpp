#include <sstream>
#include "TimeSlot.h"
using namespace std;

TimeSlot::TimeSlot() : startTime("00:00"), durationMinutes(0) {}

TimeSlot::TimeSlot(string start, int duration) : startTime(start), durationMinutes(duration) {}

string TimeSlot::getStartTime() const {
    return startTime;
}

int TimeSlot::getDurationMinutes() const {
    return durationMinutes;
}

string TimeSlot::getSlotDetails() const {
    stringstream ss; // to convert numbers to text and append
    ss << startTime << " (" << durationMinutes << " mins)";
    return ss.str(); // to get the appended strings as a single string
}

// check if start time and duration are same
bool TimeSlot::operator==(const TimeSlot& other) const {
    return (this->startTime == other.startTime && this->durationMinutes == other.durationMinutes);
}

// Stream Insertion Operator
std::ostream& operator<<(std::ostream& os, const TimeSlot& slot) {
    os << slot.getSlotDetails();
    return os;
}