/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   Card.h
 * Author: Daniel
 *
 * Created on December 15, 2022, 1:37 PM
 */

#ifndef CARD_H
#define CARD_H
#include <string>
#include <fstream>
using namespace std;
class Card{
protected:
    char *crd;
    char *cSut;
    string cardSel,//Card at a specific index in Cards.dat
           suitSel;//Suit at a specific index in Suits.dat
    const int NCARDS=52;//Number of Cards In the Deck
public:
    Card();
    ~Card();
    char ACrd(const int i){return crd[i];}
    char ACSut(const int i){return cSut[i];}
    string getCSel(){return cardSel;}
    string getSSel(){return suitSel;}
    char *getCrd(){return crd;}
    char *getSut(){return cSut;}
    void setCSel(const string c){cardSel=c;}
    void setSSel(const string s){suitSel=s;}
    void setCrd(const int i, const char n){crd[i]=n;}
    void setCSut(const int i, const char n){cSut[i]=n;}
    int getNCrd() const {return NCARDS;} 
    void fillCrd();
    void fillSut();
    string trnslte(bool, const int i);
    void genCrds(fstream &, fstream &);
    int getVal(const int);
};

#endif /* CARD_H */

