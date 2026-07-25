#include<string>
using namespace std;

class AttendanceSession;

class AttendanceCapture {
    public:
        virtual ~AttendanceCapture() = default;
        virtual void beginSession(AttendanceSession* session) = 0;
        virtual string captureNext() = 0;
        virtual void endSession() = 0;
};