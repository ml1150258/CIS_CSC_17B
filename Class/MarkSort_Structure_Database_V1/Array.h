/* 
 * File:   main.cpp
 * Author: Dr. Mark E. Lehr
 * Created on August 26th, 2020, 6:14 PM
 * Purpose:  Example of Mark Sort with Structure
 */

#ifndef ARRAY_H
#define ARRAY_H

struct Array{
    unsigned short size;//Size of the array
    int *data;          //Dynamic pointer to the data in the array
    int *index;         //Index to the data in the array
};

#endif /* ARRAY_H */

