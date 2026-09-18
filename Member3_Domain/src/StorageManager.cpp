#include "../include/StorageManager.h"
#include "../include/Repository.h"
#include "../../Member1_Domain/include/Person.h"
#include "../../Member1_Domain/include/Course.h"

#include "../../Member1_Domain/include/Student.h"
#include "../../Member1_Domain/include/Lecturer.h"
#include "../../Member1_Domain/include/Administrator.h"

#include "../../Member1_Domain/include/Lecture.h"
#include "../../Member1_Domain/include/Lab.h"
#include "../../Member1_Domain/include/Project.h"

#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;


StorageManager::StorageManager(string userPath, string coursePath)
    : userFilePath(userPath),
      courseFilePath(coursePath)
{
}


void StorageManager::loadAll(Repository<Person>& userRepo,
                             Repository<Course>& courseRepo)
{
    // Load users
        ifstream userFile(userFilePath);

    if (userFile.is_open())
    {
        string line;

        while (getline(userFile, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);

            string role;
            string savedId;
            string name;
            string email;
            string password;

            getline(ss, role, '|');
            getline(ss, savedId, '|');
            getline(ss, name, '|');
            getline(ss, email, '|');
            getline(ss, password);

            Person* person = nullptr;

            if (role == "STUDENT")
            {
                person = new Student(name, email, password);
            }
            else if (role == "LECTURER")
            {
                person = new Lecturer(name, email, password);
            }
            else if (role == "ADMIN")
            {
                person = new Administrator(name, email, password);
            }

            if (person != nullptr)
            {
                userRepo.add(person->getID(), person);
            }
        }

        userFile.close();
    }

    // Load courses
        ifstream courseFile(courseFilePath);

    if (courseFile.is_open())
    {
        string line;

        while (getline(courseFile, line))
        {
            if (line.empty())
                continue;

            stringstream ss(line);

            string type;
            string code;
            string title;
            string creditsText;
            string capacityText;

            getline(ss, type, '|');
            getline(ss, code, '|');
            getline(ss, title, '|');
            getline(ss, creditsText, '|');
            getline(ss, capacityText);

            int credits = stoi(creditsText);
            int capacity = stoi(capacityText);

            Course* course = nullptr;

            if (type == "LECTURE")
            {
                course = new Lecture(
                    code,
                    title,
                    credits,
                    capacity,
                    nullptr,
                    ""
                );
            }
            else if (type == "LAB")
            {
                course = new Lab(
                    code,
                    title,
                    credits,
                    capacity,
                    nullptr,
                    ""
                );
            }
            else if (type == "PROJECT")
            {
                course = new Project(
                    code,
                    title,
                    credits,
                    capacity,
                    nullptr,
                    ""
                );
            }

            if (course != nullptr)
            {
                courseRepo.add(code, course);
            }
        }

        courseFile.close();
    }

    cout << "Data loaded successfully." << endl;

}


void StorageManager::saveAll(Repository<Person>& userRepo,
                             Repository<Course>& courseRepo)
{
    // Save users
    ofstream userFile(userFilePath);

    if (!userFile.is_open())
    {
        cout << "Error: Could not open user file." << endl;
        return;
    }

    vector<Person*> users = userRepo.getAll();

    for (Person* person : users)
    {
        if (person != nullptr)
        {
            userFile << person->getID() << "|"
                     << person->getName() << "|"
                     << person->getEmail() << "|"
                     << person->getPassword()
                     << endl;
        }
    }

    userFile.close();
    // Save courses
    ofstream courseFile(courseFilePath);

    if (!courseFile.is_open())
    {
        cout << "Error: Could not open course file." << endl;
        return;
    }

    vector<Course*> courses = courseRepo.getAll();

    for (Course* course : courses)
    {
        if (course != nullptr)
        {
            courseFile << course->getCode() << "|"
                       << course->getTitle() << "|"
                       << course->getCreditValue() << "|"
                       << course->getCapacity()
                       << endl;
        }
    }

    courseFile.close();

    cout << "Data saved successfully." << endl;

}