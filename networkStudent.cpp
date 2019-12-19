/*
 * Project:    Roster 
 * File:       networkStudent.h
 * Programmer: Parker Christy
 * ID:         #001141715
 */

#include <iostream>
#include "networkStudent.h"

using namespace std;

NetworkStudent::NetworkStudent(){
    
    setDegree(NETWORK);
}

NetworkStudent::NetworkStudent(string id, string first, string last, string email, int a, int* num_days, Degree degree){
    
    setDegree(NETWORK);
}

Degree NetworkStudent::getDegree(){
    
    return NETWORK;
}

void NetworkStudent::setDegree(Degree d){
    
    this->degree = NETWORK;
}

void NetworkStudent::print(){
    
    this->Student::print();
    cout << "NETWORK" << endl;
}

NetworkStudent::~NetworkStudent(){
        
    Student::~Student();
    delete this;
}