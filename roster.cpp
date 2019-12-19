/*
 * Project:    Roster 
 * File:       roster.cpp
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#include <iostream>
#include <string>
#include "roster.h"
#include "Student.h"
#include "networkStudent.h"
#include "securityStudent.h"
#include "softwareStudent.h"
#include "degree.h"


using namespace std;

// empty constructor
Roster::Roster(){   
    
    this->capacity = 0;
    this->lastIndex = -1;
    this->rosterArray = nullptr;
    
}

// max capacity for roster
Roster::Roster(int capacity){
    
    this->capacity = capacity;
    this->lastIndex = -1;
    this->rosterArray = new Student*[capacity];
        
}

void Roster::add(string row){
    
    if (lastIndex < capacity){
        lastIndex++;
        int numDaysArray[Student::num_days_size];
	
        if (row.substr(row.length()-8, 8) == "SOFTWARE"){
            this->rosterArray[lastIndex] = new SoftwareStudent();
            rosterArray[lastIndex]->setDegree(SOFTWARE);
	}
		
	else if (row.substr(row.length() - 7, 7) == "NETWORK"){
            this->rosterArray[lastIndex] = new NetworkStudent();
            rosterArray[lastIndex]->setDegree(NETWORK);
	}

        else if (row.substr(row.length() - 8, 8) == "SECURITY"){
            this->rosterArray[lastIndex] = new SecurityStudent();
            rosterArray[lastIndex]->setDegree(SECURITY);
	}
	
	// Set ID
	int rhs = studentData[lastIndex].find(",");
	rosterArray[lastIndex]->setStudentID(studentData[lastIndex].substr(0, rhs));

	// Set first name
	int lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	rosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

	// Set last name
	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	rosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

	// Set email
	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	rosterArray[lastIndex]->setEmailAddress(studentData[lastIndex].substr(lhs, rhs - lhs));

	// Set age
	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	rosterArray[lastIndex]->setAge(stoi(studentData[lastIndex].substr(lhs, rhs - lhs)));

	// Set days to complete courses
	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	numDaysArray[0] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	numDaysArray[1] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData[lastIndex].find(",", lhs);
	numDaysArray[2] = stoi(studentData[lastIndex].substr(lhs, rhs - lhs));

	rosterArray[lastIndex]->setNumDays(numDaysArray);
    }
}

// travel through array and print each one
void Roster::print_All(){
    
    for (int i = 0; i <= this->lastIndex; i++){
        (this->rosterArray)[i]->print();
    }
}
// remove the requested ID, then tells you if it worked or not
bool Roster::remove(string id){

    for (int i = 0; i <= lastIndex; ++i){
	if (rosterArray[i] == nullptr){
            cout << "Student " << id << " not found" << endl;
            break;
	}
	else if (id == rosterArray[i]->getStudentID()){
            rosterArray[i] = nullptr;
            cout << "Student removed" << endl;
	}
    }
    
}

void Roster::printAvgDays(string id){
	
    bool found = false;
    
    for (int i = 0; i <= lastIndex; ++i){
        // student found
	if (this->rosterArray[i]->getStudentID() == id){
            found = true;
            int* days = rosterArray[i]->getNumDays();
            cout << "Average number of days for ID " << id << " is " << (days[0] + days[1] + days[2]) / 3 << endl;
	}
    }
}

void Roster::printInvalidEmails(){
    
    for (int i = 0; i <= lastIndex; ++i){
        
	string email = rosterArray[i]->getEmailAddress();
        
	if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)){
            cout << "The email for " << rosterArray[i]->getFirstName() << " " << rosterArray[i]->getLastName() << " is not valid: " << email << endl;
        }
    }
}

void Roster::printDegree(Degree d){
    
    string degreeTypeString;
    cout << "Student Roster by Degree: " << degreeTypeString[d] << endl;
    
    for (int i = 0; i <= lastIndex; ++i){
        
	if (this->rosterArray[i]->getDegree() == d){
            this->rosterArray[i]->print();
        }
    }
}

// destroys all student data
Roster::~Roster(){
    
    for (int i = 0; i < numStudents; i++){
            
	delete this->rosterArray[i];
    }
    
    delete this;
}

// where the magic happens
int main(){
    
    // make the roster
    Roster* classRoster = new Roster(numStudents);
        
    for (int i = 0; i < numStudents; ++i){
	
        classRoster->add(studentData[i]);
    }
    
    // required heading
    cout << "\nSCRIPTING AND PROGRAMMING APPLICATIONS — C867" << endl;
    cout << "---------------------C++---------------------" << endl;
    cout << "------------------001141715------------------" << endl;
    cout << "---------------PARKER CHRISTY----------------" << endl;
    
    // print the roster
    cout << "\nRoster\n" << endl;
    classRoster->print_All();
    cout << endl;
    
    // calc and display average days per class for each student
    cout << "Average days per class for each student" << endl;
    for (int i = 0; i < numStudents; ++i){
	classRoster->printAvgDays(classRoster->rosterArray[i]->getStudentID());
    }	
    cout << endl;
    
    // print any invalid email entries
    cout << "Invalid Emails" << endl;
    classRoster->printInvalidEmails();
    cout << endl;
    
    // print Software majors
    classRoster->printDegree(SOFTWARE);
    cout << endl;
    // remove A3
    classRoster->remove("A3");
    cout << endl;
    // try to remove it again, inevitably get error msg
    classRoster->remove("A3");
    cout << endl;
    
    return 0;
}

