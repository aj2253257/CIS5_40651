/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 28, 2018, 1:50 PM
 * Purpose: Calculate wage starting at a penny that doubles a day
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
    short days;
    float salry;
    
    //Initialize Variables
    cout<<"We are going to calculate what your wage a day would if your "<<
          "salary doubled every day starting at 1 penny."<<endl;
    cout<<"Please enter how many days worked"<<endl;
    cin>>days;
    while (days<1){
        cout<<"Invalid input"<<endl;
        cin>>days;
    }
    
    salry=0.01;
    
    //Process/Map inputs to outputs
    cout<<fixed<<showpoint<<setprecision(2);
    cout<<"Day"<<setw(15)<<"Salary"<<endl;
    cout<<"------------------------------"<<endl;
    for (int i=1;i<=days;i++){
        cout<<i<<setw(12)<<"$"<<salry<<endl;
        salry*=2;
    }
    
    //Output data
    
    
    
    //Exit stage right!
    return 0;
}