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

//Global Constants not Variables
//Math/Physics/Science/Conversions/Dimensions

//Function Prototypes
void encrypt(char [], const int);
void decrypt(char [], const int);
char map(char);
void verify(char [], const int);
//Code Begins Execution Here with function main
int main(int argc, char** argv) {
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
    else cout<<"Invalid Input"<<endl;
    //Display the results
    return 0;
}
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
        cout<<"Error: Can't Read in Numbers Individally! All Digits must be read with one cin statement!"<<endl;
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
