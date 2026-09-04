#include <iostream>
#include <string>
#include <vector>
#include "AttendanceSession.h"
#include "Timeslot.h"
#include "AttendanceCapture.h"
#include "AttendanceRecord.h"

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