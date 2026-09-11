#include "StorageManager.h"
#include "Repository.h"
#include "Person.h"
#include "Course.h"

using namespace std;


StorageManager::StorageManager(string userPath, string coursePath)
    : userFilePath(userPath),
      courseFilePath(coursePath)
{
}


void StorageManager::loadAll(Repository<Person>& userRepo,
                             Repository<Course>& courseRepo)
{
    // Load users from user file
    // Load courses from course file
}


void StorageManager::saveAll(Repository<Person>& userRepo,
                             Repository<Course>& courseRepo)
{
    // Save users to user file
    // Save courses to course file
}