/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   AbsPlayer.h
 * Author: Daniel
 *
 * Created on December 15, 2022, 7:05 PM
 */

#ifndef ABSPLAYER_H
#define ABSPLAYER_H

class AbsPlayer{
public:
    virtual void setName(char *)=0;
    virtual void setWin(bool)=0;
    virtual void setAgn(char)=0;
    virtual void setHit(char)=0;
    virtual void setMny(float)=0;
    virtual void setSMny(float)=0;
    virtual void setBet(float)=0;
    virtual void init()=0;
    virtual float getPCL()=0;
    virtual float getPCW()=0;
    virtual char *getName()=0;
    virtual bool getWin()=0;
    virtual char getAgn()=0;
    virtual char getHit()=0;
    virtual float getMny()=0;
    virtual float getSMny()=0;
    virtual float getBet()=0;
    virtual int getNMS() const=0; 
    virtual char getPrc() const=0;
    virtual void mkBet()=0;
};

#endif /* ABSPLAYER_H */

