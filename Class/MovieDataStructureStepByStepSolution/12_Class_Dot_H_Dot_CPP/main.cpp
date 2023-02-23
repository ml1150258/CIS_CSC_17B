/* 
 * Author: Dr. Mark E. Lehr
 * Created on April 3rd, 2020, 11:40 AM
 * Purpose: Movie Data Structure
 *      Step by step Solution
 *      0 - Copy the Template
 *      1 - Read in 1 Set of Data and Verify
 *      2 - Read in N Sets of Data and Verify
 *      3 - Format the Results
 *      4 - Static Structure Array
 *      5 - Change to a Dynamic Char Array inside Static Structure
 *      6 - Dynamic Structure
 *      7 - Fill Structure Function
 *      8 - Display Function for the Structure
 *      9 - Deallocate Memory in a Function
 *      10- Structure in a Structure. Minimize Dependencies
 *      11- Structures placed in their own .h Files
 *      12- Class in .h and .cpp files
 * Why? Simplification, all the code is tucked away into the class.
 * Previously checkout and debugged.
 */

//System Level Libraries
#include <iostream>   //I/O Library
#include <cstdlib>    //Random Number Generator, Setting seed, etc....
#include <iomanip>    //Formatting Library
#include <string>     //String Library
using namespace std;  //Libraries compiled under std

//User Level Libraries/Includes here.  On Code-E we have to put
//structures and classes here before main but you would never do this
//for normal projects.  We would just include many .h files
#include "CMovie.h"

//Global Constants Only - Science/Math Related, Conversions, Array and Higher
//Dimensions.  Put Global Variables anywhere in your program i.e. variables
//not contained in functions and I will give you an F!  Local variables
//only allowed.

//Function Prototypes here, Function implementations after main!

//Execution Begins Here!
int main(int argc, char** argv) {
    //Variable Declarations
    CMovie cmovie;//Class
    
    //Now you can loop on the data as many times as it takes!
    cmovie.display();//Look and see

    //Exit stage right!
    return 0;
}