#ifndef ATTENDANCE_REGISTER_H
#define ATTENDANCE_REGISTER_H

#include <vector>
#include <string>
#include "AttendanceSession.h"
#include "Timeslot.h"
#include "AttendanceCapture.h"

class AttendanceRegister {
private:
    std::vector<AttendanceSession> sessions;

public:
    AttendanceRegister();

    // Creates a new session, add it to the vector and returns a reference
    AttendanceSession& startNewSession(TimeSlot slot, int duration, AttendanceCapture* capture);

    // Calculates attendance percentage for a student for all sessions
    double getAttendancePercentage(std::string studentId) const;

    // Prints an attendance report for all sessions
    void generateReport() const;
};

#endif