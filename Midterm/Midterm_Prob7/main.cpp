/* 
 * File:   main.cpp
 * Author: Daniel Chvat
 * Created on June 21, 2021, 11:19 AM
 * Purpose:  Develop a Template to be copied
 *           for all future programs
 */

//System Libraries
#include <iostream>   //Input/Output Library
#include <vector>
using namespace std;  //STD Name-space where Library is compiled

//User Libraries
#include "Primes.h"
//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
Primes *factor(int);
void prntPrm(Primes *);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
    //Set random number seed once here
    
    //Declare variables here
    int n=0;
    //Initialize variables here
    cout<<"Which Number Would You Like to Factorize?"<<endl;
    cin>>n;
    Primes *p = factor(n);
    //Map inputs to outputs here, i.e. the process
    //Display the results
    cout<<n<<" = ";
    prntPrm(p);
    delete []p->prime;
    delete p;
    return 0;
}
Primes *factor(int n){
    Primes *p = new Primes;
    int c=2;
    short count=0;
    vector<unsigned short> a;
    while(n>1){
        if(n%c==0){
            n/=c;
            a.push_back(c);
            count++;
        }else c++;
    } 
    p->prime=new Prime [count];
    int index=0;
    for(int i=0; i<count; i++){
        unsigned char power = '1';
        for(int j=0; j<count;j++){
            if(a[i]==a[j] && i!=j){
                power++;
                i++;
            }
        }
        p->prime[index].power=power;
        p->prime[index].prime=a[i];
        index++;
        p->nPrimes=index;
    }



    return p;
}
void prntPrm(Primes *p){
    for(int i=0; i<p->nPrimes; i++){
        cout<<p->prime[i].prime<<"^";
        if(i<(p->nPrimes-1))cout<<static_cast<char>(p->prime[i].power)<<" x ";
        else cout<<static_cast<char>(p->prime[i].power)<<"";
    }
}