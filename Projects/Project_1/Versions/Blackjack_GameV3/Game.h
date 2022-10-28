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


#ifndef GAME_H
#define GAME_H

struct File{
    string fileNm1,//Name of the file being used the store the cards
           fileNm2;//Name of the file being used to store the suits of each card
};

struct Card{
    char *crd;
    char *cSut;
    string cardSel,//Card at a specific index in Cards.dat
           suitSel;//Suit at a specific index in Suits.dat
};

struct Player{
    string *pCards;
    string *pSuits;
    char   *name;
    const int NMSIZE=81;
    bool win; //If the player has won or lost
};
#endif /* GAME_H */
