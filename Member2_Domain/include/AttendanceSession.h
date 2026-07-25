#include <string>
#include <vector>
using namespace std;

class Timeslot;
class AttendanceRecord;

class AttendanceSession{
    private:
        string sessionID;
        Timeslot timeslot;
        bool isOpen;
        string startTime;
        int durationMinutes;
        vector<AttendanceRecord> records;
    public:
        AttendanceSession();
        void markPresent(string studentID, string method);
        void closeSession();
        vector<AttendanceRecord> getRecords() const;
}