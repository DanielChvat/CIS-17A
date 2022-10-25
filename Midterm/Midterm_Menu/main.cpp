/* 
 * File:   main.cpp
 * Author: Dr Mark E. Lehr
 * Purpose:  Menu using Functions,
 *           extend for midterm
 */

//System Libraries
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
using namespace std;

//User Libraries
#include "Bank.h"
#include "Pay.h"
#include "Primes.h"
//Global Constants - Math/Physics Constants, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void menu();
void prblm1();
void prblm2();
void prblm3();
void prblm4();
void prblm5();
void prblm6();
void prblm7();


//Problem 1
Bank *input(); //Get Input from Account Holder
void fillAry(float *, short, string);
void calc(Bank *);
void destroy(Bank *);
void print(Bank *);

//Problem 2
void input(Company *);
void print(Company *);
string english(int);

//Problem 4
void encrypt(char [], const int);
void decrypt(char [], const int);
char map(char);
void verify(char [], const int);

//Problem 7
Primes *factor(int);
void prntPrm(Primes *);
//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    char choice;
    
    //Loop and Display menu
    do{
        menu();
        cin>>choice;

        //Process/Map inputs to outputs
        switch(choice){
            case '1':{prblm1();break;}
            case '2':{prblm2();break;}
            case '3':{prblm3();break;}
            case '4':{prblm4();break;}
            case '5':{prblm5();break;}
            case '6':{prblm6();break;}
            case '7':{prblm7();break;}
            default: cout<<"Exiting Menu"<<endl;
        }
    }while(choice>='1'&&choice<='7');
    
    //Exit stage right!
    return 0;
}

void menu(){
    //Display menu
    cout<<endl<<"Choose from the following Menu"<<endl;
    cout<<"Type 1 for Problem 1"<<endl;
    cout<<"Type 2 for Problem 2"<<endl;
    cout<<"Type 3 for Problem 3"<<endl;   
    cout<<"Type 4 for Problem 4"<<endl;
    cout<<"Type 5 for Problem 5"<<endl;
    cout<<"Type 6 for Problem 6"<<endl;
    cout<<"Type 7 for Problem 7"<<endl<<endl;
}

void prblm1(){
    //Set random number seed once here
    
    //Declare variables here
    Bank *account=input();
    //Initialize variables here
    if(account->nChecks>0){
        account->chkAmt=new float[account->nChecks];
        fillAry(account->chkAmt, account->nChecks, "Check");
    }

    if(account->nDep>0){
        account->depAmt=new float[account->nDep];
        fillAry(account->depAmt, account->nDep, "Deposit");
    }

    if(account->nChecks==0 && account->nDep==0)account->nBal=account->bal;

    
    //Map inputs to outputs here, i.e. the process
    if(account->bal!=account->nBal)calc(account);
    //Display the results
    print(account);
    cout<<account->bal<<account->nBal<<endl;
    destroy(account);
}
void prblm2(){
    Company *c = new Company;
    //Initialize variables here
    cout<<"What Is The Name Of The Company?"<<endl;
    cin.ignore();
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
}
void prblm3(){
    cout<<"Included in another project!"<<endl;
}
void prblm4(){
    //Set random number seed once here
    
    //Declare variables here
    const int SIZE = 4;
    char data[SIZE] = {'\0'};
    char choice;
    //Initialize variables here
    cout<<"Would you like to encrypt or decrypt? (E for Encrypt|D for Decrypt)"<<endl;
    cin>>choice;
    //Map inputs to outputs here, i.e. the process
    if(choice == 'E' ||choice == 'e')encrypt(data, SIZE);
    else if(choice == 'D' ||choice == 'd')decrypt(data, SIZE);
    else{
        cout<<"Invalid Input"<<endl;
        exit(1);
    }
}
void prblm5(){
    cout<<"5A) Largest n! which can be stored in 1 byte variable is 5!|n=5"<<endl;
    cout<<"5B) Other Data Types"<<endl;
    cout<<"--------------------"<<endl;
    cout<<"Largest n! which can be stored in signed char variable       :  5!|n=5"<<endl;
    cout<<"Largest n! which can be stored in unsigned char variable     :  5!|n=5"<<endl;
    cout<<"Largest n! which can be stored in signed short variable      :  7!|n=7"<<endl;
    cout<<"Largest n! which can be stored in unsigned short variable    :  8!|n=8"<<endl;
    cout<<"Largest n! which can be stored in signed int variable        : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in unsigned int variable      : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in signed long variable       : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in unsigned long variable     : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in signed long long variable  : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in unsigned long long variable: 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in float variable             : 12!|n=12"<<endl;
    cout<<"Largest n! which can be stored in double variable            : 12!|n=12"<<endl;
}
void prblm6(){
    cout<<"A)"<<endl;
    cout<<"49.1875"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: 31.3"<<endl;
    cout<<"Binary: 110001.0011"<<endl;
    cout<<"Octal: 61.14"<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 01100010011000000000000000000110"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: 62600006"<<endl<<endl;
    cout<<"3.07421875"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: 3.13"<<endl;
    cout<<"Binary: 11.00010011"<<endl;
    cout<<"Octal: 3.046"<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 01100010011000000000000000000010"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: 62600002"<<endl<<endl;
    cout<<"0.2"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: 0.3 Repeating 3"<<endl;
    cout<<"Binary: 0.0011 Repeating 0011"<<endl;
    cout<<"Octal: 0.1463 Repeating 1463"<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 00011001100110011001100100000000"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: 19999900"<<endl<<endl;
    
    cout<<"B)"<<endl;
    cout<<"-49.1875"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: -31.3 or by 16's complement Repeating F CE.D"<<endl;
    cout<<"Binary: -110001.0011 or by 2's complement Repeating 1 001110.1101"<<endl;
    cout<<"Octal: -61.14 or by 8's complement Repeating 7 16.64"<<endl<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 11100010011000000000000000000110"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: E2600006"<<endl<<endl;
    cout<<"-3.07421875"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: -3.13 or by 16's complement Repeating F C.ED"<<endl;
    cout<<"Binary: -11.00010011 or by 2's complement Repeating 1 00.11101101"<<endl;
    cout<<"Octal: -3.046 or by 8's complement Repeating 7 4.732"<<endl<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 11100010011000000000000000000010"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: E2600002"<<endl<<endl;
    cout<<"-0.2"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Hex: -0.3 Repeating 3 or by 16's complement Repeating F FC Repeating C"<<endl;
    cout<<"Binary: -0.0011 Repeating 0011 or by 2's complement Repeating 1 1.1100 Repeating 1100 + 1"<<endl;
    cout<<"Octal: -0.1463 Repeating 1463 or by 8's complement Repeating 7 7.6314 Repeating 6314"<<endl;
    cout<<"4 Byte NASA Float Representation Binary: 10011001100110011001100100000000"<<endl;
    cout<<"4 Byte NASA Float Representation Hex: 99999900"<<endl<<endl;
    
    cout<<"C)"<<endl;
    cout<<"Hex 4 Byte Float: 69999902"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Decimal: 3.3"<<endl<<endl;
    cout<<"Hex 4 Byte Float: 69999903"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Decimal: 6.6"<<endl<<endl;
    cout<<"Hex 4 Byte Float: 966667FF"<<endl;
    cout<<"-----------"<<endl;
    cout<<"Decimal: Not a Number NaN"<<endl;

}
void prblm7(){
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
}


