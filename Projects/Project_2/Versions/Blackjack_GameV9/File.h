/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   File.h
 * Author: Daniel
 *
 * Created on December 16, 2022, 1:42 PM
 */

#ifndef FILE_H
#define FILE_H
#include <string>
#include <fstream>
using namespace std; 
class File{
private:
    string name;
    fstream *file;
public:
    //Default Constructor
    File();
    
    //Constructor
    File(string);
    
    //Destructor
    ~File(){delete file;}
    
    //Mutator Functions
    void setName(string n ){name=n;}
    
    //Accessor Functions
    fstream *getFile(){return file;}
    string getName(){return name;}
    
    
};

#endif /* FILE_H */

