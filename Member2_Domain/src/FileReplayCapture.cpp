#include <iostream>
#include "AttendanceCapture.h"
using namespace std;

FileReplayCapture::FileReplayCapture(const string& path) : filePath(path) {}

void FileReplayCapture::beginSession (AttendanceSession* session){
    fileStream.open(filePath);
    
    if(!fileStream.is_open()){
        cout << "Error: Save file cannot be loaded" << endl;
    }
}

void captureNext::FileReplayCapture() {
    string studentID;

    if(fileStream >> studentID){
        return studentID;
    }
    return "Empty";
}

void endSession::FileReplayCapture(){
    if(fileStream.is_open()){
        fileStream.close();
    }
}