#include <string>
#include <fstream>
#include "AttendanceCapture.h"
using namespace std;

class AttendanceSession;

class FileReplayCapture : public AttendanceCapture {
    private:
        string filePath;
        ifstream fileStream;
    public:
        FileReplayCapture (const string& path);
        void beginSession(AttendanceSession* session) override;
        void captureNext() override;
        void endSession() override;
};