#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <exception>

using namespace std;

class UniversityException : public exception {
public:
    virtual const char* what() const noexcept = 0;
};

class EnrollmentException : public UniversityException {
public:
    const char* what() const noexcept override;
};

class TimetableClashException : public UniversityException {
public:
    const char* what() const noexcept override;
};

class AttendanceException : public UniversityException {
public:
    const char* what() const noexcept override;
};

class SessionClosedException : public AttendanceException {
public:
    const char* what() const noexcept override;
};

class NotEnrolledException : public AttendanceException {
public:
    const char* what() const noexcept override;
};

class DuplicateAttendanceException : public AttendanceException {
public:
    const char* what() const noexcept override;
};

#endif