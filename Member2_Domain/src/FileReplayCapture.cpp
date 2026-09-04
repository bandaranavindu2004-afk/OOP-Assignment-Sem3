#include <iostream>
#include "AttendanceCapture.h"
#include "FileReplayCapture.h"
using namespace std;

FileReplayCapture::FileReplayCapture(const string& path) : filePath(path) {}

void FileReplayCapture::beginSession (AttendanceSession* session){
    fileStream.open(filePath);
    
    if(!fileStream.is_open()){
        cout << "Error: Save file cannot be loaded" << endl;
    }
}

string FileReplayCapture::captureNext() {
    string studentID;

    if(fileStream >> studentID){
        return studentID;
    }
    return "Empty";
}

void FileReplayCapture::endSession(){
    if(fileStream.is_open()){
        fileStream.close();
    }
}