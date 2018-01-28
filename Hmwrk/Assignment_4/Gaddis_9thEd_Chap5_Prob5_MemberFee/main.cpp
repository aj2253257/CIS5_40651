/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 28, 2018, 11:20 AM
 * Purpose: Calculate/Display membership fee increase
 */

// System Libraries
#include <iostream>
#include <iomanip>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constant, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    float charge;
    
    //Initialize Variables
    charge=2500;
    
    //Process/Map inputs to outputs
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Current membership fee is $"<<charge<<endl;
    
    for (int i=1;i<=6;i++){
        charge+=(charge*0.04);
        cout<<"For year "<<i<<" the membership fee will be $"<<charge<<endl;

    }
    
    //Output data
    
    //Exit stage right!
    return 0;
}