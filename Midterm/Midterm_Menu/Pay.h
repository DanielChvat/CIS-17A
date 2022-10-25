/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Pay.H
 * Author: Daniel
 *
 * Created on October 19, 2022, 10:42 AM
 */

#ifndef PAY_H
#define PAY_H

struct Emplee{ //Employee Structure
    string name; //Name of the Employee Being entered
    short hrs; //Hours Employees have worked
    float payRate; //Pay rate for employee
    float payChck; //Amount to be paid for the employee
};
struct Company{
    string name; //Name of the Company
    string address; //Address of the company;
    short nEmploy; //Number of people employed whos data is being entered
    Emplee *emplee; //Array of employees information
};


#endif /* PAY_H */
