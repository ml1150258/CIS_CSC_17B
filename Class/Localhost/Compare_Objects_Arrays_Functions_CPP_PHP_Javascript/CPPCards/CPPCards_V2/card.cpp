/*
 * Author:      Dr. Mark E. Lehr
 * Date  :      September 4th, 2020
 * Purpose:     Card Class implementation comparison
 * 
 */

#include "card.h"
#include <sstream>
using namespace std;

Card::Card(int number){
    if(number>=MINCRDS&&number<MAXCRDS){
        this->number=number;
        setFace();
        setSuit();
        setName();
        setPict();
    }else{
        this->number=-1;
        this->faceVal=-1;
        this->suit="none";
        this->name="none";
        this->picture="none";
    }
}

void Card::setFace(){
    int num=this->number%13+1;
    if(num>10)num=10;
    else if(num==1)num=11;
    if(num>=2&&num<=11)this->faceVal=num;
    else this->faceVal=-2;
}

void Card::setSuit(){
    if(this->number<13)     this->suit="Spades";
    else if(this->number<26)this->suit="Diamonds";
    else if(this->number<39)this->suit="Clubs";
    else if(this->number<52)this->suit="Hearts";
    else                   this->suit="Bad Value";
}
            
void Card::setName(){
    switch(this->number%13){
        case 0:  this->name="Ace";  break;
        case 1:  this->name="Two";  break;
        case 2:  this->name="Three";break;
        case 3:  this->name="Four"; break;
        case 4:  this->name="Five"; break;
        case 5:  this->name="Six";  break;
        case 6:  this->name="Seven";break;
        case 7:  this->name="Eight";break;
        case 8:  this->name="Nine"; break;
        case 9:  this->name="Ten";  break;
        case 10: this->name="Jack"; break;
        case 11: this->name="Queen";break;
        case 12: this->name="King"; break;
        default: this->name="Bad Value";
    }
}
            
void Card::setPict(){
    this->picture="cards/"+this->name+this->suit+".jpg";
}
   
string Card::toString(){
    ostringstream cnvNum,cnvFace;
    cnvNum  << this->number;
    cnvFace << this->faceVal;
    string str="\n";
    str+=("<img src="+this->picture+" />");
    str+=("\nNumber = "+cnvNum.str());
    str+=("\nName = "+this->name);
    str+=("\nSuit = "+this->suit);
    str+=("\nFace Value = "+cnvFace.str());
    str+=("\n \n");
    return str;
}