#include "TimeTable.h"
using namespace std;

TimeTable::TimeTable() {}

void TimeTable::addSlot(TimeSlot slot) {
    slots.push_back(slot);
}

vector<TimeSlot> TimeTable::getSlots() const {
    return slots;
}

void TimeTable::displayTable() const {
    std::cout << *this; // Reuses the overloaded operator<<
}

// Overloading +=
TimeTable& TimeTable::operator+=(const TimeSlot& slot) {
    this->slots.push_back(slot);
    return *this; // Return reference to allow chaining ( t += s1 += s2)
}

// Overloading []
TimeSlot TimeTable::operator[](int index) const {
    return slots[index];
}

// Stream Insertion Operator
ostream& operator<<(ostream& os, const TimeTable& table) {
    os << "===== Scheduled Time Slots =====" << endl;
    if (table.slots.empty()) {
        os << "No time slots scheduled." << endl;
    } else {
        for (int i = 0; i < table.slots.size(); ++i) {
            os << "Slot " << (i + 1) << ": " << table.slots[i] << endl;
        }
    }
    return os;
}