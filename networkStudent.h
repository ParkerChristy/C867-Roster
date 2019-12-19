/*
 * Project:    Roster 
 * File:       networkStudent.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#ifndef NETWORKSTUDENT_H
#define NETWORKSTUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
#include "Student.h"

using namespace std;

class NetworkStudent : public Student{
public:
    NetworkStudent();
    NetworkStudent(
        string id, 
        string first, 
        string last, 
        string email, 
        int a, 
        int* num_days, 
        Degree degree);
    Degree getDegree();
    void setDegree(Degree d);
    void print();
    ~NetworkStudent();
};


#endif /* NETWORKSTUDENT_H */

