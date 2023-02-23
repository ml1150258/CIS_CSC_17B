/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
using namespace std;  //Libraries compiled under std


#include "CMovie.h"

CMovie::~CMovie(){
    //Clean Up the Dynamic Stuff
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        delete [] movies->mveInfo[mvees].dirName;//The character arrays in the Stucture
    }
    delete [] movies->mveInfo;//Now the array of Structures
    delete movies;//Now deallocate the final Movie Structure
}

//Just copy, cut, and paste into a function.  Code already checked out in main.
void CMovie::display(){
    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        //I copied the output from Code-E then applied formatting
        cout<<left<<endl;
        cout<<setw(11)<<"Title:"<<movies->mveInfo[mvees].movName<<endl;
        cout<<setw(11)<<"Director:"<<movies->mveInfo[mvees].dirName<<endl;
        cout<<setw(11)<<"Year:"<<movies->mveInfo[mvees].yrRlsd<<endl;
        cout<<setw(11)<<"Length:"<<movies->mveInfo[mvees].runTime<<endl;
    }
}

CMovie CMovie::operator=(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }   
    
    return *this;
}

CMovie::CMovie(const CMovie &obj){
    //Declare the Structure array
    movies=new Movies;
    //Copy the number of movies
    movies->nMovies=obj.movies->nMovies;            
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){
        movies->mveInfo[mvees].movName=obj.movies->mveInfo[mvees].movName;
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        movies->mveInfo[mvees].dirName=obj.movies->mveInfo[mvees].dirName;
        movies->mveInfo[mvees].yrRlsd=obj.movies->mveInfo[mvees].yrRlsd;
        movies->mveInfo[mvees].runTime=obj.movies->mveInfo[mvees].runTime;
    }    
}

//This implementation of this function was thoroughly tested out already
//in main.
CMovie::CMovie(){
    //Declare the Structure array
    movies=new Movies;
    //I copied the output from Code-E so I wouldn't make any typing mistakes
    //Then I just formatted.
    cout<<"This program reviews structures"<<endl;
    cout<<"Input how many movies, the Title of the Movie, Director, Year "<<
          "Released, and the Running Time in (minutes)."<<endl;
    cin>>movies->nMovies;                //Integer Read
    
    //Now you can allocate the array dynamically
    movies->mveInfo=new MovieInfo[movies->nMovies];

    //Now you can loop on the data as many times as it takes!
    for(int mvees=0;mvees<movies->nMovies;mvees++){//Gotta frickin indent!!!!!
        cin.ignore();              //Oh Yea, Gotta do this for the buffer
        getline(cin,movies->mveInfo[mvees].movName);//Movie Name In an Array Structure
        int size=81;//Make it Dynamic
        movies->mveInfo[mvees].dirName=new char[size];
        cin.getline(movies->mveInfo[mvees].dirName,size-1);//Array Structure element
        cin>>movies->mveInfo[mvees].yrRlsd;//Look ma, no ignore after gets!!!!
        cin>>movies->mveInfo[mvees].runTime;//Look again,no ignore after gets,only before
    }
}