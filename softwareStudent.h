/*
 * Project:    Roster
 * File:       softwareStudent.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#ifndef SOFTWARESTUDENT_H
#define SOFTWARESTUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
#include "Student.h"

using namespace std;

class SoftwareStudent : public Student{
public:
    SoftwareStudent();
    SoftwareStudent(
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
    ~SoftwareStudent();
};


#endif /* SOFTWARESTUDENT_H */

