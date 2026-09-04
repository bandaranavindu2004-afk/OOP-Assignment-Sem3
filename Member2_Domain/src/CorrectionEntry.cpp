#include <ctime>
#include "CorrectionEntry.h"
using namespace std;

CorrectionEntry::CorrectionEntry(string author, string reasonText) : correctedBy(author), reason(reasonText) {
    
    // Simple timestamp generation
    time_t now = time(0); // fetches current time
    string timeStr = ctime(&now); //convert time to standard form (Weekday Month DD HH:MM:SS YYYY)
    
    // Remove newline character at the end defaultly added from ctime
    if (!timeStr.empty() && timeStr.back() == '\n') {
        timeStr.pop_back();
    }
    
    this->timestamp = timeStr;
}

string CorrectionEntry::getCorrectedBy() const {
    return correctedBy;
}

string CorrectionEntry::getReason() const {
    return reason;
}

string CorrectionEntry::getTimestamp() const {
    return timestamp;
}