/*
 * Project:    Roster 
 * File:       securityStudent.cpp
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#include <iostream>
#include "securityStudent.h"


using namespace std;

SecurityStudent::SecurityStudent(){
    
    setDegree(SECURITY);
}

SecurityStudent::SecurityStudent(string id, string first, string last, string email, int a, int* num_days, Degree degree){

    setDegree(SECURITY);
}

Degree SecurityStudent::getDegree(){
    
    return SECURITY;
}

void SecurityStudent::setDegree(Degree d){
    
    this->degree = SECURITY;
}

void SecurityStudent::print(){
    
    this->Student::print();
    cout << "SECURITY" << endl;
}

SecurityStudent::~SecurityStudent(){
    
    Student::~Student();
    delete this;
}