/*
*File: main.cpp
*Author: Daniel Chvat
*Created on October 22 2022, 1:37 PM
*Purpose: Blackjack Card Game
*/

//System Libraries
#include <iostream> //Input Output Library
#include <ctime>    //Time Library
#include <string>   //String Library
#include <cmath>    //Math Library
#include <cstdlib>  //C Standard Library
#include <iomanip>  //Formatting Library
#include <fstream>  //File Input Output Library
#include <vector>   //Vector Library
using namespace std;
//User Libraries
#include "Game.h"
#include "Card.h"
#include "MyVctr.h"
#include "Face.h"
//Global Constants

//Mathematical/Physics/Conversions/Higher Dimensioned Arrays
const unsigned char PERCENT=100;
//Function Prototypes
int CrdVal(MyVctr<int>,const int);
Player *init();
void stats(File *, const int, const char *, const char *);
void wrtBin(Stats, File *);
Stats *readBin(File *);
bool hasWon(int, int, int limit=21);
string getSuit(char *, int);
void destroy(File *,Player *, Stats *);
//Execution begins here
int main(){
    srand((unsigned)time(NULL));
    //Declare Variables
    File *file = new File;
    Card card;
    Player *player = init();
    Game game;
    
    MyVctr<int> pVals(card.getNCrd());
    //Initialize Variables
    game.crntIdx=0;
    file->fileNm1="Cards.dat";
    file->fileNm2="Suits.dat";
    file->fileNm3="Stats.dat";
    file->cards.open(file->fileNm1,ios::in|ios::out);
    file->suits.open(file->fileNm2,ios::in|ios::out);
    file->stats.open(file->fileNm3, ios::in|ios::out|ios::binary|ios::trunc);
    string temp;
    getline(file->cards,temp);
    cout<<temp<<endl;
    card.setCSel(temp);
    //Fill Card Array
    card.fillCrd();
    getline(file->suits,temp);
    card.setSSel(temp);
    //Fill Suits Array
    card.fillSut();
    //Map Inputs to Outputs
    card.genCrds(file->cards, file->suits);
    file->cards.close();
    file->suits.close();
    file->stats.close();
    
    //Precalculate all the card values in the vector
    for(int i=0; i<card.getNCrd(); i++){
        pVals[i]=card.getVal(i);
        cout<<pVals[i]<<" ";
    }
    //Game Play
    do{
        game.pVal=0;
        game.dVal=0;
        //Open the Cards.dat and Suits.dat files to be read and used later on in the game
        file->cards.open(file->fileNm1,ios::in);
        file->suits.open(file->fileNm2,ios::in);
        cout<<endl;
        cout<<"You Currently Have "<<fixed<<setprecision(2)<<player->money<<" Dollars Left!"<<endl;
        //Ensure player has more than 0 Dollars Left
        if(player->money>0){
            cout<<"How Much Would You Like to Bet on This Game?"<<endl;
            cin>>player->bet; 
            //Check if the bet is valid
            while(player->bet>player->money || player->bet<0){
                cout<<"That Bet is Not Valid!"<<endl;
                cout<<"Please Enter How Much You Wish to Bet:"<<endl;
                cin>>player->bet;
            }
            //Grab a card from the cards file to start the player with
            if(game.crntIdx<card.getNCrd()){
                //Fill cards and Suits Table to be printed later
                //Display a message of the card and its suit that the player received
                //Calculate the current value of all the players cards         
                cout<<endl;
                game.pVal=CrdVal(pVals,game.crntIdx);
                cout<<"You Received: "<<card.trnslte(true,game.crntIdx)<<" of "<<card.trnslte(false, game.crntIdx)<<endl;
                cout<<endl;
                cout<<"Your Cards Total Value is Currently: "<<game.pVal<<endl<<endl;
                ++game.crntIdx;
            }else{
                cout<<"No cards left in deck to draw from";
                exit(0);
            }
            game.dVal+=rand()%11+1;
            cout<<"The Dealers Shown Card Value is: "<<game.dVal<<endl<<endl;
            cout<<"Would You Like to Hit (Y/N)"<<endl;
            cin>>player->hit;
            if(game.crntIdx<card.getNCrd()){
                do{
                    if(player->hit=='Y'||player->hit=='y'){
                        if(game.crntIdx<card.getNCrd()){
                            //Calculate the current value of all the players cards         
                            cout<<endl;
                            game.pVal=CrdVal(pVals,game.crntIdx);
                            //Display Message to player saying the card they recieved their current total card value and the dealers show card value
                            cout<<"You Recieved: "<<card.trnslte(true, game.crntIdx)<<" of "<<card.trnslte(false, game.crntIdx)<<endl;
                            cout<<endl;
                            cout<<"Your Cards Total Value is Currently: "<<game.pVal<<endl<<endl;
                            cout<<"The Dealers Shown Card Value is: "<<game.dVal<<endl<<endl;
                            game.crntIdx+=1;
                        }else{
                            //Tell the player there are no cards left in the deck and exit program
                            cout<<"No cards left in deck to draw from";
                            exit(0);
                        }
                        if(game.pVal<21){
                            cout<<"Would you like to hit (Y/N)"<<endl;
                            cin>>player->hit;
                        }else player->hit='N';
                    }
                }while(game.crntIdx<card.getNCrd() && (player->hit=='Y'||player->hit=='y'));
                //Increase dealers card value by a random value from 1 to 10 if their total card value is less than 17
                while(game.dVal<17)game.dVal+=rand()%11+1;
            }
             
            //Check if the player has won
            player->win=hasWon(game.pVal, game.dVal);
            cout<<endl<<endl<<"Results:"<<endl;
            if(player->win){
                //Pay out the bet at a 3:2 Ratio(found on blackjack.org) if the player has won
                player->money+=player->bet/2*3;
                player->prcChng=player->money/player->strtMny*PERCENT;
                player->strtMny=player->money;
                //Display message saying player won
                cout<<"Congratulations You Have Won :) "<<endl;
                cout<<"Your Total Card Value Was: "<<game.pVal<<endl;
                cout<<"The Dealer's Total Card Value Was: "<<game.dVal<<endl;
                cout<<"Your New Balance is $"<<player->money<<endl;
                cout<<"Your money increased by around "<<fixed<<setprecision(0)<<round(player->prcChng)<<"%"<<endl;
            }else if(game.pVal==game.dVal ||(game.pVal>21 && game.dVal>21)){
                //Display a message saying nobody won
                cout<<"The Dealer's Total Card Value Was: "<<game.dVal<<endl;
                cout<<"Nobody Wins"<<endl;
            }else{
                player->money-=player->bet;
                player->prcChng=player->money/player->strtMny*PERCENT;
                player->strtMny=player->money;
                cout<<endl;
                //Display message saying player lost
                cout<<"Sorry You Lost :( "<<endl;
                cout<<"Your Total Card Value Was: "<<game.pVal<<endl;
                cout<<"The Dealer's Total Card Value Was: "<<game.dVal<<endl;
                cout<<"Your New Balance is "<<fixed<<setprecision(2)<<player->money<<endl;
                //Display how much player's money decreased and round to the nearest Value
                cout<<"Your money decreased by around "<<fixed<<setprecision(0)<<round(PERCENT-player->prcChng)<<"%"<<endl;
            }
        }
        if(player->money>0){
            cout<<"Would you like to play again?(Y/N)"<<endl;
            cin>>player->again;
            
        }
    }while(player->money>0 && (player->again=='Y'||player->again=='y'));
    //Write Game Stats into file
    //Close Files Correctly
    file->cards.close();
    file->suits.close();
    file->stats.close();
    stats(file, card.getNCrd(), card.getCrd(), card.getSut());
    Stats *stats = readBin(file);
    //Ask Player if they want to see info about the game
    cout<<"Would You Like To See Some Info About The Game?(Y/N)"<<endl;
    cin>>game.info;
    if(game.info=='Y' || game.info=='y'){
        cout<<endl<<"Heres A List Of All The Cards That Were In The Deck With Their Suits"<<endl<<endl;
        cout<<"Card: ";
        for(int i=0; i<card.getNCrd();i++)cout<<stats->data[0][i];
        cout<<endl;
        cout<<"Suit: ";
        for(int i=0; i<card.getNCrd();i++)cout<<stats->data[1][i];
        cout<<endl<<endl;
    }else cout<<endl<<endl<<"Thanks For Playing "<<player->name<<"!"<<endl;
    //De-Allocate Memory
    for(int i=0; i<52; i++)cout<<pVals[i]<<" ";
    destroy(file, player, stats);
    //Exit Stage Right
    return 0;
}
int CrdVal(MyVctr<int> cards,const int index){
    int value = 0;
    for(int i=0; i<index+1; i++){
        value+=cards[i];
        cout<<"Value: "<<value<<endl;
    }
    return value;
}
bool hasWon(int pVal, int dVal, int limit){
    if(pVal>dVal && pVal<=limit || (pVal<=21 && dVal>21))return true;
    else return false;
}
//Get Initial Values for player structure
Player *init(){
    Player *player = new Player;
    player->bet=0;
    player->money=0;
    //Create Oversized Array to hold Players Name
    player->name=new char[player->NMSIZE];
    cout<<"What is Your Name"<<endl;
    cin.getline(player->name, player->NMSIZE);
    //Ask Player to input amount of money they wish to play with
    cout<<"Blackjack Card Game"<<endl;
    cout<<"Input the Amount of Money in Dollars You Wish to Play With"<<endl;
    cin>>player->money;
    player->strtMny=player->money;
    //Ensure the player is not entering negative amounts of money
    while(player->money<0){
        cout<<player->money<<" Is Not a Valid Amount of Money"<<endl;
        cout<<"Input the Amount of Money You Wish to Play With"<<endl;
        cin>>player->money;
        player->strtMny=player->money;
    }
    return player;
}
void stats(File *f, const int NCARDS, const char *a, const char *b){
    Stats s;
    s.rows=2;
    s.cols=NCARDS;
    //Row 1 is Cards
    //Row 2 is Suits
    for(int i=0; i<s.cols; i++){
        s.data[0][i]=a[i];
        s.data[1][i]=b[i];
    }
    wrtBin(s, f);

}

void wrtBin(Stats s, File *f){
    f->stats.open(f->fileNm3,ios::out|ios::binary);
    f->stats.write(&s.rows, sizeof(char));
    f->stats.write(&s.cols, sizeof(char));
    for(int i=0; i<s.cols; i++)f->stats.write(&s.data[0][i], sizeof(char));
    for(int i=0; i<s.cols; i++)f->stats.write(&s.data[1][i], sizeof(char));
    f->stats.close();
}
Stats *readBin(File *f){
    Stats *s = new Stats;
    long cursor=0L;
    f->stats.open(f->fileNm3,ios::in|ios::binary);
    f->stats.seekg(cursor, ios::beg);
    f->stats.read(&s->rows, sizeof(char));
    f->stats.read(&s->cols, sizeof(char));
    for(int i=0; i<s->cols; i++)f->stats.read(&s->data[0][i], sizeof(char));
    for(int i=0; i<s->cols; i++)f->stats.read(&s->data[1][i], sizeof(char));
    return s;
    f->stats.close();
}
//De-Allocate Memory
void destroy(File *file,Player *player, Stats *stats){
    delete []player->name;
    delete file;
    delete player;
    delete stats;

}