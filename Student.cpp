/* 
 * Project:     Roster
 * File:        Student.cpp
 * Programmer:  Parker Christy
 * ID:          #001141715
 */

#include <iostream>
#include <iomanip>
#include "Student.h"
#include "degree.h"

using namespace std;

// Empty Constructor
Student::Student(){
    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->num_days = new int[num_days_size];
    for (int i = 0; i < num_days_size; ++i){
        this->num_days[i] = 0;
        }
	
}
// Constructor
Student::Student(string id, string first, string last, string email, int a, int num_days[], Degree degree){
    this->studentID = id;
    this->firstName = first;
    this->lastName = last; 
    this->emailAddress = email;
    this->age = a;
    this->num_days = new int[num_days_size];
    for (int i = 0; i < 3; ++i){
        this->num_days[i] = num_days[i];
        }

}

// Getters
string Student::getStudentID()
{
    return studentID;
}
string Student::getFirstName()
{
    return firstName;
}
string Student::getLastName()
{
    return lastName;
}
string Student::getEmailAddress()
{
    return emailAddress;
}
int Student::getAge()
{
    return age;
}
int* Student::getNumDays()
{
    return num_days;
}

// Setters
void Student::setStudentID(string id)
{
    this->studentID = id;
}
void Student::setFirstName(string first)
{
    this->firstName = first;
}
void Student::setLastName(string last)
{
    this->lastName = last;
}
void Student::setEmailAddress(string email)
{
    this->emailAddress = email;
}
void Student::setAge(int a)
{
    this->age = a;
}
void Student::setNumDays(int num_days[])
{
    if (this->num_days != nullptr){
	delete[] this->num_days;
	this->num_days = nullptr;
	}
    this->num_days = new int[num_days_size];
    for (int i = 0; i < 3; ++i){
	this->num_days[i] = num_days[i];
	}
}

void Student::print()
{
    // Using getters to print student data
    cout << getStudentID() << endl;
    cout << "First name: " << getFirstName() << "\t";
    cout << "Last name: " << getLastName() << "\t";
    cout << "Age: " << getAge() << "\t";
    int* days = getNumDays();
    cout << "Days in course: {" << *days << " " << *(days + 1) << " " << *(days + 2) << "}\t";
}

// Destructor
Student::~Student(){
    if (num_days != nullptr){
	delete[] num_days;
	num_days = nullptr;
	}
}

