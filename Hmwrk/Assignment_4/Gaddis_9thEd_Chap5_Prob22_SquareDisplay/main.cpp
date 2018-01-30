/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 29, 2018, 8:00 PM
 * Purpose: Square Display
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
    int inpt,newln;
    
    //Initialize Variables
    cout<<"We are going to display a square comprised of the the letter X "
        <<" using an integer inputted"<<endl;
    cout<<"Please enter a positive integer no greater than 15"<<endl;
    cin>>inpt;
    while (inpt<1||inpt>15){
        cout<<"Invalid entry"<<endl;
        cin>>inpt;
    }
    
    //Process/Map inputs to outputs
    
    
    //Output data
    for (int i=1;i<=inpt;i++){
        for(newln=1;newln<=inpt;newln++){
            cout<<"X";
        }
        cout<<endl;
        newln=1;    
    }
    //Exit stage right!
    return 0;
}