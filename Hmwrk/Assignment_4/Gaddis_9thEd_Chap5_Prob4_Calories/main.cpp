/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 22, 2018, 7:05 PM
 * Purpose: Calculate calories burned
 */

// System Libraries
#include <iostream>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constant, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float cal;
    short min;
    
    //Initialize Variables
    
    
    //Process/Map inputs to outputs

    for (cal=3.6, min=5;min<35; min=min+5){
        cout<<"Every "<<min<<" minutes of activity, "<<cal
            <<" calories will be burned"<<endl;
        cal=3.6*min;
        
        
    }
    //Output data
    
    
    //Exit stage right!
    return 0;
}