/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 28, 2018, 4:40 PM
 * Purpose: From a series of inputs determine greatest/least
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
    int less,great,inpt;
    
    //Initialize Variables
    cout<<"We are going to determine from a series of numbers you input "<<
          "which in the series is the greatest or least most"<<endl;
    cout<<"At any time, enter -99 to end your series"<<endl;
    cin>>inpt;
    
    if (inpt==-99){
        cout<<"Ending program"<<endl;
        return 0;
    }
    
    less=inpt;
    great=inpt;
    
    for (int i=inpt;i!=-99;i=inpt){
        cin>>inpt;
        if (inpt!=-99){
            if (inpt>less&&inpt>great)
                great=inpt;
            else if (inpt<less)
                less=inpt;
        }
    }
    
    cout<<"End of series"<<endl;
        
    //Process/Map inputs to outputs
    
    //Output data
    cout<<"Based on the series of numbers you entered,";
    if (less==great)
        cout<<" the number "<<less<<" is equal to itself"<<endl;
    else
        cout<<" the number "<<less<<" is the least most integer and"
            <<" the number "<<great<<" is the greatest most integer in the "
            <<"series you input"<<endl;
    
    //Exit stage right!
    return 0;
}