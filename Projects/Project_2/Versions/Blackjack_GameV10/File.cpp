/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "File.h"

//Default Constructor
File::File(){
    file = new fstream;
    name = "";
}

//Constructor
File::File(string n){
    name = n;
    file = new fstream;
}