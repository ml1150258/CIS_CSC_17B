/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on November 12th, 2020, 10:30 AM
 * Purpose:  Player Class Specification
 */


#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

#include "Hand.h"

class Player{
    private:
        string name;
        Hand *hand;
       
    public:
        Player(string);
        void setHand(Hand *);
        string getName(){return name;}
        void prntHnd();
};


#endif /* PLAYER_H */

