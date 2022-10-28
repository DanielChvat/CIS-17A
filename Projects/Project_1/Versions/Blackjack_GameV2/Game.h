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
};

#endif /* GAME_H */
