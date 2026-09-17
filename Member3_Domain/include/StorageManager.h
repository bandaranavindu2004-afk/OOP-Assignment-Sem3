#ifndef STORAGEMANAGER_H
#define STORAGEMANAGER_H

#include <string>
#include "Repository.h"
#include "../../Member1_Domain/include/Person.h"
#include "../../Member1_Domain/include/Course.h"

using namespace std;

class StorageManager{
    private:
    string userFilePath;
    string courseFilePath;

    public:
    StorageManager(string userPath,string coursePath);
    void loadAll(Repository<Person>& userRepo,Repository<Course>& courseRepo);
    void saveAll(Repository<Person>& userRepo,Repository<Course>& courseRepo);
};
#endif