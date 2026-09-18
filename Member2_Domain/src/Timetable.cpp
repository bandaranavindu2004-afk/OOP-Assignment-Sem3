#include "../include/Timetable.h"
using namespace std;

Timetable::Timetable() {}

void Timetable::addSlot(TimeSlot slot) {
    slots.push_back(slot);
}

vector<TimeSlot> Timetable::getTimeSlots() const {
    return slots;
}

void Timetable::displayTable() const {
    std::cout << *this; // Reuses the overloaded operator<<
}

// Overloading +=
Timetable& Timetable::operator+=(const TimeSlot& slot) {
    this->slots.push_back(slot);
    return *this; // Return reference to allow chaining ( t += s1 += s2)
}

// Overloading []
TimeSlot Timetable::operator[](int index) const {
    return slots[index];
}

bool Timetable::hasClashWith(const Timetable& other) const {
    const std::vector<TimeSlot>& otherSlots = other.getTimeSlots();
    for (size_t i = 0; i < timeslots.size(); ++i) {
        for (size_t j = 0; j < otherSlots.size(); ++j) {
            if (timeslots[i] == otherSlots[j]) {
                return true; // Clash found
            }
        }
    }
    return false; // No clashes
}