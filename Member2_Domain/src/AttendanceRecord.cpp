#include <ctime>
#include "AttendanceRecord.h"
using namespace std;

AttendanceRecord::AttendanceRecord(std::string studId, std::string status, std::string method) : studentId(studId), status(status), capturedBy(method) {
    
    // Create a time stamp string
    time_t now = time(0); // fetches current time
    char* dt = ctime(&now); //convert time to standard form (Weekday Month DD HH:MM:SS YYYY)
    string timeStr(dt);
    
    // Remove newline character at the end defaultly added from ctime
    if (!timeStr.empty() && timeStr.back() == '\n') {
        timeStr.pop_back();
    }
    
    this->timestamp = timeStr;
}

string AttendanceRecord::getStudentID() const {
    return studentId;
}

string AttendanceRecord::getTimestamp() const {
    return timestamp;
}

string AttendanceRecord::getStatus() const {
    return status;
}

string AttendanceRecord::getCapturedBy() const {
    return capturedBy;
}

void AttendanceRecord::addCorrection(CorrectionEntry entry) {
    corrections.push_back(entry);
}

vector<CorrectionEntry> AttendanceRecord::getCorrections() const {
    return corrections;
}