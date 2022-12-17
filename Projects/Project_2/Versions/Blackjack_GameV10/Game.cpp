/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Game.h"
#include "MyVctr.h"
#include <string>
using namespace std;
Game::Game(){
    pVal=0;
    dVal=0;
    crntIdx=0;
    info='\0';
}

int Game::getCVal(MyVctr<int> &cards, const int prvVal){
    int value=0;
    for(int i=0; i<crntIdx+1;i++){
        value+=cards[i];
    }
    return value-prvVal;
}

void Game::operator++(){
    if(crntIdx+1 > 52){
        string error = "Sorry We Ran Out Of Cards";
        throw error; 
    }
    else ++crntIdx;
}