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
           fileNm2;//Name of the file being used to store the suits of each card
    fstream cards,suits;
};

struct Card{
    char *crd;
    char *cSut;
    string cardSel,//Card at a specific index in Cards.dat
           suitSel;//Suit at a specific index in Suits.dat
    const int NCARDS=52;//Number of Cards In the Deck
};

struct Player{
    string *pCards;
    string *pSuits;
    char   *name;
    const int NMSIZE=81;
    bool win; //If the player has won or lost
    Card card;
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
};
#endif /* GAME_H */
