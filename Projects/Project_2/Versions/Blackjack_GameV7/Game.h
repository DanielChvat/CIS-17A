/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Game.h
 * Author: Daniel
 *
 * Created on October 27, 2022, 3:40 PM
 */
#include <fstream>

#ifndef GAME_H
#define GAME_H

struct File{
    string fileNm1,//Name of the file being used the store the cards
           fileNm2,//Name of the file being used to store the suits of each card
           fileNm3;//Name of the file being used to store stats about the game
    fstream cards,//Cards File
            suits,//Suits File
            stats;//Stats File
};

struct Player{
    string *pCards;
    string *pSuits;
    char   *name;
    const int NMSIZE=81;
    bool win; //If the player has won or lost
    char again,//If the player wishes to play again
         hit; //If the player wishes to hit or stay
    float money,//How much money the player currently has
          strtMny, //How much money the player started with
          bet,//How much money the player is willing to bet on a game
          prcChng;//The % change in the players money after the end of a game
};

struct Game{
    int pVal,//Current Value of Players Cards
        dVal,//Current Value of Dealers Cards
        crntIdx;//Current Index being used in the file
    char info;
};
struct Stats{
    char rows; //Number of Rows in 2d Array
    char cols; //Number of Cols in 2d Array
    char data[2][52]; //2D Array containing Cards and Suits
};
#endif /* GAME_H */
