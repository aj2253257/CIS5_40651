/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 28, 2018, 2:15 PM
 * Purpose: Calculate occupancy rate of hotel
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
    short floors,rooms,occupy;
    float rate,occpd,totRms;
    
    //Initialize Variables
    totRms=0;
    occpd=0;
    
    cout<<"We are going to calculate the occupancy rate of a hotel"<<endl;
    cout<<"Please enter the number of floors in the hotel"<<endl;
    cin>>floors;
    for (int i=1;i<=floors;i++){
        if (i!=13){
        cout<<"Please enter the number of rooms on floor "<<i<<endl;
        cin>>rooms;
        totRms+=rooms;
        cout<<"Please enter the number of occupied rooms in floor "<<i<<endl;
        cin>>occupy;
        occpd+=occupy;
        }
    }
    
    //Process/Map inputs to outputs
    rate=(occpd/totRms)*100;
    
    //Output data
    cout<<"At this hotel we have the following statistics"<<endl;
    cout<<"There are a total of "<<totRms<<" rooms"<<endl;
    cout<<"Of these rooms, "<<occpd<<" rooms are occupied"<<endl;
    cout<<"Furthermore, "<<totRms-occpd<<" rooms are unoccupied"<<endl;
    cout<<fixed<<showpoint<<setprecision(2)<<endl;
    cout<<"The rate of occupancy in this hotel is currently "<<rate<<"%"<<endl;
    
    //Exit stage right!
    return 0;
}