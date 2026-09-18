#include "../include/StorageManager.h"
#include "../include/Repository.h"

#include "../../Member1_Domain/include/Person.h"
#include "../../Member1_Domain/include/Student.h"
#include "../../Member1_Domain/include/Lecturer.h"
#include "../../Member1_Domain/include/Administrator.h"

#include "../../Member1_Domain/include/Course.h"
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

    // LOAD USERS


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
            string id;
            string name;
            string email;
            string password;

            getline(ss, role, '|');
            getline(ss, id, '|');
            getline(ss, name, '|');
            getline(ss, email, '|');
            getline(ss, password);

            Person* person = nullptr;

            if (role == "STUDENT")
            {
                person = new Student(
                    id,
                    name,
                    email,
                    password
                );
            }
            else if (role == "LECTURER")
            {
                person = new Lecturer(
                    id,
                    name,
                    email,
                    password
                );
            }
            else if (role == "ADMIN")
            {
                person = new Administrator(
                    id,
                    name,
                    email,
                    password
                );
            }

            if (person != nullptr)
            {
                userRepo.add(id, person);
            }
        }

        userFile.close();

        cout << "Users loaded successfully." << endl;
    }
    else
    {
        cout << "User file not found." << endl;
    }

    // LOAD COURSES


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
            string lecturerId;
            string prerequisite;

            getline(ss, type, '|');
            getline(ss, code, '|');
            getline(ss, title, '|');
            getline(ss, creditsText, '|');
            getline(ss, capacityText, '|');
            getline(ss, lecturerId, '|');
            getline(ss, prerequisite);

            try
            {
                int credits = stoi(creditsText);
                int capacity = stoi(capacityText);

                Lecturer* lecturer = nullptr;

                
                if (lecturerId != "NONE")
                {
                    Person* person = userRepo.find(lecturerId);

                    lecturer =
                        dynamic_cast<Lecturer*>(person);
                }

                Course* course = nullptr;

                if (type == "LECTURE")
                {
                    course = new Lecture(
                        code,
                        title,
                        credits,
                        capacity,
                        lecturer,
                        prerequisite
                    );
                }
                else if (type == "LAB")
                {
                    course = new Lab(
                        code,
                        title,
                        credits,
                        capacity,
                        lecturer,
                        prerequisite
                    );
                }
                else if (type == "PROJECT")
                {
                    course = new Project(
                        code,
                        title,
                        credits,
                        capacity,
                        lecturer,
                        prerequisite
                    );
                }

                if (course != nullptr)
                {
                    courseRepo.add(code, course);
                }
            }
            catch (const exception& e)
            {
                cout << "Invalid course data: "
                     << e.what()
                     << endl;
            }
        }

        courseFile.close();

        cout << "Courses loaded successfully." << endl;
    }
    else
    {
        cout << "Course file not found." << endl;
    }
}
void StorageManager::saveAll(Repository<Person>& userRepo,
                             Repository<Course>& courseRepo)
{
    // SAVE USERS

    ofstream userFile(userFilePath);

    if (!userFile.is_open())
    {
        cout << "Error: Could not open user file."
             << endl;

        return;
    }

    vector<Person*> users = userRepo.getAll();

    for (Person* person : users)
    {
        if (person == nullptr)
            continue;

        string role;

        if (dynamic_cast<Student*>(person) != nullptr)
        {
            role = "STUDENT";
        }
        else if (dynamic_cast<Lecturer*>(person) != nullptr)
        {
            role = "LECTURER";
        }
        else if (dynamic_cast<Administrator*>(person) != nullptr)
        {
            role = "ADMIN";
        }
        else
        {
            continue;
        }

        userFile
            << role << "|"
            << person->getID() << "|"
            << person->getName() << "|"
            << person->getEmail() << "|"
            << person->getPassword()
            << endl;
    }

    userFile.close();

    cout << "Users saved successfully." << endl;


    // SAVE COURSES

    ofstream courseFile(courseFilePath);

    if (!courseFile.is_open())
    {
        cout << "Error: Could not open course file."
             << endl;

        return;
    }

    vector<Course*> courses = courseRepo.getAll();

    for (Course* course : courses)
    {
        if (course == nullptr)
            continue;

        string type;
        string prerequisite;


        if (Lecture* lecture =
                dynamic_cast<Lecture*>(course))
        {
            type = "LECTURE";
            prerequisite =
                lecture->getPrerequisites();
        }
        else if (Lab* lab =
                     dynamic_cast<Lab*>(course))
        {
            type = "LAB";
            prerequisite =
                lab->getPrerequisites();
        }
        else if (Project* project =
                     dynamic_cast<Project*>(course))
        {
            type = "PROJECT";
            prerequisite =
                project->getPrerequisites();
        }
        else
        {
            continue;
        }

        string lecturerId = "NONE";

        if (course->getAssignedLecturer() != nullptr)
        {
            lecturerId =
                course->getAssignedLecturer()->getID();
        }


        courseFile
            << type << "|"
            << course->getCode() << "|"
            << course->getTitle() << "|"
            << course->getCreditValue() << "|"
            << course->getCapacity() << "|"
            << lecturerId << "|"
            << prerequisite
            << endl;
    }

    courseFile.close();

    cout << "Courses saved successfully." << endl;
}