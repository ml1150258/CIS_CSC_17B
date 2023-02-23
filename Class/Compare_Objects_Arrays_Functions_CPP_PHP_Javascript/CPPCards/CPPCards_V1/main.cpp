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

//Execution Begins Here
int main(int argc, char** argv) {   
    //Test the Cards by creating a deck then printing the result
    int nCards=52;
    Card **deck=new Card*[nCards];
    for(int i=0;i<nCards;i++){
        deck[i]=new Card(i);
        cout<<deck[i]->toString();
    }
    
    //Clean up memory allocation
    for(int i=0;i<nCards;i++){
        delete deck[i];
    }
    delete []deck;

    //Exit program stage right
    return 0;
}