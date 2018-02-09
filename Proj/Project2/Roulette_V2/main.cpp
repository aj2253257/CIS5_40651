/* 
 * File:   main.cpp
 * Author: Andrew Joson
 * Created on January 29, 2018, 9:00 PM
 * Purpose: Create roulette game
 */

// System Libraries
#include <iostream> //IO library
#include <cstdlib>  //For sRand function
#include <ctime>    //Time library for srand function
#include <iomanip>  //formatting library
#include <cmath>    //Math library
#include <string>   //String library
#include <fstream>  //File library
using namespace std;

//User Libraries

//Global Constants - Math/Physics Constant, Conversions,
//                   2-D Array Dimensions

//Function Prototypes
void mainMenu();                //Main menu of game
void gameOn(short[],short[]);   //Primary game function
int gameSpn(bool);              //Return value of spin from 1-38
bool gameOn(int,int);           //Demonstrating overloading function names
                                //      actual purpose for game statistics

//Execution Begins Here

int main(int argc, char** argv) {
    //Setting random seed
    srand(static_cast<unsigned int> (time(0))); //Generate random seed
    
    
    //Run main menu
    mainMenu();

    //Exit stage right!
    return 0;
}


//Spin roulette wheel
int gameSpn(bool endgame=0){
    //RNG for spin value
        if (endgame == 0){
            
    int spin;        
        
    for (spin=0;spin>38||spin<1;) {
        spin = rand() % 100;    //Modulus the rand to 1-99, only accept
                                //if integer is 1-38 (37=zero, 38=doublezero)
    }
        //Output to user where the ball has landed
        if (spin<=36){
            cout<<endl<<"The ball has landed on "<<spin<<"!"<<endl<<endl;
            return spin;
        }
        else if (spin==37){
            cout<<endl<<"The ball has landed on Zero! Ouch!"<<endl<<endl;
            return spin;
        }
        else if (spin==38){
            cout<<endl<<"The ball has landed on Double-Zero! Ouch!"<<endl<<endl;
            return spin;
        }
        }
}

//Flag to determine winning statement in stats
bool gameOn(int win,int lose){
    if (win>lose)
        return true;
    else 
        return false;
}


//Main menu
void mainMenu(){
    //Pull previous stats
    ifstream gmStats;
    string stats;
    const int RB=18;
    //Array for all red values on board
    short reds[RB]={1,3,5,7,9,12,14,16,18,19,21,23,25,27,30,32,34,36};
    //Array for all black values on board
    short blacks[RB]={2,4,6,8,10,11,13,15,17,20,22,24,26,28,29,31,33,35};

    //Game menu
    cout << "Welcome to CSC-5 Roulette by Andrew Joson!"
            << endl << "Here are your menu options:" << endl;
    cout << "1. Play game" << endl << "2. How to play" << endl
            << "3. Betting Odds" << endl << "4. Previous Game Statistics"
            <<endl<<"5. Exit Game"<< endl;

    //Switch case for main menu
    short menu;
    do {
        cin>>menu;
        switch (menu) {
            case 1:
                gameOn(reds,blacks);
                
                break;
            case 2:
                cout <<endl<< "You are going to be playing the table game called "
                        << "roulette." << endl << "In this version of roulette,"
                        << endl << "only one bet may be made per spin, however"
                        << endl << "your bet options are any straight bet,"
                        << endl << "dozen, or even chance bet. Table pay out odds"
                        << endl << "can be found from the main menu."
                        << endl << "The minimum bet for this table is $50." << endl

                        << endl << "Here are your menu options:" << endl;
                cout <<endl<< "1. Play game" << endl << "2. How to play" << endl
                        << "3. Betting Odds" << endl << "4. Previous Game Statistics" 
                        << endl << "5. Exit Game" << endl;

                break;
            case 3:
                cout <<endl<< "The pay outs for the bets available in this version "
                        << "of roulette are as follows: " << endl
                        << "All even chances (Red/Black, High/Low, Even/Odd) "
                        << "are paid out: 1:1" << endl
                        << "All dozens bets are paid out as: 2:1 "
                        << endl << "All straight bets are paid out as: 35:1,"
                        << endl << "except the 0 and 00 rolls which include a "
                        << endl << "house courtesy of: 36:1 odds" << endl
                        << endl << "Here are your menu options:" << endl;
                cout <<endl<< "1. Play game" << endl << "2. How to play" << endl
                        << "3. Betting Odds" << endl << "4. Previous Game Statistics"
                        << endl << "5. Exit Game"<<endl;

                break;
            case 4:
                gmStats.open ("gamestats.dat");
                while (getline (gmStats,stats)){
                cout<<stats<<endl;
                }
                gmStats.close();
                cout <<endl<< "Here are your menu options:" << endl;
                cout <<endl<< "1. Play game" << endl << "2. How to play" << endl
                        << "3. Betting Odds" << endl << "4. Previous Game Statistics" 
                        << endl << "5. Exit Game" << endl;
                
                break;
            case 5: 
                exit(0);
                break;

        }
    }    while (menu != 5 && menu != 1);
}

