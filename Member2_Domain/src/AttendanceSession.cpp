#include <iostream>
#include <string>
#include <vector>
#include "../include/AttendanceSession.h"
#include "../include/Timeslot.h"
#include "../include/AttendanceCapture.h"
#include "../include/AttendanceRecord.h"

AttendanceSession::AttendanceSession(string id, TimeSlot slot, int duration, AttendanceCapture* capture) : sessionID(id), timeslot(slot), durationMinutes(duration) {
    this->isOpen=true;
    if(capture!=nullptr){
        capture -> beginSession(this);
    }
}

void AttendanceSession::markPresent(string studentid, string method){
    if(isOpen==false){
        cout << "Error: Session is inactive." << endl;
        return;
    }
    AttendanceRecord record(studentid, "Present", method);
    records.push_back(record);
}

void AttendanceSession::closeSession(){
    this->isOpen=false;
}

vector<AttendanceRecord> AttendanceSession::getRecords() const{
    return records;
}

string AttendanceSession::getSessionId() const {
    return this->sessionID;
}