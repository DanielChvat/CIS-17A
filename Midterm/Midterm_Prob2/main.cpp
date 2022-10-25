/* 
 * File:   main.cpp
 * Author: Daniel Chvat
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <iomanip>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Pay.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void input(Company *);
void print(Company *);
string english(int);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    Company *c = new Company;
    //Initialize variables here
    cout<<"What Is The Name Of The Company?"<<endl;
    getline(cin, c->name);
    cout<<"What Is The Address Of The Company?"<<endl;
    getline(cin, c->address);
    cout<<"How Many Employees Are Being Inputted?"<<endl;
    cin>>c->nEmploy;

    //Create the employees array
    c->emplee=new Emplee[c->nEmploy];

    //Input the employee info into the array
    input(c);
    //Map inputs to outputs here, i.e. the process
    //Display the results
    print(c);
    delete []c->emplee;
    delete c;
    return 0;
}
void input(Company *c){
    for(int i=0; i<c->nEmploy; i++){
        //Get Name, Hours Worked, and Pay Rate for each employee
        cout<<"Employee "<<i+1<<endl;
        cout<<"----------------"<<endl;
        cout<<"Name: ";
        cin.ignore();
        getline(cin, c->emplee[i].name);
        cout<<endl;
        cout<<"Hours Worked: ";
        cin>>c->emplee[i].hrs;
        while(c->emplee[i].hrs<0){
            cout<<"That Is Not Not A Valid Number Of Hours!"<<endl;
            cout<<"Hours Worked: ";
            cin>>c->emplee[i].hrs;
        }
        cout<<endl;
        cout<<"Pay Rate $/hr: ";
        cin>> c->emplee[i].payRate;
        while(c->emplee[i].payRate<0){
            cout<<"That Is Not Not A Valid Pay Rate!"<<endl;
            cout<<"Pay Rate $/hr: ";
            cin>> c->emplee[i].payRate;
        }
        cout<<endl;

        //Calculate Each Employees Pay Rate
        if(c->emplee[i].hrs<=20)
            c->emplee[i].payChck=c->emplee[i].hrs*c->emplee[i].payRate;
        else if (c->emplee[i].hrs>20 && c->emplee[i].hrs<=40)
            c->emplee[i].payChck=(c->emplee[i].hrs-20)*2*c->emplee[i].payRate + (20*c->emplee[i].payRate);
        else if (c->emplee[i].hrs>40)
            c->emplee[i].payChck=(c->emplee[i].hrs-40)*3*c->emplee[i].payRate + (20*2*c->emplee[i].payRate) + (20*c->emplee[i].payRate);
    }
}
string english(int n){
    char n1000s,n100s,n10s,n1s;
    string text;
    n1000s=n/1000;
    n100s=n%1000/100;
    n10s=n%100/10;
    n1s=n%10;

    switch(n1000s){
        case 1:text+="One Thousand "; break;
        case 2:text+="Two Thousand "; break;
        case 3:text+="Three Thousand "; break;
        case 4:text+="Four Thousand ";break;
        case 5:text+="Five Thousand ";break;
        case 6:text+="Six Thousand ";break;
        case 7:text+="Seven Thousand ";break;
        case 8:text+="Eight Thousand ";break;
        case 9:text+="Nine Thousand ";break;
    }
    switch(n100s){
        case 1:text+="One Hundred "; break;
        case 2:text+="Two Hundred "; break;
        case 3:text+="Three Hundred "; break;
        case 4:text+="Four Hundred "; break;
        case 5:text+="Five Hundred "; break;
        case 6:text+="Six Hundred "; break;
        case 7:text+="Seven Hundred "; break;
        case 8:text+="Eight Hundred "; break;
        case 9:text+="Nine Hundred "; break;
    }
    switch(n10s){
        case 2:text+="Twenty "; break;
        case 3:text+="Thirty "; break;
        case 4:text+="Forty "; break;
        case 5:text+="Fifty "; break;
        case 6:text+="Sixty "; break;
        case 7:text+="Seventy "; break;
        case 8:text+="Eighty "; break;
        case 9:text+="Ninety "; break;
    }
    if(n10s==1 && n1s==0)text+="Ten ";
    else if(n10s==1 &&n1s==1)text+="Eleven ";
    else if(n10s==1 &&n1s==2)text+="Twelve ";
    else if(n10s==1 &&n1s==3)text+="Thirteen ";
    else if(n10s==1 &&n1s==4)text+="Fourteen ";
    else if(n10s==1 &&n1s==5)text+="Fifteen ";
    else if(n10s==1 &&n1s==6)text+="Sixteen ";
    else if(n10s==1 &&n1s==7)text+="Seventeen ";
    else if(n10s==1 &&n1s==8)text+="Eighteen ";
    else if(n10s==1 &&n1s==9)text+="Nineteen ";
    
    if((n10s>1||n10s==0) && n1s==1)text+="One ";
    else if((n10s>1||n10s==0) &&n1s==2)text+="Two ";
    else if((n10s>1||n10s==0) &&n1s==3)text+="Three ";
    else if((n10s>1||n10s==0) &&n1s==4)text+="Four ";
    else if((n10s>1||n10s==0) &&n1s==5)text+="Five ";
    else if((n10s>1||n10s==0) &&n1s==6)text+="Six ";
    else if((n10s>1||n10s==0) &&n1s==7)text+="Seven ";
    else if((n10s>1||n10s==0) &&n1s==8)text+="Eight ";
    else if((n10s>1||n10s==0) &&n1s==9)text+="Nine ";

    return text;
}
void print(Company *c){
        for(int i=0; i<c->nEmploy; i++){
        cout<<endl;
        cout<<c->name<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
        cout<<"Address: "<<c->address<<endl;
        cout<<"Name: "<<left<<setw(46)<<c->emplee[i].name<<"$"<<static_cast<int>(c->emplee[i].payChck);
        if(c->emplee[i].payChck-static_cast<int>(c->emplee[i].payChck)==0)cout<<" 00/100"<<endl;
        else cout<<" "<<setprecision(2)<<(c->emplee[i].payChck-static_cast<int>(c->emplee[i].payChck))*100<<"/100"<<endl;
        cout<<"Amount: "<<left<<setw(48)<<english(static_cast<int>(c->emplee[i].payChck));
        if(c->emplee[i].payChck-static_cast<int>(c->emplee[i].payChck)==0)cout<<" 00/100"<<endl;
        else cout<<" "<<setprecision(2)<<(c->emplee[i].payChck-static_cast<int>(c->emplee[i].payChck))*100<<"/100"<<endl;
        cout<<endl<<endl;
        cout<<"---------------------------"<<endl;
        cout<<"         Signature     "<<endl;
        cout<<"---------------------------------------------------------------"<<endl;
    }
}