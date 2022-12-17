/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Deck.h
 * Author: Daniel
 *
 * Created on December 16, 2022, 4:05 PM
 */

#ifndef DECK_H
#define DECK_H
#include "Card.h"
#include "MyVctr.h"
class Deck:public Card{
    private:
        MyVctr<int> cVals;
    public:
        Deck();
        MyVctr<int> &getVec(){return cVals;}
        int getVec(const int i){return cVals[i];} 
};

#endif /* DECK_H */

