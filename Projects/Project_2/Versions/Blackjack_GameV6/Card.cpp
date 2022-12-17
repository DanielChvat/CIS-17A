/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Card.h"
#include "Face.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
using namespace std;
Card::Card(){
    crd=new char[NCARDS];
    cSut=new char[NCARDS];
}

Card::~Card(){
    delete []crd;
    delete []cSut;
}

void Card::fillCrd(){
    for(int i=0; i<NCARDS; i++){
        crd[i]=cardSel[i];
    }
}

void Card::fillSut(){
    for(int i=0; i<NCARDS; i++){
        cSut[i]=suitSel[i];
    }
}

string Card::trnslte(bool c, const int i){
    if(c){
        string card;
        if(crd[i]=='A')card="Ace";
        if(crd[i]=='2')card="2";
        if(crd[i]=='3')card="3";
        if(crd[i]=='4')card="4";
        if(crd[i]=='5')card="5";
        if(crd[i]=='6')card="6";
        if(crd[i]=='7')card="7";
        if(crd[i]=='8')card="8";
        if(crd[i]=='9')card="9";
        if(crd[i]=='T')card="10";
        if(crd[i]=='Q')card="Queen";
        if(crd[i]=='K')card="King";
        if(crd[i]=='J')card="Jack";
        return card;
    }else{
        string suit;
        suit=cSut[i]=='H'?"Hearts":
        cSut[i]=='D'?"Diamonds":
        cSut[i]=='C'?"Clubs":
        cSut[i]=='S'?"Spades":"";
        return suit;
    }
}
void Card::genCrds(fstream &cards, fstream &suits){
    srand((unsigned)time(NULL));
    cout<<rand()<<endl;
    for(unsigned char card=0; card<NCARDS;card++){
        int cardVal=rand()%13+1;
        //Check to see if the random number generated matches a specific number if it does write down that card into the Cards.dat file
        switch(cardVal){
            case 1:{
                cards<<"A";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 2:{
                cards<<"2";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 3:{
                cards<<"3";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 4:{
                cards<<"4";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 5:{
                cards<<"5";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 6:{
                cards<<"6";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 7:{
                cards<<"7";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 8:{
                cards<<"8";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 9:{
                cards<<"9";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 10:{
                cards<<"T";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 11:{
                cards<<"K";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 12:{
                cards<<"Q";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
            case 13:{
                cards<<"J";
                unsigned char suit=rand()%4+1;
                if(suit==1)suits<<"H";
                else if(suit==2)suits<<"D";
                else if(suit==3)suits<<"C";
                else suits<<"S";
            break;}
        }
    }
}

int Card::getVal(const int index){
    Face value;
    value=crd[index]=='A'?Face::Ace:
    crd[index]=='2'?Face::Two:
    crd[index]=='3'?Face::Three:
    crd[index]=='4'?Face::Four:
    crd[index]=='5'?Face::Five:
    crd[index]=='6'?Face::Six:
    crd[index]=='7'?Face::Seven:
    crd[index]=='8'?Face::Eight:
    crd[index]=='9'?Face::Nine:
    crd[index]=='T'?Face::Ten:
    crd[index]=='Q'?Face::Queen:
    crd[index]=='K'?Face::King:
    crd[index]=='J'?Face::Jack:value;
    return (int)value;
}