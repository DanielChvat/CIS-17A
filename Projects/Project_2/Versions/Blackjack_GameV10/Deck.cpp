/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Deck.h"
#include "MyVctr.h"

Deck::Deck(){
    Card::genCrds();
    cVals.resize(52);
    for(int i=0; i<Card::NCARDS; i++){
        cVals[i]=Card::getVal(i);
    }
}

