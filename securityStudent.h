/*
 * Project:    Roster 
 * File:       securityStudent.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#ifndef SECURITYSTUDENT_H
#define SECURITYSTUDENT_H

#include <iostream>
#include <string>
#include "degree.h"
#include "Student.h"

using namespace std;

class SecurityStudent : public Student{
public:
    SecurityStudent();
    SecurityStudent(
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
    ~SecurityStudent();
};


#endif /* SECURITYSTUDENT_H */

