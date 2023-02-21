/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on February 4, 2015, 10:57 AM
 */

//System Libraries
#include <iostream>
#include <ctime>
using namespace std;

//User Libraries

//Global Constants
const int COL=30;

//Function Prototypes
void filAray(char [][COL],int,char);
void prntAry(char [][COL],int);
void prntMap(char [][COL],int,char);
void inject(char [][COL],int,int,char);
void pause(int);
void gnrashn(char [][COL],char[][COL],int,char,char);
int  cntNbor(char [][COL],int,char,int,int);

//Execution Begins Here!
int main(int argc, char** argv) {
    //Declare the 2 Dimensional character array
    const int ROW=10;
    char array[ROW][COL]={};
    char brray[ROW][COL]={};
    int nGen=20;
    char d='*',nd='X';
    //Fill the array
    filAray(array,ROW,d);
    filAray(brray,ROW,d);
    //Print the array without the glider
    prntAry(array,ROW);
    //Inject the glider
    inject(array,1,10,nd);
    //Print the array with the glider
    prntAry(array,ROW);
    pause(1);
    //Game of life for generations stipulated
    for(int gen=1;gen<=nGen;gen++){
        //prntMap(array,ROW,'X');
        cout<<"Gen "<<gen<<endl;
        if(gen%2){
            gnrashn(array,brray,ROW,d,nd);
            prntAry(brray,ROW);
        }else{
            gnrashn(brray,array,ROW,d,nd);
            prntAry(array,ROW);
        }
        //prntMap(array,ROW,'X');
        pause(1);
    }
    //Exit the program
    return 0;
}

void gnrashn(char a[][COL],char b[][COL],int ROW,char d,char nd){
    for(int r=1;r<ROW-1;r++){
        for(int c=1;c<COL-1;c++){
            int nBr=cntNbor(a,ROW,nd,r,c);
            if(a[r][c]==nd&&nBr<=1)b[r][c]=d;
            else if(a[r][c]==nd&&(nBr==2||nBr==3))b[r][c]=nd;
            else if(a[r][c]==nd&&nBr>=4)b[r][c]=d;
            else if(a[r][c]==d&&nBr==3)b[r][c]=nd;
            else b[r][c]=a[r][c];
        }
    }
}

void prntMap(char a[][COL],int ROW,char nd){
    cout<<endl;
    for(int r=1;r<ROW-1;r++){
        cout<<" ";
        for(int c=1;c<COL-1;c++){
            int nBr=cntNbor(a,ROW,nd,r,c);
            cout<<nBr;
        }
        cout<<endl;
    }
}

int  cntNbor(char a[][COL],int ROW,char d,int r,int c){
    //Count your neighbors
    int count=0;
    //3 on Top
    if(a[r-1][c-1]== d)count++;
    if(a[r-1][c]  == d)count++;
    if(a[r-1][c+1]== d)count++;
    //2 in Middle
    if(a[r][c-1]  == d)count++;
    if(a[r][c+1]  == d)count++;
    //3 on Bottom
    if(a[r+1][c-1]== d)count++;
    if(a[r+1][c]  == d)count++;
    if(a[r+1][c+1]== d)count++;
    //Return the count
    return count;
}

void pause(int secs){
    //Start the timer
    int strt=static_cast<unsigned int>(time(0));
    int end;
    do{
        end=static_cast<unsigned int>(time(0));
    }while(secs>(end-strt));
}

void inject(char a[][COL],int pRow,int pCol,char c){
    a[pRow+0][pCol+1]=c;
    a[pRow+1][pCol+2]=c;
    a[pRow+2][pCol+0]=c;
    a[pRow+2][pCol+1]=c;
    a[pRow+2][pCol+2]=c;
}

void prntAry(char a[][COL],int ROW){
    cout<<endl;
    for(int r=0;r<ROW;r++){
        for(int c=0;c<COL;c++){
            cout<<a[r][c];
        }
        cout<<endl;
    }
    cout<<endl;
}

void filAray(char a[][COL],int ROW,char d){
    for(int r=0;r<ROW;r++){
        for(int c=0;c<COL;c++){
            if(r==0){
                a[r][c]=c%10+48;
            }else if(r==(ROW-1)){
                a[r][c]=c%10+48;
            }else if(c==0){
                a[r][c]=r%10+48;
            }else if(c==(COL-1)){
                a[r][c]=r%10+48;
            }else{
                a[r][c]=d;
            }
        }
    }
}