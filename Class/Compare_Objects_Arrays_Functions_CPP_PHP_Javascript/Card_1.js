/*
 * Author:      Dr. Mark E. Lehr
 * Date  :      September 4th, 2019
 * Purpose:     Show a card class written in Javascript
 * 
 */

//Constructor for the Card class
var MAXCRDS=52;
var MINCRDS=0;

function Card(number){
    //Public properties of the class
    if(number>=MINCRDS&&number<MAXCRDS){
        this.number=number;
        this.setFace();
        this.setSuit();
        this.setName();
        this.setPict();
    }else{
        this.number=-1;
        this.faceVal=-1;
        this.suit="none";
        this.name="none";
        this.picture="none";
    }
}
//Setting the Face Value
Card.prototype.setFace=function(){
    var num=this.number%13+1;
    if(num>10)num=10;
    else if(num==1)num=11;
    if(num>=2&&num<=11)this.faceVal=num;
    else this.faceVal=-2;
};
//Setting the Suit Value
Card.prototype.setSuit=function(){
    if(this.number<13)     this.suit="Spades";
    else if(this.number<26)this.suit="Diamonds";
    else if(this.number<39)this.suit="Clubs";
    else if(this.number<52)this.suit="Hearts";
    else                   this.suit="Bad Value";
};
//Determine the Face Name
Card.prototype.setName=function(){
    switch(this.number%13){
        case 0:  this.name="Ace";  break;
        case 1:  this.name="Two";  break;
        case 2:  this.name="Three";break;
        case 3:  this.name="Four"; break;
        case 4:  this.name="Five"; break;
        case 5:  this.name="Six";  break;
        case 6:  this.name="Seven";break;
        case 7:  this.name="Eight";break;
        case 8:  this.name="Nine"; break;
        case 9:  this.name="Ten";  break;
        case 10: this.name="Jack"; break;
        case 11: this.name="Queen";break;
        case 12: this.name="King"; break;
        default: this.name="Bad Value";
    }
};

//Simply setting the picture
Card.prototype.setPict=function(){
    this.picture="Cards/"+this.name+this.suit+".jpg";
};

//To String function of the Card Class
Card.prototype.toString=function(){
    document.write("<img src="+this.picture+" />");
    document.write("<br/>Number = "+this.number);
    document.write("<br/>Name = "+this.name);
    document.write("<br/>Suit = "+this.suit);
    document.write("<br/>Face Value = "+this.faceVal);
    document.write("<br/><br/>");
};


/*
 * Test code used to check out the above class Code
 * 
 * 
//Create a deck of 52 cards
	var card=new Array(52);
	for(var i=0;i<52;i++){
		card[i]=new Card(i);
	}
//Shuffle the cards
//First create an indexed array
	var idx=new Array(52);
	for(var i=0;i<idx.length;i++){
		idx[i]=i;
	}
//Now mix up the indexed array
	for(var i=0;i<idx.length;i++){
		var temp=Math.random()*51;
		temp=temp.toFixed(0);
		temp=parseInt(temp);
		//Swap positions
		var val=idx[i];
		idx[i]=idx[temp];
		idx[temp]=val;
	}

//Print out the shuffled deck
	document.write("The shuffled Deck <br />");
	for(var i=0;i<idx.length;i++){
		card[idx[i]].toString();
	}
*/