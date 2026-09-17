#ifndef ATTENDANCE_SESSION_H
#define ATTENDANCE_SESSION_H

#include <string>
#include <vector>
#include "Timeslot.h"
#include "AttendanceRecord.h"
#include "AttendanceCapture.h"
using namespace std;

class AttendanceSession{
    private:
        string sessionID;
        TimeSlot timeslot;
        bool isOpen;
        string startTime;
        int durationMinutes;
        vector<AttendanceRecord> records;
    public:
        AttendanceSession(string id, TimeSlot s, int dur, AttendanceCapture* cap = NULL);
        void markPresent(string studentID, string method);
        void closeSession();
        vector<AttendanceRecord> getRecords() const;
};

#endif