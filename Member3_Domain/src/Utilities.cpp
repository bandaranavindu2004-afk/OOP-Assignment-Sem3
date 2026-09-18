#include "../include/Utilities.h"

using namespace std;



ostream& operator<<(ostream& os, const Person& p)
{
    os << "Person ID: " << p.getID();

    return os;
}



ostream& operator<<(ostream& os, const Course& c)
{
    os << "Course Code: " << c.getCode();

    return os;
}



ostream& operator<<(ostream& os, const Timetable& table)
{
    vector<TimeSlot> slots = table.getTimeSlots();

    os << "TimeTable:" << endl;

    for (const TimeSlot& slot : slots)
    {
        os << "  " << slot.getSlotDetails() << endl;
    }

    return os;
}