/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Stats.h
 * Author: Daniel
 *
 * Created on October 27, 2022, 3:40 PM
 */
#include <fstream>

#ifndef STATS_H
#define STATS_H

struct Stats{
    char rows; //Number of Rows in 2d Array
    char cols; //Number of Cols in 2d Array
    char data[2][52]; //2D Array containing Cards and Suits
};
#endif /* STATS_H */
