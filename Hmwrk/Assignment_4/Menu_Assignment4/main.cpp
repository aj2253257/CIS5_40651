/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on 01/27/2018 at 1:00PM
 * Purpose:  Menu to be used in the Midterm, future homework and the Final
 *           Add System Libraries and Functions as needed.
 */

//System Libraries
#include <iostream> //IO library
#include <iomanip>  //Formatting library
#include <string>   //String library
#include <cmath>    //Math library
using namespace std;

//User Libraries

//Global Constants Only!

//Function Prototypes
void Menu();
int  getN();
void def(int);
void problem1();
void problem2();
void problem3();
void problem4();
void problem5();
void problem6();
void problem7();
void problem8();
void problem9();

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set a Random number seed here.
    
    //Declare Main variables here.
    int inN;
    
    //Loop on each problem
    do{
        Menu();
        inN=getN();
        switch(inN){
            case 1:    problem1();break;
            case 2:    problem2();break;
            case 3:    problem3();break;
            case 4:    problem4();break;
            case 5:    problem5();break;
            case 6:    problem6();break;
            case 7:    problem7();break;
            case 8:    problem8();break;
            case 9:    problem9();break;
            default:   return 0;
	}
    }while(inN<=9);

    //Exit Stage Right Here!
    return 0;
}

void Menu(){
    cout<<endl;
    cout<<"Type 1 to execute Problem 1"<<endl;
    cout<<"Type 2 to execute Problem 2"<<endl;
    cout<<"Type 3 to execute Problem 3"<<endl;
    cout<<"Type 4 to execute Problem 4"<<endl;
    cout<<"Type 5 to execute Problem 5"<<endl;
    cout<<"Type 6 to execute Problem 6"<<endl;
    cout<<"Type 7 to execute Problem 7"<<endl;
    cout<<"Type 8 to execute Problem 8"<<endl;
    cout<<"Type 9 to execute Problem 9"<<endl;
    cout<<"Type anything else to exit."<<endl<<endl;
}

int  getN(){
    int inN;
    cin>>inN;
    return inN;
}

void def(int inN){
    cout<<endl<<"Typing "<<inN<<" exits the program."<<endl;
}

void problem1(){
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
}
    
void problem2(){
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
}
    

void problem3(){
    float cal;
    short min;
    
    //Initialize Variables
    
    
    //Process/Map inputs to outputs

    for (cal=3.6, min=5;min<35; min=min+5){
        cout<<"Every "<<min<<" minutes of activity, "<<cal
            <<" calories will be burned"<<endl;
        cal=3.6*min; 
    }
}
    
void problem4(){
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
}
    

void problem5(){
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
}
    

void problem6(){
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
}

void problem7(){
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
}

void problem8(){
    //Declare Variables
    int less,great,inpt;
    
    //Initialize Variables
    cout<<"We are going to determine from a series of numbers you input "<<
          "which in the series is the greatest or least most"<<endl;
    cout<<"At any time, enter -99 to end your series"<<endl;
    cin>>inpt;
    
    if (inpt==-99){
        cout<<"Ending program"<<endl;
        exit;
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
}

void problem9(){
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
}