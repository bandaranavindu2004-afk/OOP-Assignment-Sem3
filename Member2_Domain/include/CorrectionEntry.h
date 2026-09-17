#ifndef CORRECTION_ENTRY_H
#define CORRECTION_ENTRY_H

#include <string>
using namespace std;

class CorrectionEntry {
private:
    string correctedBy;
    string reason;
    string timestamp;

public:
    CorrectionEntry(string author, string reasonText);

    // Getters for correction entry
    string getCorrectedBy() const;
    string getReason() const;
    string getTimestamp() const;
};

#endif