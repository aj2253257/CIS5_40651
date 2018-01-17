/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 11, 2018, 2:00 PM
 * Purpose: Create a menu for the following assignment
 */

// System Libraries
#include <iostream>
#include <cstdlib>  //RNG function
#include <ctime>    //Time library for random seed
#include <iomanip>  //Format library
#include <cmath>
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constant, Conversions,
//                   2-D Array Dimensions

//Function Prototypes

//Execution Begins Here
int main(int argc, char** argv) {
    //Declare Variables
    int probNum;
    
    //Menu with input of choice
    cout<<"Choose from the following Menu"<<endl;
    cout<<"Problem 1 -> Gaddis_9thEd_Chap4_Prob11_MathTutor"<<endl;
    cout<<"Problem 2 -> Savitch_9thEd_Chap3_Prob6_Fibonacci"<<endl;
    cout<<"Problem 3 -> Savitch_9thEd_Chap3_Prob7_EToTheX"<<endl;
    cout<<"Problem 4 -> Gaddis_9thEd_Chap4_Prob2_RomanNumeral"<<endl;
    cout<<"Problem 5 -> Gaddis_9thEd_Chap4_Prob1_MinMax"<<endl;
    cout<<"Problem 6 -> Gaddis_9thEd_Chap4_Prob3_MagicDates"<<endl;
    cout<<"Problem 7 -> Gaddis_9thEd_Chap4_Prob4_RectanglesArea"<<endl;
    cout<<"Problem 8 -> Gaddis_9thEd_Chap4_Prob5_BMI"<<endl;
    cout<<"Problem 9 -> Gaddis_9thEd_Chap4_Prob6_MassWeight"<<endl;
    cout<<"Type 1 to 9 only"<<endl;
    cin>>probNum;
    
    //Output the results
    switch(probNum){
        case 1: {
                    //Set random number seed
                    srand(static_cast<unsigned int>(time(0)));

                    //Declare Variables
                    unsigned short op1, op2, result, answer;

                    //Initialize Variables
                    op1=rand()%900+100;//Three digit number
                    op2=rand()%1000;    //Any 1 to 3 digit number

                    //Process/Map inputs to outputs
                         result=op1+op2;

                    //Output data
                         cout<<"Test your addition skills, Solve the following"<<endl;
                         cout<<setw(5)<<op1<<endl;
                         cout<<"+ "<<setw(3)<<op2<<endl;
                          cout<<"-----"<<endl<<(result>1000?" ":"  ");
                          cin>>answer;
                         cout<<(answer==result?"Correct":"Incorrect");

                    //Exit stage right!
                    break;

        }
        
        case 2: {
                unsigned int fi,fim1,fim2;
    
                    //Initialize Variables
                    fim1=1;            
                    fim2=1;
                    cout<<fim2<<", "<<fim1;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Process/Map inputs to outputs
                    fi=fim1+fim2;
                    cout<<", "<<fi;
                    fim2=fim1;
                    fim1=fi;

                    //Comparison of the ratio of Fibonacci to the Golden Ratio
                    cout<<endl<<endl<<"Ratio = "<<1.0f*fim1/fim2<<endl;break;
        }

        case 3: {
                float aproxE,term,x;
                int counter;

                    //Initialize Variables
                    aproxE=1.0;
                    counter=1;
                    x=1.0f;
                    term=x/counter++;

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Process/Map inputs to outputs
                    aproxE+=term;
                    cout<<"e^"<<x<<" approximately = "<<aproxE<<endl;
                    term*=x/counter++; 

                    //Output data
                    cout<<"e^"<<x<<"       exactly = "<<exp(x)<<endl;break;
        }
    
        case 4:     
            
                short number;

                    //Initialize Variables
                    cout<<"We are going to convert an inputted integer from 1 to 10 to "<<
                          "Roman Numerals."<<endl;
                    cout<<"Please enter an integer from 1 to 10"<<endl;
                    cin>>number;


                    //Process/Map inputs to outputs
                    switch (number) {
                        case 1: 
                        cout<<"The roman numeral for the integer "<<number<<" is I."<<endl;break;
                        case 2:
                        cout<<"The roman numeral for the integer "<<number<<" is II."<<endl;break;
                        case 3: 
                        cout<<"The roman numeral for the integer "<<number<<" is III."<<endl;break;
                        case 4: 
                        cout<<"The roman numeral for the integer "<<number<<" is IV."<<endl;break;
                        case 5:
                        cout<<"The roman numeral for the integer "<<number<<" is V."<<endl;break;
                        case 6: 
                        cout<<"The roman numeral for the integer "<<number<<" is VI."<<endl;break;
                        case 7: 
                        cout<<"The roman numeral for the integer "<<number<<" is VII."<<endl;break;
                        case 8: 
                        cout<<"The roman numeral for the integer "<<number<<" is VIII."<<endl;break;
                        case 9: 
                        cout<<"The roman numeral for the integer "<<number<<" is IX."<<endl;break;
                        case 10: 
                        cout<<"The roman numeral for the integer "<<number<<" is X."<<endl;break;
                        default:
                            cout<<"You did not enter an integer from 1 to 10. Ending program."<<endl;break;
                    }break;
        case 5: 
                    int one, two;
    
                        //Initialize Variables
                        cout<<"We are going to input two numbers and display "<<
                              "the larger of two."<<endl;
                        cout<<"Please enter a number from 1 to 100"<<endl;
                        cin>>one;
                        cout<<"Please enter another number from 1 to 100"<<endl;
                        cin>>two;

                        //Process/Map inputs to outputs

                        //Output data
                        if (one>100||one<0)
                            cout<<"You input an invalid entry"<<endl;
                        else if (one>two)
                            cout<<"The greater number is "<<one<<endl;
                        else if (two>one)
                            cout<<"The greater number is "<<two<<endl;
                        else if (one==two)
                            cout<<"The two numbers are equal, neither is greater."<<endl;
                        else
                            cout<<"You input an invalid entry"<<endl;break;
                            
                            
        case 6:
                    short day,month,year;
    
                        //Initialize Variables
                        cout<<"We are going to determine if a date you enter is a magical date."<<endl;
                        cout<<"Please enter the day of the month"<<endl<<endl;
                        cin>>day;
                        if (day>31||day<=0)
                            cout<<"You have entered an invalid date"<<endl;
                        if (day>31||day<=0) return 0;

                        cout<<"Please enter the month of year"<<endl<<endl;
                        cin>>month;
                        if (month>12||month<=0)
                            cout<<"You have entered an invalid date"<<endl;
                        if (month>12||month<=0) return 0;

                        cout<<"Please enter last two digits of the year"<<endl<<endl;
                        cin>>year;
                        if (year<=0||year>99)
                            cout<<"You have entered an invalid date"<<endl;
                        if (year<=0||year>99) return 0;

                        //Process/Map inputs to outputs

                        //Output data
                            cout<<"You have entered the date, "<<month<<"/"<<day<<"/"<<year<<endl;
                            if (year==month*day)
                                cout<<"The date is a magical date!"<<endl;
                            else
                                cout<<"The date is not magical at all"<<endl;break;

        case 7: 
                    int length,width,area,
                    length2,width2,area2;
    
                        //Initialize Variables
                        cout<<"We are going to calculate the areas of two separate rectangles "<<
                              "based on your input, and determine which of the two is larger"<<endl;
                        cout<<"Please enter the length of the first rectangle in feet"<<endl;
                        cin>>length;

                        cout<<"Please enter the width of the first rectangle in feet"<<endl;
                        cin>>width;

                        cout<<"Please enter the length of the second rectangle in feet"<<endl;
                        cin>>length2;

                        cout<<"Please enter the width of the second rectangle in feet"<<endl;
                        cin>>width2;

                        //Process/Map inputs to outputs
                        area=length*width;
                        area2=length2*width2;

                        //Output data
                        if (area<0||area2<0)
                            cout<<"You entered an invalid value"<<endl;
                        else if (area<0||area2<0) return 0;
                        else if (area>0||area2>0) {
                                cout<<"With the area of first rectangle being "<<area<<
                                      " feet and the second rectangle being "<<area2<<
                                      " feet, "<<endl;

                                if (area==area2)
                                cout<<"both rectangles are alike."<<endl;
                                else if (area>area2)
                                cout<<"the greater sized rectangle is the first rectangle"<<endl;
                                else if (area2>area)
                                cout<<"the greater sized rectangle is the second rectangle"<<endl;
                        }
                        break;
    
        case 8: 
                    float bmi;
                    short weight, height;

                        //Initialize Variables
                        cout<<"We are going to determine if you are underweight, optimal, or "<<
                              "overweight based on your Body Mass Index"<<endl;
                        cout<<"Please input your weight in pounds"<<endl;
                        cin>>weight;

                        cout<<"Please input your height, in inches"<<endl;
                        cin>>height;

                        //Process/Map inputs to outputs
                        bmi=(weight*703.0f)/(height*height);

                        //Output data
                        if (bmi<=0)
                            cout<<"You input an invalid entry"<<endl;
                        else if (bmi<=0)
                            return 0;

                        else if (bmi>0){
                        cout<<"Using the information provided, your Body Mass Index is "<<
                                setprecision(3)<<bmi<<endl;

                        if (bmi<18.5)
                            cout<<"Based on this determination, you are underweight"<<endl;
                        else if (bmi>=18.5&&bmi<=25.0f)
                            cout<<"Based on this determination, you are an optimal weight"<<endl;
                        else if (bmi>25.0f)
                            cout<<"Based on this determination, you are overweight"<<endl;
                        }break;

        case 9: 
                    float weight3;
                    short mass;

                        //Initialize Variables
                        cout<<"We are going find weight, in Newtons, using mass and determine "<<
                              "if the object is too light or too heavy"<<endl;
                        cout<<"Please input the mass of the object"<<endl;
                        cin>>mass;

                        //Process/Map inputs to outputs
                        weight3=(mass*9.8f);

                        //Output data
                        if (weight3<=0)
                            cout<<"You input an invalid entry"<<endl;
                        if (weight3<=0)
                            return 0;

                        if (weight3>0){
                        cout<<"Using the information provided, the weight, in newtons is "<<
                                setprecision(3)<<weight3<<endl;

                        if (weight3<10&&weight3>0)
                            cout<<"Based on this determination, the object is too light"<<endl;
                        else if (weight3>1000)
                            cout<<"Based on this determination, the object is too heavy"<<endl;
                        }break;

                            default:cout<<"You choose to exit"<<endl;
                        }
        
    
    //Exit stage right!
    return 0;
}