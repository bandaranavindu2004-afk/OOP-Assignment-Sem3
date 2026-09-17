#ifndef ATTENDANCE_RECORD_H
#define ATTENDANCE_RECORD_H

#include <string>
#include <vector>
#include "CorrectionEntry.h"
using namespace std;

class AttendanceRecord {
private:
    string studentId;
    string timestamp;
    string status;
    string capturedBy;
    vector<CorrectionEntry> corrections;

public:
    AttendanceRecord(string studId, string status, string method);

    // Getters for the vector
    string getStudentID() const;
    string getTimestamp() const;
    string getStatus() const;
    string getCapturedBy() const;

    // Correction management
    void addCorrection(CorrectionEntry entry);
    vector<CorrectionEntry> getCorrections() const;
};

#endif