/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on September 4, 2020, 6:08 PM
 * Purpose:  To compare C++, Javascript and PHP arrays, objects and functions
 */

//System Libraries
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//User Libraries
#include "card.h"

//Global Constants, physical, mathematical, conversions only

//Function Prototypes
Card **filDeck(int);                //Fill a deck of cards
int   *filIndx(int);                //Fill an index to the deck
void   prntDek(Card **,int *,int);  //Print the deck with an index
void   shuffle(int *,int);          //Shuffle the deck

//Execution Begins Here
int main(int argc, char** argv) {   
    //Set the random number seed
    srand(static_cast<unsigned int>(time(0)));
    
    //Declare variables
    int    nCards=52;
    int  *index;
    Card **deck;
  
    //Initialize the data
    deck=filDeck(nCards);
    index=filIndx(nCards);
    
    //Print the Deck before randomization
    cout<<"Before a Deck Shuffle"<<endl;
    prntDek(deck,index,nCards);
    
    //Shuffle the deck
    shuffle(index,nCards);
    
    //Print the Deck after randomization
    cout<<"After a Deck Shuffle"<<endl;
    prntDek(deck,index,nCards);
    
    //Clean up memory allocation
    for(int i=0;i<nCards;i++){
        delete deck[i];
    }
    delete []deck;
    delete []index;

    //Exit program stage right
    return 0;
}

void   shuffle(int *indx,int n){
    for(int nMix=1;nMix<7;nMix++){
        for(int swap=0;swap<n;swap++){
            int rnSwp=rand()%n;
            int temp=indx[swap];
            indx[swap]=indx[rnSwp];
            indx[rnSwp]=temp;
        }
    } 
}

void   prntDek(Card **deck,int *indx,int n){
    for(int i=0;i<n;i++){
        cout<<deck[indx[i]]->toString();
    }
}

int   *filIndx(int n){
    int *indx=new int[n];
    for(int i=0;i<n;i++){
        indx[i]=i;
    }
    return indx;
}

Card **filDeck(int n){
    Card **deck=new Card*[n];
    for(int i=0;i<n;i++){
        deck[i]=new Card(i);
    }
    return deck;
}