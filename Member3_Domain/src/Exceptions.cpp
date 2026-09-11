#include "Exceptions.h"

const char* EnrollmentException::what() const noexcept {
    return "Enrolment Exception";
}

const char* TimetableClashException::what() const noexcept {
    return "Timetable Clash Exception";
}

const char* AttendanceException::what() const noexcept {
    return "Attendance Exception";
}

const char* SessionClosedException::what() const noexcept {
    return "Session Closed Exception";
}

const char* NotEnrolledException::what() const noexcept {
    return "Not Enrolled Exception";
}

const char* DuplicateAttendanceException::what() const noexcept {
    return "Duplicate Attendance Exception";
}