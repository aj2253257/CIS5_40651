/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 18, 2018, 1:10 PM
 * Purpose: Sum of Numbers
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
    int input,outpt; //Pre and post process variables
    
    //Initialize Variables
    cout<<"We are going to find the sum of every number from 1 to the "
        <<"number you input"<<endl;
    cout<<"Please enter a positive number"<<endl;
    cin>>input;
        while (input<=0){   //Prevents the input of zero or negative numbers
            cout<<"You input an invalid number"<<endl;
            cin>>input;
        }
    
    int num, num2; //Sum and temp integer variables
    for (num=1, num2=0;num!=input;num++){
            num2=num2+num;
            outpt=num2+input; //Moves value outside of loop scope                
    }
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"The sum of all the numbers from 1 to "<<input
        <<" is "<<outpt<<endl;
    
    //Exit stage right!
    return 0;
}