//Problem 1
Bank *input(){//Get Input from Account Holder
    Bank *a = new Bank;
    a->bal=0;
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
    if(account->nChecks>0){
        cout<<endl<<"Checks"<<endl;
        cout<<"-----------------"<<endl;
        for(int i=0; i<account->nChecks; i++){
            cout<<"Check "<<i+1<<": $"<<account->chkAmt[i]<<endl;
        }
    }
    if(account->nDep>0){
        cout<<endl<<"Deposits"<<endl;
        cout<<"-----------------"<<endl;
        for(int i=0; i<account->nDep; i++){
            cout<<"Deposit "<<i+1<<": $"<<account->depAmt[i]<<endl;
        }
    }
}
void destroy(Bank *account){
    if(account->nChecks>0)delete []account->chkAmt;
    if(account->nDep>0)delete []account->depAmt;
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

//Problem 2
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

//Problem 4
void encrypt(char data[], const int SIZE){
    cout<<"Encrypting"<<endl;
    cout<<"------------"<<endl;
    cout<<"Enter The 4 Digit Numbers between 0 and 7 You Wish To Encrypt: ";
    cin>>data;
    verify(data, SIZE);
    //Add 6 to each character and mod by 8
    for(int i=0; i<SIZE;i++){
        data[i]=((data[i]-42)%8)+48;
    }
    //Swap first with third
    data[0]=data[0]^data[2];
    data[2]=data[0]^data[2];
    data[0]=data[0]^data[2];
    //Swap the second with the fourth
    data[1]=data[1]^data[3];
    data[3]=data[1]^data[3];
    data[1]=data[1]^data[3];
    cout<<endl<<"Encrypted Numbers: "<<data<<endl;
}
void verify(char data[], const int SIZE){
    bool error = false;
    for(int i=0; i<SIZE; i++){
        if(data[i]=='\0' || static_cast<int>(data[i])<48 || static_cast<int>(data[i])>55){
            error=true;
        }
    }
    if(error){
        cout<<"Error: Can't Read in Numbers Individually! All Digits must be read with one cin statement!"<<endl;
        exit(1);
    }
}
void decrypt(char data[], const int SIZE){
    cout<<"Decrypting"<<endl;
    cout<<"------------"<<endl;
    cout<<"Enter The 4 Digit Numbers between 0 and 7 You Wish To Decrypt: ";
    cin>>data;
    verify(data, SIZE);
    for(int i=0; i<SIZE; i++)data[i]=map(data[i]);
    //Swap first with third
    data[0]=data[0]^data[2];
    data[2]=data[0]^data[2];
    data[0]=data[0]^data[2];
    //Swap the second with the fourth
    data[1]=data[1]^data[3];
    data[3]=data[1]^data[3];
    data[1]=data[1]^data[3];
    cout<<"Decrypted Numbers: "<<data<<endl;

}
char map(char c){
    switch(c){
        case 54: return 48; break;
        case 55: return 49; break;
        case 48: return 50; break;
        case 49: return 51; break;
        case 50: return 52; break;
        case 51: return 53; break;
        case 52: return 54; break;
        case 53: return 55; break;
    }
}
//Problem 7
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
