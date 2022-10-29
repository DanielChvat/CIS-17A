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
//Global Constants

//Mathematical/Physics/Conversions/Higher Dimensioned Arrays
const unsigned char PERCENT=100;
//Function Prototypes
int CrdVal(vector <int>,const int);
Player *init();
void stats(Player *, File *);
void genCrds(fstream &, fstream &, const int);
void wrtBin(Stats, File *);
Stats *readBin(File *);
void filCrd(Card, const int);
void filSut(Card, const int);
bool hasWon(int, int, int limit=21);
string getCard(char *, int);
string getSuit(char *, int);
int getVal(char *, int, int);
void destroy(File *, Card, Player *, Stats *);
//Execution begins here
enum Face {
    Ace   = 1,
    Two   = 2,
    Three = 3,
    Four  = 4,
    Five  = 5,
    Six   = 6,
    Seven = 7,
    Eight = 8,
    Nine  = 9,
    Ten   = 10,
    Queen = 10,
    King  = 10,
    Jack  = 10,
    lAce  = 11

};
int main(){
    //Initialize the Random Number Seed
    srand(static_cast<unsigned int>(time(0)));
    //Declare Variables
    File *file = new File;
    Player *player = init();
    Game game;
    
    vector<int> pVals(player->card.NCARDS);
    //Initialize Variables
    game.crntIdx=0;
    file->fileNm1="Cards.dat";
    file->fileNm2="Suits.dat";
    file->fileNm3="Stats.dat";
    file->cards.open(file->fileNm1,ios::out);
    file->suits.open(file->fileNm2,ios::out);
    file->stats.open(file->fileNm3, ios::in|ios::out|ios::binary|ios::trunc);
    //Map Inputs to Outputs
    //Generate Random Deck of Cards with suits into two different files
    genCrds(file->cards, file->suits, player->card.NCARDS);
    file->cards.close();
    file->suits.close();
    //Display Results
    //Game Play
    do{
        game.pVal=0;
        game.dVal=0;
        //crdwSut="";
        for(int i=0; i<player->card.NCARDS;i++){
            pVals[i]=0;
        }
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
            if(game.crntIdx<player->card.NCARDS){
                getline(file->cards,player->card.cardSel);
                //Fill Cards Array
                filCrd(player->card, player->card.NCARDS);
                getline(file->suits,player->card.suitSel);
                //Fill suits array
                filSut(player->card, player->card.NCARDS);
                //Fill cards and Suits Table to be printed later
                //Display a message of the card and its suit that the player recieved
                player->pCards[game.crntIdx]=getCard(player->card.crd, game.crntIdx);
                player->pSuits[game.crntIdx]=getSuit(player->card.cSut,game.crntIdx);
                //Calculate the current value of all the players cards         
                game.pVal=game.pVal=getVal(player->card.crd,game.crntIdx,game.pVal);
                pVals[game.crntIdx]=game.pVal;
                game.pVal=CrdVal(pVals,player->card.NCARDS);
                cout<<endl;
                cout<<"You Recieved: "<<player->pCards[game.crntIdx]<<" of "<<player->pSuits[game.crntIdx]<<endl;
                cout<<endl;
                cout<<"Your Cards Total Value is Currently: "<<game.pVal<<endl<<endl;
                game.crntIdx+=1;
            }else{
                cout<<"No cards left in deck to draw from";
                exit(0);
            }
            game.dVal+=rand()%11+1;
            cout<<"The Dealers Shown Card Value is: "<<game.dVal<<endl<<endl;
            cout<<"Would You Like to Hit (Y/N)"<<endl;
            cin>>player->hit;
            if(game.crntIdx<player->card.NCARDS){
                do{
                    if(player->hit=='Y'||player->hit=='y'){
                        if(game.crntIdx<player->card.NCARDS){
                            getline(file->cards,player->card.cardSel);
                            getline(file->suits,player->card.suitSel);
                            player->pCards[game.crntIdx]=getCard(player->card.crd, game.crntIdx);
                            player->pSuits[game.crntIdx]=getSuit(player->card.cSut,game.crntIdx);
                            //Calculate the current value of all the players cards         
                            game.pVal=getVal(player->card.crd,game.crntIdx,game.pVal);
                            pVals[game.crntIdx]=game.pVal;
                            game.pVal=CrdVal(pVals,player->card.NCARDS);
                            cout<<endl;
                            //Display Message to player saying the card they recieved their current total card value and the dealers show card value
                            cout<<"You Recieved: "<<player->pCards[game.crntIdx]<<" of "<<player->pSuits[game.crntIdx]<<endl;
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
                }while(game.crntIdx<player->card.NCARDS && (player->hit=='Y'||player->hit=='y'));
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
    stats(player, file);
    Stats *stats = readBin(file);
    //Ask Player if they want to see info about the game
    cout<<"Would You Like To See Some Info About The Game?(Y/N)"<<endl;
    cin>>game.info;
    if(game.info=='Y' || game.info=='y'){
        cout<<endl<<"Heres A List Of All The Cards That Were In The Deck With Their Suits"<<endl<<endl;
        cout<<"Card: ";
        for(int i=0; i<player->card.NCARDS;i++)cout<<stats->data[0][i];
        cout<<endl;
        cout<<"Suit: ";
        for(int i=0; i<player->card.NCARDS;i++)cout<<stats->data[1][i];
        cout<<endl<<endl;
    }else cout<<endl<<endl<<"Thanks For Playing "<<player->name<<"!"<<endl;
    //Close Files Correctly
    file->cards.close();
    file->suits.close();
    file->stats.close();
    //De-Allocate Memory
    destroy(file, player->card, player, stats);
    //Exit Stage Right
    return 0;
}
int CrdVal(vector<int> cards,const int NCARDS){
    int pVal=0;
    for(int i=0; i<NCARDS;i++){
        pVal+=cards[i];
    }
    return pVal;
}
void genCrds(fstream &cards, fstream &suits, const int NCARDS){
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
void filCrd(Card card, const int NCARDS){
    for(int i=0; i<NCARDS;i++){
        card.crd[i]=card.cardSel[i];
    }
}
void filSut(Card card, const int NCARDS){
    for(int i=0; i<NCARDS;i++){
        card.cSut[i]=card.suitSel[i];
    }
}
bool hasWon(int pVal, int dVal, int limit){
    if(pVal>dVal && pVal<=limit || (pVal<=21 && dVal>21))return true;
    else return false;
}
string getCard(char *cards, int index){
    string card;
    if(cards[index]=='A')card="Ace";
    if(cards[index]=='2')card="2";
    if(cards[index]=='3')card="3";
    if(cards[index]=='4')card="4";
    if(cards[index]=='5')card="5";
    if(cards[index]=='6')card="6";
    if(cards[index]=='7')card="7";
    if(cards[index]=='8')card="8";
    if(cards[index]=='9')card="9";
    if(cards[index]=='T')card="10";
    if(cards[index]=='Q')card="Queen";
    if(cards[index]=='K')card="King";
    if(cards[index]=='J')card="Jack";
    return card;
}
string getSuit(char *suits, int index){
    string suit;
    suit=suits[index]=='H'?"Hearts":
        suits[index]=='D'?"Diamonds":
        suits[index]=='C'?"Clubs":
        suits[index]=='S'?"Spades":"";
        return suit;
}
int getVal(char *cards, int index, int pVal){
    Face value;
    if(cards[index]=='A' && ((pVal+11)<=21))value=lAce;
    else value=Ace;
    value=cards[index]=='2'?Two:
    cards[index]=='3'?Three:
    cards[index]=='4'?Four:
    cards[index]=='5'?Five:
    cards[index]=='6'?Six:
    cards[index]=='7'?Seven:
    cards[index]=='8'?Eight:
    cards[index]=='9'?Nine:
    cards[index]=='T'?Ten:
    cards[index]=='Q'?Queen:
    cards[index]=='K'?King:
    cards[index]=='J'?Jack:value;
    return value;
}
//Get Initial Values for player structure
Player *init(){
    Player *player = new Player;
    player->pCards=new string[player->card.NCARDS];
    player->pSuits=new string[player->card.NCARDS];
    player->card.cSut = new char[player->card.NCARDS];
    player->card.crd = new char[player->card.NCARDS];
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
void stats(Player *p, File *f){
    Stats s;
    s.rows=2;
    s.cols=p->card.NCARDS;
    //Row 1 is Cards
    //Row 2 is Suits
    for(int i=0; i<s.cols; i++){
        s.data[0][i]=p->card.crd[i];
        s.data[1][i]=p->card.cSut[i];
    }
    wrtBin(s, f);

}

void wrtBin(Stats s, File *f){
    f->stats.write(&s.rows, sizeof(char));
    f->stats.write(&s.cols, sizeof(char));
    for(int i=0; i<s.cols; i++)f->stats.write(&s.data[0][i], sizeof(char));
    for(int i=0; i<s.cols; i++)f->stats.write(&s.data[1][i], sizeof(char));
}
Stats *readBin(File *f){
    Stats *s = new Stats;
    long cursor=0L;
    f->stats.seekg(cursor, ios::beg);
    f->stats.read(&s->rows, sizeof(char));
    f->stats.read(&s->cols, sizeof(char));
    for(int i=0; i<s->cols; i++)f->stats.read(&s->data[0][i], sizeof(char));
    for(int i=0; i<s->cols; i++)f->stats.read(&s->data[1][i], sizeof(char));
    return s;
}
//De-Allocate Memory
void destroy(File *file, Card card, Player *player, Stats *stats){
    delete []player->pCards;
    delete []player->pSuits;
    delete []player->name;
    delete []card.crd;
    delete []card.cSut;
    delete file;
    delete player;
    delete stats;

}