//Core game function
void gameOn(short reds[], short blacks[]) {
    ofstream gmStats;           //Write to file //
    unsigned int bnkRoll=0;       //Int for dollars in bank roll
    unsigned int betAmt=0;        //Int for amount placed on bet
    int strBet;                 //Number placed for straight bet
    int spin;                   //Value of roulette wheel spin              
    
    //Variables to represent statistics
    int wins=0;         //Number of wins
    int losses=0;       //Number of losses
    int totGame=0;      //Total number of games
    int earnings=0;     //Total earnings
    int ecPlac=0;       //Number of even chance bets made
    int dozPlac=0;      //Number of dozens bets made
    int strPlac=0;      //Number of straight bets made
    float winPct=0.00f; //Win percentage
    
    char    won = 'L'; //Win flag
    bool    red = false, //Even chance flags
            black = false,
            even = false,
            odd = false,
            high = false,
            low = false;

    bool    doz = false, //Dozens flags
            doz2 = false,
            doz3 = false;

    //Output to user the menu options
    cout <<endl<< "Feeling lucky? Let's play a game of roulette!" << endl;
    cout << "To begin, we are going to determine the size of your bankroll."
            << endl << "Please choose from the following, bearing in mind the"
            << " minimum bet for this table is $50."
            << endl << endl << "1. $1,000" << endl << "2. $2,000" << endl
            << "3. $5,000" << endl << "4. $10,000" << endl;

    //Determining bankroll. Only occurs once.
    short bnkMenu = 0;
    bnkRoll=0;
    do {                    //Switch case for bank menu
        cin>>bnkMenu;
        switch (bnkMenu) {  //Case corresponds to bankroll amount
            case 1:
                bnkRoll = 1000;
                cout<<endl << "Bankroll set to $1,000."<<endl<<endl;
                break;
            case 2:
                bnkRoll = 2000;
                cout<<endl << "Bankroll set to $2,000."<<endl<<endl;
                break;
            case 3:
                bnkRoll = 5000;
                cout<<endl << "Bankroll set to $5,000."<<endl<<endl;
                break;
            case 4:
                bnkRoll = 10000;
                cout<<endl << "Bankroll set to $10,000."<<endl<<endl;
                break;
            default:
                cout<<endl<<"Invalid input, please try again"<<endl;
                break;
        }
    } while (bnkMenu < 1 || bnkMenu > 4);   //Keep menu open until valid input

    bool endgame = false;   //Check if game is currently being played
    
    //Enter betting phase of game
    //Output to user options to bet
    do {    
        //Check if player has lost all money
        if (bnkRoll<50){
            cout<<endl<<"You have lost all of your money!"<<endl;
            cout<<"You cannot meet the table minimum for bets."<<endl;
            cout<<"Saving statistics and ending game."<<endl;
            endgame=1;
            return;
        }
        
        if (endgame == 0){
        cout<<endl << "Your bank roll is currently at $"<<bnkRoll << endl;
        cout << "We are now going to enter the bet phase of the game." << endl;
        cout<<endl << "Here are your options:" << endl
                << "1. Even Chances" << endl << "2. Dozens" << endl
                << "3. Straight Bets" << endl <<"4. Save Stats and Exit Game" << endl;
        }

        
        //Menu for different bets to be placed
    short betMenu;
        do {
            if (endgame == 0)
            cin>>betMenu;
            switch (betMenu) {
                case 1:         //Even Chances menu
                    cout<<endl << "Even Chances:" << endl << endl << "1. Black" << endl
                            << "2. Red" << endl << "3. Even" << endl << "4. Odd" << endl
                            << "5. High" << endl << "6. Low" << endl;
                    short ecMenu;
                    cin>>ecMenu;
                    switch (ecMenu) {
                        case 1:
                            cout<<endl << "You will be betting on Black." << endl;
                            black = true;
                            ecPlac++;
                            break;
                        case 2:
                            cout<<endl << "You will be betting on Red." << endl;
                            red = true;
                            ecPlac++;
                            break;
                        case 3:
                            cout<<endl << "You will be betting on Even." << endl;
                            even = true;
                            ecPlac++;
                            break;
                        case 4:
                            cout<<endl << "You will be betting on Odd." << endl;
                            odd = true;
                            ecPlac++;
                            break;
                        case 5:
                            cout<<endl << "You will be betting on High"
                                    <<" (19-36)"<< endl;
                            high = true;
                            ecPlac++;
                            break;
                        case 6:
                            cout<<endl << "You will be betting on Low"
                                    <<" (1-18)"<< endl;
                            low = true;
                            ecPlac++;
                            break;
                        default:    //Catch invalid entries
                            cout<<endl<<"Invalid input, try again."<<endl;
                            cin>>ecMenu;
                            break;
                    }
                    break;


                case 2:     //Dozens menu
                    cout<<endl << "Dozens:" << endl << endl << "1. First Dozen" << endl
                            << "2. Second Dozen" << endl << "3. Third Dozen" << endl;

                    short dzMenu;
                    cin>>dzMenu;
                    switch (dzMenu) {
                        case 1:
                            cout<<endl << "You will be betting on "
                                    << "the First Dozen." << endl;
                            doz = true;
                            dozPlac++;
                            break;
                        case 2:
                            cout<<endl << "You will be betting on "
                                    << "the Second Dozen." << endl;
                            doz2 = true;
                            dozPlac++;
                            break;
                        case 3:
                            cout<<endl << "You will be betting on "
                                    << "the Third Dozen." << endl;
                            doz3 = true;
                            dozPlac++;
                            break;
                        default:    //Catch invalid entries
                            cout<<endl<<"Invalid input, try again."<<endl;
                            cin>>dzMenu;
                            break;
                    }
                    break;

                case 3:     //Straight bets menu
                    cout << "Straight Bets:" << endl << "1. 1-36"<<endl
                            <<"2. Zero"<<endl<<"3. Double-Zero"<<endl;
                    
                    short strMenu;
                    cin>>strMenu;
                    switch (strMenu) {
                        case 1:     //User input straight bet number limited to 1-36
                            strBet=1;
                            cout<<endl<<"Enter a number from 1-36"<<endl;
                            do{
                                if (strBet<1||strBet>36){
                                    cout<<endl<<"Invalid number. Try again."<<endl;
                                }
                            cin>>strBet;
                            }while(strBet<1||strBet>36);
                            cout<<endl<<"You will be betting on "<<strBet<<"."<<endl;
                            strPlac++;
                            break;
                            
                        case 2:     //Output Zero but set strBet to 37
                            cout<<endl<<"You will be betting on Zero."<<endl;
                            strBet=37;
                            strPlac++;
                            break;
                            
                        case 3:     //Output Double-Zero but set strBet to 38
                            cout<<endl<<"You will be betting on Double-Zero."<<endl;
                            strBet=38;
                            strPlac++;
                            break;
                        default:    //Catch invalid entries
                            cout<<"Invalid input, try again."<<endl;
                            cin>>strMenu;
                            break;
                    }      
                    break;
            
                case 4: //Exiting game leads to statistics update ofstream and exit
                    cout<<endl << "Exiting Game." << endl<<endl;
                    endgame = 1;
                    break;
            }
        }while (betMenu>4||betMenu<=0);
        
        
        //Betting phase
        if (endgame == 0){      //Check if game exited or not
        cout<<endl<<"How much money would you like to bet?"<<endl
                <<"The table minimum is $50."<<endl;
        cout<<"You currently have $"<<bnkRoll<<" in your bank roll."<<endl;
        cin>>betAmt;            //Input bet amount
        while(betAmt<50||betAmt>bnkRoll){
            if (betAmt<50){     //Do not allow bets below table minimum
                cout<<endl<<"You may not place a bet lower than $50."<<endl
                        <<"Please enter in the amount you would like the bet"<<endl;
                cin>>betAmt;
            }
            else {   //Do not allow bets larger than bank roll
                cout<<endl<<"You may not bet more than the amount in"
                        <<" your bankroll."<<endl
                        <<"Please enter in the amount you would like the bet"<<endl;
                cin>>betAmt;
            }
        }
        
        bnkRoll-=betAmt;        //Subtract bet amount from bank roll
        cout<<endl<<"You are currently betting $"<<betAmt<<" and have $"
                <<bnkRoll<<" remaining in your bank roll."<<endl<<endl;
    }
        
        
        //Output to user the game is approaching the spin phase
    if (endgame == 0){
        cout<<"We are now preparing to enter the spin phase of the game!"
                <<endl<<endl<<"All bets are placed!"<<endl;
    }
 
    //Enter spin phase, return value
    if (endgame==0){
        spin=gameSpn(0);
    }
        
    //Pay out if win, consolation if loss 
        if (endgame == 0){
            
    cout<<"At this time, we are entering the pay out phase."<<endl;
        if (spin>0&&spin<=36){
            if (spin%2==0&&even==true){ //Check for even bets
                cout<<endl<<"Congratulations! "<<spin<<" is an Even number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                even=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame+=1;
                betAmt=0;   //Must reset betAmt after gathering statistics
            }
            if (spin%2!=0&&odd==true){ //Check for odd bets
                cout<<endl<<"Congratulations! "<<spin<<" is an Odd number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                odd=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
            }
            //Check for black
            for (int n=0;n<=17;n++){
                if (black==true&&blacks[n]==spin){
                    cout<<endl<<"Congratulations! "<<spin
                            <<" is a Black number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                black=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                 }
            }
            //Check for red
            for (int n=0;n<=17;n++){
                if (red==true&&reds[n]==spin){
                    cout<<endl<<"Congratulations! "<<spin
                            <<" is a Red number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                red=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                 }    
            }
            //Check for high 19-36
            if (spin>=19&&spin<=36&&high==true){
                cout<<endl<<"Congratulations! "<<spin<<" is a High number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                high=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }    
            }
            //Check for low 1-18
            if (spin>=1&&spin<=18&&low==true){
                cout<<endl<<"Congratulations! "<<spin<<" is a Low number!"<<endl
                        <<"You receive $"<<betAmt*2<<" as a 1:1 pay out!"<<endl;
                bnkRoll+=(betAmt*2);
                low=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*2);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }    
            }
            //Check for 1st Dozens
            if (spin>=1&&spin<=12&&doz==true){
                cout<<endl<<"Congratulations! "<<spin
                        <<" is in the First Dozens!"<<endl
                        <<"You receive $"<<betAmt*3<<" as a 2:1 pay out!"<<endl;
                bnkRoll+=(betAmt*3);
                doz=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*3);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }   
            //Check for 2nd Dozens
            if (spin>=13&&spin<=24&&doz2==true){
                cout<<endl<<"Congratulations! "<<spin
                        <<" is in the Second Dozens!"<<endl
                        <<"You receive $"<<betAmt*3<<" as a 2:1 pay out!"<<endl;
                bnkRoll+=(betAmt*3);
                doz2=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*3);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }    
            //Check for 3rd Dozens
            if (spin>=25&&spin<=36&&doz3==true){
                cout<<endl<<"Congratulations! "<<spin
                        <<" is in the Third Dozens!"<<endl
                        <<"You receive $"<<betAmt*3<<" as a 2:1 pay out!"<<endl;
                bnkRoll+=(betAmt*3);
                doz3=false;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*3);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }    
        
            //Check for straight bets 1-36 and zero bets (37-38)
            if (spin==strBet){
                if (strBet>0&&strBet<=36){
                cout<<endl<<"Congratulations! "<<spin
                        <<" is the number you bet on!"<<endl
                        <<"You receive $"<<betAmt*36<<" as a 35:1 pay out!"<<endl;
                bnkRoll+=(betAmt*36);
                strBet=0;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*36);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                } 
                else if (spin==37){
                cout<<endl<<"Congratulations! Zero"
                        <<" is the number you bet on!"<<endl<<endl
                        <<"We have included a house courtesy of "
                        <<"you receiving $"<<betAmt*37<<" as a 36:1 pay out!"<<endl;
                bnkRoll+=(betAmt*37);
                strBet=0;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*37);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }
                else if (spin==38){
                cout<<endl<<"Congratulations! Double-Zero"
                        <<" is the number you bet on!"<<endl<<endl
                        <<"We have included a house courtesy of "
                        <<"you receiving $"<<betAmt*37<<" as a 36:1 pay out!"<<endl;
                bnkRoll+=(betAmt*37);
                strBet=0;
                spin=0;
                won='W';
                
                //Statistics update
                earnings+=(betAmt*37);
                wins++;
                totGame++;
                betAmt=0;   //Must reset betAmt after gathering statistics
                }  
            }
        if (won=='L'&&endgame==0){
                cout<<"Sorry, you lose this round."<<endl;
                earnings-=betAmt;
                betAmt=0;   //Must reset betAmt after gathering statistics
                //Statistics update
                totGame++;
                losses++;
            }
        
        won='L';   //Reset win flag for next round
        
        //Statistics calculations
        winPct=(static_cast<float>(wins)/totGame)*100;
        float oddsRpt=0.0263157;        //1/38 for stats base odds of repeat
        float posble=pow(oddsRpt,(totGame-1));    //1/38 to a power for odds of repeat stats
        short popular=0;                        //Used to determine what popular bet to display
        //Save statistics of game for main menu on next run of the game
        
        gameOn(wins,losses);
        
        gmStats.open("gamestats.dat");
        gmStats<<"You have played "<<totGame<<" games."<<endl;
        gmStats<<"You have won "<<wins<<" games."<<endl;
        gmStats<<"You have lost "<<losses<<" games."<<endl;
        gmStats<<"You have earned $"<<earnings<<" total."<<endl;
        popular=((ecPlac>dozPlac&&ecPlac>strPlac)?1:0);
        if (popular==1){
            gmStats<<"Your most popular bet type was the Even Chances bet"
                    <<endl<<"which you placed "<<ecPlac<<" times(s)."<<endl;
        }
        popular=((dozPlac>ecPlac&&dozPlac>strPlac)?2:0);
        if (popular==2){
            gmStats<<"Your most popular bet type was the Dozens bet"
                    <<endl<<"which you placed "<<dozPlac<<" time(s)."<<endl;
        }
        popular=((strPlac>dozPlac&&strPlac>ecPlac)?3:0);
        if (popular==3){
            gmStats<<"Your most popular bet type was the Straight Bet"
                    <<endl<<"which you placed "<<ecPlac<<" time(s)."<<endl;
        }
        if (ecPlac==dozPlac&&dozPlac==strPlac){
            gmStats<<"You had no favorite bet last game."<<endl;
        }
        if (totGame>1){
        gmStats<<showpoint<<fixed<<setprecision(8);
        gmStats<<"For "<<totGame<<" spins played, the possibility of the same"
                <<" number"<<endl<<"repeating every round is %"<<posble<<endl;
        }
        gmStats<<showpoint<<fixed<<setprecision(2);
        if (totGame>0){
        gmStats<<"You have won "<<winPct<<"% of the games played."<<endl;
        }
        if ((gameOn(wins,losses)==true)&&earnings>0){
            gmStats<<"You are beating the casino, having won more than you have lost!"<<endl;
        }
        gmStats.close();    //Close gamestats file
        
    }while (endgame == 0);
}