/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Bank.h
 * Author: Daniel
 *
 * Created on October 18, 2022, 2:55 PM
 */

#ifndef BANK_H
#define BANK_H

struct Bank {
    string acNum; //Account Number
    string name; //Name of Account Holder
    string address; //Address of Account Holder
    float bal; //Balance of Account
    float nBal; //New Balance of the Account after checks and deposits
    short nChecks; //Number of Checks written for the month
    float *chkAmt; //All the checks written for the month
    short nDep; //Number of Deposits for the month
    float *depAmt; //All the deposits made this month
};

#endif /* BANK_H */

