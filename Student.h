/* 
 * Project:    Roster
 * File:       Student.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"

using namespace std;

class Student
{
protected:
    string studentID;
    string firstName;
    string lastName;
    string emailAddress;
    int age;
    int* num_days; 
    Degree degree; // network, software, or security
	
public:
    const static int num_days_size = 3;
    // Constructors
    Student();
    Student(
        string id, 
        string first, 
        string last, 
        string email, 
        int a, 
        int num_days[], 
        Degree degree);

    // Getters
    string getStudentID();
    string getFirstName();
    string getLastName();
    string getEmailAddress();
    int getAge();
    int* getNumDays();
    virtual Degree getDegree() = 0;

    // Setters
    void setStudentID(string id);
    void setFirstName(string first);
    void setLastName(string last);
    void setEmailAddress(string email);
    void setAge(int a);
    void setNumDays(int num_days[]);
    virtual void setDegree(Degree d) = 0;
    virtual void print() = 0;
	
    // Destructor
    ~Student();
	
};

#endif /* STUDENT_H */

