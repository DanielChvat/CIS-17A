/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MyVctr.h
 * Author: Daniel
 *
 * Created on December 15, 2022, 4:04 PM
 */

#ifndef MYVCTR_H
#define MYVCTR_H

#include <iostream>
#include <new>
#include <cstdlib>
using namespace std;
template <class T>
class MyVctr{
    private:
        T *aptr; //To point to the allocated array
        int aSize; //Number of elements in the array
        void mError(); //Handles Memory Allocation Errors
        void sError(); //Handles Subscripts out of range
    public:
        //Default Constructor
        MyVctr()
        {aptr=0; aSize=0;}
        //Constructor Declaration
        MyVctr(const int);
       
        
        //Destructor declaration
        //~MyVctr();
        
        //Accessor to return the array Size
        int size()
        {return aSize;}
        
        //Accessor to return a specific element
        T get(int);
        
        //Overloaded [] operator declaration
        T &operator[] (const int &);
        
        //Push Function
        void push_back(T);
        void pop_back();
};

template <class T>
MyVctr<T>::MyVctr(const int s){
    aSize=s;
    
    //Allocate Memory
    try{
        aptr=new T[s];
    }
    catch (bad_alloc){
        mError();
    }
    
    //Initialize the Array
    for(int i=0; i<aSize; i++)aptr[i]=0;
}

//template <class T>
//MyVctr<T>::~MyVctr(){
//    if(aSize>0)delete []aptr;
//}

template <class T>
void MyVctr<T>::mError(){
    cout<<"ERROR: Cannot allocate Memory!"<<endl;
    exit(EXIT_FAILURE);
}

template <class T>
void MyVctr<T>::sError(){
    cout<< "ERROR: Subscript out of range!"<<endl;
    exit(EXIT_FAILURE);
}

template <class T>
T MyVctr<T>::get(int sub){
    if(sub<0 || sub>=aSize)sError();
    return aptr[sub];
}

template <class T>
T &MyVctr<T>::operator [](const int &sub){
    if(sub<0 || sub>=aSize)sError();
    return aptr[sub];
}

template <class T>
void MyVctr<T>::push_back(T data){
    T *temp = aptr;
    ++aSize;
    delete []aptr;
    aptr=new T[aSize];
    for(int i=0; i<aSize-1; i++)aptr[i]=temp[i];
    aptr[aSize-1]=data;
    
}
template <class T>
void MyVctr<T>::pop_back(){
    T *temp = aptr;
    --aSize;
    delete []aptr;
    aptr=new T[aSize];
    for(int i=0; i<aSize; i++)aptr[i]=temp[i];
}

#endif /* MYVCTR_H */

