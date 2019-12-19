/*
 * Project:    Roster
 * File:       softwareStudent.cpp
 * Programmer: Parker Christy
 * ID:         #001141715
 */


#include <iostream>
#include "softwareStudent.h"

using namespace std;

SoftwareStudent::SoftwareStudent(){
    
    setDegree(SOFTWARE);
}

SoftwareStudent::SoftwareStudent(string id, string first, string last, string email, int a, int* num_days, Degree degree){
	
    setDegree(SOFTWARE);
}

Degree SoftwareStudent::getDegree(){
    
    return SOFTWARE;
}

void SoftwareStudent::setDegree(Degree d){
    
    this->degree = SOFTWARE;
}

void SoftwareStudent::print(){
    
    this->Student::print();
    cout << "SOFTWARE" << endl;
}

SoftwareStudent::~SoftwareStudent(){
    
    Student::~Student();
    delete this;
}
