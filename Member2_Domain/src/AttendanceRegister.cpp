#include <iostream>
#include "AttendanceRegister.h"
using namespace std;

AttendanceRegister::AttendanceRegister() {} // Vector starts empty

AttendanceSession& AttendanceRegister::startNewSession(TimeSlot slot, int duration, AttendanceCapture* capture) {
    // Create a unique session ID based on current session count
    string newSessionId = "SES_" + to_string(sessions.size() + 1);

    // Create session object which matches AttendanceSession constructor
    AttendanceSession newSession(newSessionId, slot, duration, capture);

    // Storing in vector
    sessions.push_back(newSession);

    // Return the reference of the created session inside the vector
    return sessions.back();
}

double AttendanceRegister::getAttendancePercentage(string studentId) const {
    if (sessions.empty()) {
        return 0.0;
    }

    int totalSessions = sessions.size();
    int attendedSessions = 0;

    // Iterate through all the recorded sessions
    for (const AttendanceSession& session : sessions) {
        vector<AttendanceRecord> records = session.getRecords();
        
        // Check if a student exists in the session records
        for (const AttendanceRecord& record : records) {
            if (record.getStudentID() == studentId) { 
                attendedSessions++;
                break; // Found student in this session, move to next session
            }
        }
    }

    return (attendedSessions * 100.0) / totalSessions;
}

void AttendanceRegister::generateReport() const {
    cout << "=============== ATTENDANCE REPORT ===============" << endl;
    cout << "Total Sessions: " << sessions.size() << endl;

    for (int i = 0; i < sessions.size(); ++i) {
        vector<AttendanceRecord> records = sessions[i].getRecords();
        cout << "Session Number " << (i + 1) << " => Total Present: " << records.size() << endl;

        for (const AttendanceRecord& record : records) {
            cout << " # Student ID: " << record.getStudentID();
            cout << " => Status: " << record.getStatus();
            cout << " => Method: " << record.getCapturedBy() << endl;
        }
    }
    cout << "================================================" << endl;
}