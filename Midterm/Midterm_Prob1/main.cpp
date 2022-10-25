/* 
 * File:   main.cpp
 * Author: Daniel Chvat
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs
 */

//System Libraries
#include <iostream>   //Input/Output Library
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Bank.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
Bank *input(); //Get Input from Account Holder
void fillAry(float *, short, string);
void calc(Bank *);
void destroy(Bank *);
void print (Bank *);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    Bank *account=input();
    //Initialize variables here
    account->chkAmt=new float[account->nChecks];
    account->depAmt=new float[account->nDep];
    fillAry(account->chkAmt, account->nChecks, "Check");
    fillAry(account->depAmt, account->nDep, "Deposit");
    //Map inputs to outputs here, i.e. the process
    calc(account);
    //Display the results
    print(account);
    destroy(account);
    return 0;
}
Bank *input(){//Get Input from Account Holder
    Bank *a = new Bank;
    cout<<"Please Enter Your 5 Digit Account Number:";
    cin>>a->acNum;
    while(a->acNum.length()>5 || a->acNum.length()<5){
        cout<<"Account Number Must Be 5 Digits"<<endl;
        cout<<"Please Enter Your 5 Digit Account Number:";
        cin>>a->acNum;
    }
    cout<<endl<<"Please Enter Your Name:";
    cin.ignore();
    getline(cin, a->name);
    cout<<endl<<"Please Enter Your Address:";
    getline(cin, a->address);
    cout<<endl<<"Please Enter Your Balance At The Beginning Of The Month:$";
    cin>>a->bal;
    cout<<endl<<"Please Enter The Number of Checks You Wrote This Month:";
    cin>>a->nChecks;
    cout<<endl<<"Please Enter The Number of Deposits You Made This Month:";
    cin>>a->nDep;
    cout<<endl;
    return a;
    delete a;
}
void print (Bank *account){
    cout<<"Account Info"<<endl;
    cout<<"-----------------"<<endl;
    cout<<"Number             : "<<account->acNum<<endl;
    cout<<"Name               : "<<account->name<<endl;
    cout<<"Address            : "<<account->address<<endl;
    cout<<"Starting Balance   : $"<<account->bal<<endl;
    if(account->nBal<0){
        cout<<endl<<"Account Overdrawn (An Additional 35 Dollar Fee Has Been Applied)"<<endl;
        cout<<"----------------------------------------------------------------"<<endl;
        cout<<"Account New Balance Before Fee = $"<<account->bal+account->nBal<<endl;
        cout<<"Account Balance After Fee = $"<<account->bal+account->nBal-35<<endl;
    }else cout<<"Account New Balance: $"<<account->nBal<<endl;
    cout<<endl<<"Checks"<<endl;
    cout<<"-----------------"<<endl;
    for(int i=0; i<account->nChecks; i++){
        cout<<"Check "<<i+1<<": $"<<account->chkAmt[i]<<endl;
    }
    cout<<endl<<"Deposits"<<endl;
    cout<<"-----------------"<<endl;
    for(int i=0; i<account->nDep; i++){
        cout<<"Deposit "<<i+1<<": $"<<account->depAmt[i]<<endl;
    }
}
void destroy(Bank *account){
    delete []account->chkAmt;
    delete []account->depAmt;
    delete account;
}
void fillAry(float *a, short size, string type){
    for(int i=0; i<size; i++){
        cout<<type<<" "<<i+1<<" Amount: $";
        cin>>a[i];
        cout<<endl;
    }
}
void calc(Bank *a){
    float chkSum=0;
    float depSum=0;
    //Get Total Amount for all deposits
    for(int i=0; i<a->nDep; i++){
        depSum+=a->depAmt[i];
    }
    //Get Total Amount for all Checks Written
    for(int i=0; i<a->nChecks; i++){
        chkSum+=a->chkAmt[i];
    }
    a->nBal=a->bal+depSum-chkSum;
}