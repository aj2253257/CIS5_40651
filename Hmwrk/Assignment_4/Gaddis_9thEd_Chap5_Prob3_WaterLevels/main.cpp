/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 22, 2018, 6:55 PM
 * Purpose: Calculate water levsl rising
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
    float ocean;
    short mult;
    
    //Initialize Variables
    
    
    //Process/Map inputs to outputs

    for (ocean = 1.5, mult = 1;mult != 26; mult++){
        ocean=1.5*mult;
        cout<<"For year "<<mult<<" the water will have risen "<<ocean
            <<" millimeters of water"<<endl;
    }
    //Output data
    
    
    //Exit stage right!
    return 0;
}