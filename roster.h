/*
 * Project:    Roster 
 * File:       roster.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "Student.h"

using namespace std;

const int numStudents = 5;

// required data
 const string studentData[numStudents] =
 {
 "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
 "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
 "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
 "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
 "A5,Parker,Christy,lchr107@my.wgu.edu,29,14,22,16,SOFTWARE"
 };  
 
class Roster{
public:
    int lastIndex;
    int capacity;
    Student** rosterArray;
    Roster();
    Roster(int capacity);
    void add(string datarow);
    void print_All();
    bool remove(string id);
    void printAvgDays(string id);
    void printInvalidEmails();
    void printDegree(Degree d);
    ~Roster();
};


#endif /* ROSTER_H */

