/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Player.h"
#include "iostream"
using namespace std;
//Default Constructor
Player::Player(){
    name = new char[NMSIZE];
    init();
}

//Copy Constructor
Player::Player(const Player &p){
    name=p.name;
    win=p.win;
    again=p.again;
    hit=p.hit;
    money=p.money;
    strtMny=p.strtMny;
    bet=p.bet;
    prcChng=p.prcChng;
}

//Destructor
Player::~Player(){
    //delete []name;
}

//Mutator Functions
void Player::setName(char *n){
    name=n;
}

void Player::setWin(bool w){
    win=w;
}

void Player::setAgn(char a){
    again=a;
}

void Player::setHit(char h){
    hit=h;
}

void Player::setMny(float m){
    money=m;
}

void Player::setSMny(float s){
    strtMny=s;
}

void Player::setBet(float b){
    bet=b;
}

void Player::mkBet(){
    money-=bet;
}

void Player::init(){
    win=false;
    again='\0';
    hit='\0';
    money=0;
    strtMny=0;
    bet=0;
    prcChng=0;
    cout<<"What is Your Name"<<endl;
    cin.getline(name, NMSIZE);
    
    //Ask Player to input amount of money they wish to play with
    cout<<"Blackjack Card Game"<<endl;
    cout<<"Input the Amount of Money in Dollars You Wish to Play With"<<endl;
    cin>>money;
    strtMny=money;
    
    //Ensure the player is not entering negative amounts of money
    while(money<0){
        cout<<money<<" Is Not a Valid Amount of Money"<<endl;
        cout<<"Input the Amount of Money You Wish to Play With"<<endl;
        cin>>money;
        strtMny=money;
    }
}

//Accessor Functions
float Player::getPCW(){
        money=money +(bet/2)*3;
        prcChng=money/strtMny*PERCENT;
        strtMny=money;
        return prcChng;
}

float Player::getPCL(){
    money-=bet;
    prcChng=money/strtMny*PERCENT;
    strtMny=money;
    return prcChng;
}


char *Player::getName(){
    return name;
}

bool Player::getWin(){
    return win;
}

char Player::getAgn(){
    return again;
}

char Player::getHit(){
    return hit;
}

float Player::getMny(){
    return money;
}

float Player::getSMny(){
    return strtMny;
}

float Player::getBet(){
    return bet;
}

int Player::getNMS() const {
    return NMSIZE;
}

char Player::getPrc() const{
    return PERCENT;
}

//Static Members
char Player::PERCENT=100;
const int Player::NMSIZE = 81;