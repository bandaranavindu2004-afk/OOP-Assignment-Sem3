#include <iostream>
#include <string>
#include <ctime>
#include "RotatingSessionCodeCapture.h"
using namespace std;

RotatingSessionCodeCapture::RotatingSessionCodeCapture(){}

string RotatingSessionCodeCapture::generateNewCode(){
    currentActiveCode = "Session Code: " + to_string(rand()%9000+1000);
    return currentActiveCode;
}

void RotatingSessionCodeCapture::beginSession() {
    generateNewCode();
    expiryTime = "1 minute";
    cout<< "Rotating Session Started: " <<endl;
}

string RotatingSessionCodeCapture::captureNext() {
    return currentActiveCode;
}

void RotatingSessionCodeCapture::endSession(){
    currentActiveCode="0000";
    cout << "Rotating Session Ended."<<endl;
}