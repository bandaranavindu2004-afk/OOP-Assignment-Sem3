#include <string>
#include "AttendanceCapture.h"

class AttendanceSession;

class RotatingSessionCodeCapture : public AttendanceCapture {
    private:
        string currentActiveCode;
        string expiryTime;
    public:
        RotatingSessionCodeCapture();
        string generateNewCode();
        void beginSession(AttendanceSession* session) override;
        string captureNext() override;
        void endSession() override;
    }