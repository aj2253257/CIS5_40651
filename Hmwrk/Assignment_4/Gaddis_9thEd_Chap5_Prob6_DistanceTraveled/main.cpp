/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 28, 2018, 11:30 AM
 * Purpose: Calculate distance traveled for speed and time
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
    short spd,time;
    
    //Initialize Variables
    cout<<"Please input the average speed of travel, and distance traveled"
        <<endl;
    cin>>spd>>time;
    while (spd<=0||time<1){
        cout<<"Invalid input, please try again"<<endl;
        cin>>spd>>time;
    }
    
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Hour"<<setw(23)<<"Distance Traveled"<<endl;
    cout<<"----------------------------------------"<<endl;
    for (int i=1;i<=time;i++){
        cout<<i<<setw(17)<<(spd*i)<<endl;
    }
    //Exit stage right!
    return 0;
}