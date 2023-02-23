/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MovieInfoSturc.h
 * Author: mlehr
 *
 * Created on July 14, 2021, 4:48 PM
 */

#ifndef MOVIEINFOSTURC_H
#define MOVIEINFOSTURC_H

#include <string>
using namespace std;

struct MovieInfo{
    string movName;//Strings are good
    char *dirName;//You should know how to deal with dynamic character arrays
    unsigned short yrRlsd; //Don't need a larger data size and always > 0
    unsigned short runTime;//Don't need a larger data size and always > 0
};


#endif /* MOVIEINFOSTURC_H */

