/*
 ******************************************************************************************************
 Title: Roulette Simulation
 File:Project1_shaswat_khan
 Name: Shaswat Pratap Khan
 Course: CSCI 501
 Due Date: Feb. 3rd . 2017
 Professor: Dr. Jordan Ringenberg
 Description:
         Roulette is a game in which participants place wagers regarding the outcome of a ball landing in one of 38 number(0-36,00) on a spinning wheel.
         The outcome of the wager decides whether the participant wins or loses. In this program, a special function is used to generate the random winning number.
         Participants get to decide what kind of betting they want to play for (Even, Odd , 1st half , 2nd half or exact guess) and accordingly, the winning amount 
         is calculated.
 
 Input: The inputs below will be received from the manual user input.
       - Kind of bet
       - wager amount
       - wager confirmation
       - exact number
       - Y/N Confirmation
       - Play again or not option.
 
 Output : Outputs that will be printed for the game:
       - Menu option
       - Kind of bet the participant selected
       - verdict of the game(WIN OR LOSE)
       - number of chips won or lost
       - number of chips left after recent bet
       - remaining chip at last
       - Message displaying after the game
 
    Wager can select from 1 to 36 in even, odd, 1st and 2nd half. While playing exact guess bet wager can guess  0 and 00 as well. Here in this program "00" is handled using integer -1.
 
 */



//library files

#include <iostream>
#include <iomanip>
#include <string>
#include <unistd.h>
#include <cstdlib>
#include <time.h>
using namespace std;


int main() {
    //variable declaration
    //sleeptime is used in order to give some delay time.
    const int SLEEPTIME      = 1000000;
    //initial balance
    const int initialBalance = 1000;
    int balance = 1000;
    int betOption;
    int amountWagered;
    string exactGuessStr;
    int exactguess;
    const int LOW   = -1;
    const int HIGH  = 36;
    bool continuePlaying  = true;
    char playAgain;
    char proceedConfirmation;
    // if the participant wants to play the game.
    while (continuePlaying) {
        //In order to generate a random winning number( ranging from -1 to 36) each game
        srand ( (unsigned) time(0) );
        int winningNum  = rand() % (HIGH - LOW + 1) + LOW;
      //cout << "winningNum::::" << winningNum << endl ;
        cout << "******************Welcome to Roulette************************";
        cout << "\n--------------------------------------------------------------------------------";
        cout << "\n|   Input   | " << "  Wager                                              |"  << " Payout     |";
        cout << "  --------------------------------------------------------------------------------";
        cout << "\n|     1     | " << " Even numbers ( 2, 4, 6,.......36)                   |"  << "  1 to 1    |";
        cout << "\n|     2     |  " << "Odd  numbers ( 1, 3, 5,.......35)                   |"  << "  1 to 1    |";
        cout << "\n|     3     |  " << "1st  half    ( 1, 2, 3,.......18)                   |"  << "  1 to 1    |";
        cout << "\n|     4     |  " << "2nd  half    (19,20,21,.......36)                   |"  << "  1 to 1    |";
        cout << "\n|     5     |  " << "Exact guess  ( 1-36, 0 ,  and 00)                   |"  << " 35 to 1    |";
        cout << "\n-------------------------------------------------------------------------------";
        // participant gets to choose which bet to play for
        cout << "\nWhat way you want to put your bets on:\n" ;
        cin  >> betOption;
        switch (betOption) {
            case 1:
                cout << "\n************* Okay !!!! Even bet it is *********************\n";
                cout << "\nPlace the amount of chips to wager:\n";
                cin  >>  amountWagered ;
                while(amountWagered > balance || amountWagered <= 0){
                    cout << "Wager Amount either more than balance or equal to or less than 0." << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                cout <<"\nYou have decided to wager " << amountWagered << " " << "on even numbers." << endl;
                cout << "Is this correct?" << endl;
                cout << "Enter 'Y' to proceed with game" << endl;
                cout << "OR enter 'N' to take back your wager:";
                cin  >> proceedConfirmation;
                if(proceedConfirmation == 'Y' || proceedConfirmation == 'y'){
                    /* when participant decides to play the game, roulette starts to roll. In order to make the game bit dramatic, functions like usleep is used.
                       usleep provides the delay you want to set. Next line of code is not executed until the delay time. flush function is used in order to clear the buffer memory.*/
                    
                    cout << "Roulette Rolling\n";
                    for(int i = 0 ; i < 3 ; i++){
                        cout << "." ;
                        cout.flush();
                        usleep(SLEEPTIME);
                    }
                    usleep(SLEEPTIME);
                if( winningNum % 2 != 0 || winningNum == 0) {
                    cout << "\n*************************************************************************";
                    cout << "\nSORRY!!!!, You lose " << amountWagered << " chips.\n";
                    balance = balance - amountWagered ;
                    cout << "\n*************************************************************************";
                }
                else{
                    cout << "\n*************************************************************************\n";
                    cout << "\nCONGRATULATIONS!!!!!!!!! You WIN"<< " " << amountWagered << " " << "chips.\n";
                    balance = amountWagered + balance ;
                }
                
                cout << "\nYour current chip balance is:" << balance << endl;
                }
                
                break;
            
            case 2:
                cout << "\n************* Okay !!!! Odd bet it is *********************\n";
                cout << "\nPlace the amount of chips to wager:\n";
                cin  >>  amountWagered ;
                while (amountWagered > balance || amountWagered <= 0) {
                    cout << "Wager Amount either more than balance or equal to or less than 0" << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                cout << "\nYou have decided to wager " << amountWagered << " " <<"on odd chips" << endl;
                cout << "Is this correct?" << endl;
                cout << "Enter 'Y' to proceed with game" << endl;
                cout << "OR enter 'N' to take back your wager:";
                cin  >> proceedConfirmation;
                if(proceedConfirmation == 'Y' || proceedConfirmation == 'y'){
                    cout << "Roulette Rolling\n";
                    for(int i = 0 ; i < 3 ; i++){
                        usleep(SLEEPTIME);
                        cout << ". " ;
                        cout.flush();
                    }
                    usleep(SLEEPTIME);
                    if( winningNum == -1 || winningNum % 2 == 0  ) {
                        cout << "\n*************************************************************************";
                       cout  << "\nSORRY!!!!, You lose " << amountWagered << " chips\n";
                        balance = balance-amountWagered ;
                        cout << "\n*************************************************************************";
                    }
                    else{
                        cout << "\n*************************************************************************\n";
                        cout << "\nCONGRATULATIONS!!!!!!!!! You WIN" << " " << amountWagered << " " << "chips.\n";
                        balance = amountWagered + balance ;
                    }
                    
                    cout << "\nYour current chip balance is:" << balance << endl;
                }
                break;
                
            case 3:
                cout << "\n************* Okay !!!! 1st half bet is ON *********************\n";
                cout << "\nPlace the amount of chips to wager:\n";
                cin  >>  amountWagered ;
                // checks whether the amount wagered is less than the balance or greater than 0.
                while(amountWagered > balance || amountWagered <= 0){
                    cout << "Wager Amount either more than balance or equal to or less than 0." << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                cout << "\nYou have decided to wager " << amountWagered << " " <<"on 1st half numbers" << endl;
                cout << "Is this correct?" << endl;
                cout << "Enter 'Y' to proceed with game" << endl;
                cout << "OR enter 'N' to take back your wager:";
                cin  >> proceedConfirmation;
                if(proceedConfirmation == 'Y' || proceedConfirmation == 'y'){
                    cout << "Roulette Rolling\n";
                    for( int i = 0;i < 3; i++){
                        cout << "." ;
                        cout.flush();
                        usleep(SLEEPTIME);
                    }
                    if(winningNum <= 0 || winningNum > 18) {
                        cout << "\n*************************************************************************";
                        cout << "\nSORRY!!!!, You lose " << amountWagered << " chips\n";
                        balance = balance-amountWagered ;
                        cout << "\n*************************************************************************";
                    }
                    else{
                        cout << "\n*************************************************************************\n";
                        cout << "\nCONGRATULATIONS!!!!!!!!! You WIN"<< " "<< amountWagered << " " << "chips.\n";
                        balance = amountWagered + balance ;
                    }
                    
                    cout << "\nYour current chip balance is:" << balance << endl;
                }
                break;
            case 4:
                cout << "\n************* Okay !!!! 2nd half bet is ON *********************\n";
                cout << "\nPlace the amount of chips to wager:\n";
                cin  >>  amountWagered ;
                while(amountWagered > balance || amountWagered <= 0){
                    cout << "Wager Amount either more than balance or equal to or less than 0." << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                cout << "\nYou have decided to wager " << amountWagered << " " << "on 2nd half numbers" << endl;
                cout << "Is this correct?" << endl;
                cout << "Enter 'Y' to proceed with game" << endl;
                cout << "OR enter 'N' to take back your wager:";
                cin  >> proceedConfirmation;
                if(proceedConfirmation == 'Y' || proceedConfirmation == 'y'){
                    cout << "Roulette Rolling";
                    for(int i = 0 ; i < 3; i++){
                        cout << "." ;
                        cout.flush();
                        usleep(SLEEPTIME);
                    }
                    /* As winning number cannot be more than 36, hence only lower limit(< 19) is handled, upper limit is handled by the random number generating function.*/
                    if( winningNum < 19) {
                        cout << "\n*************************************************************************";
                        cout << "\nSORRY!!!!, You lose " << amountWagered << " chips\n";
                        balance = balance-amountWagered ;
                        cout << "\n*************************************************************************";
                    }
                    else{
                        cout << "\n*************************************************************************\n";
                        cout << "\nCONGRATULATIONS!!!!!!!!! You WIN"<< " "<< amountWagered << " " << "chips.\n";
                        balance = amountWagered + balance ;
                    }
                    
                    cout << "\nYour current chip balance is:" << balance << endl;
                }
                break;
                
            case 5:
                cout << "\n************* Okay !!!! Exact guess bet is ON *********************\n";
                cout << "\nPlace the amount of chips to wager:\n";
                cin  >>  amountWagered ;
                if(amountWagered > balance) {
                    cout << "Insufficient chips." << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                else if( amountWagered < 0){
                    cout << "Wager amount must be greater than 0." << endl;
                    cout << "Please place the amount of wager in between 0 and balance:\n";
                    cin  >> amountWagered;
                }
                else{
                cout << "\nYou have decided to wager "<< amountWagered << " " <<"on exact guess chips";
                }
                cout << "\nPlease guess your number: ";
                cin  >> exactGuessStr;
                cout << "\n*************************************************************************\n";
                // checks whether guess number is between -1 to 36 or not.
                if(stoi(exactGuessStr) < -1 || stoi(exactGuessStr) > 36){
                    cout << "\nPlease guess the number correctly\n";
                    cout << "Your guess number should be from 0 to 36 or 00.\n";
                }
                else{
                    
                    /* if guess number is "00" then at backend this string value is converted to integer -1 else 
                       string format is simply converted to its integer format.
                     */
                    
                    if((exactGuessStr) == "00"){
                        exactguess = -1;
                        cout << "\nYou entered" << " " << exactGuessStr << " \nYou sure about the number? ";
                    
                    }
                    else{
                        exactguess = stoi(exactGuessStr);
                        cout << "\nYou entered" << " " << exactguess << " \nYou sure about the number? ";
                    }
                cout << "Enter 'Y' to proceed with game" << endl;
                cout << "OR enter 'N' to take back your wager:";
                cin  >> proceedConfirmation;
                if(proceedConfirmation == 'Y' || proceedConfirmation == 'y'){
                    cout << "Roulette Rolling\n";
                    for(int i = 0 ; i < 3 ; i++){
                        cout << "." ;
                        cout.flush();
                        usleep(SLEEPTIME);
                    }
                    usleep(SLEEPTIME);
                    if( exactguess != winningNum) {
                        cout << "\n*************************************************************************";
                        cout << "\nI am sorry, You Lose " << amountWagered << " chips.";
                        cout << "\nBETTER LUCK NEXT TIME" << endl;
                        balance = balance - amountWagered;
                        cout << "\n*************************************************************************";
                    }
                    else{
                         cout << "\nCONGRATULATIONS!!!!!!!!! You WIN" << " " << amountWagered * 35<< " " << "chips\n";
                         balance = (amountWagered * 35) + balance ;
                    }
                }
                    else{
                        cout << "\nYou said No\nThank you!!!!!!";
                        
                    }
                    }
                cout <<"\nYour current chip balance is " << balance << " chips\n";
                break;
                
            default:
                //when the bet option is not from 1 to 5
                cout << "Please enter the valid option from 1 to 5 to play.\n";
                break;
        }
        /* Balance less than zero can not proceed further to game. If participant decides to quit, then the overall win or loss is also tabulated along with message.
         */
        if(balance!=0){
            cout << "Play again? Y/N:";
            cin >> playAgain;
            if(playAgain != 'Y' && playAgain != 'y'){
                cout << "\n*********************************************************************\n";
                cout << "\nYour chip balance is " << balance << " chips.";
                if(balance > initialBalance){
                    cout << "\nCONGRATULATIONS, ON YOUR WIN..........\n";
                    cout << "YOU WIN " << balance - initialBalance << " chips" << endl;
                    
                }
                else if(balance < initialBalance){
                    cout << "\nHARD LUCK!!!!!!\n";
                    cout << "YOU LOST "<<  initialBalance - balance << " chips" << endl;
                }
                else{
                    cout << "\nYOU ARE LEVEL!!!!!\n";
                }
                cout <<"\n*********************************************************************\n";
                cout << "\nHope you had a wonderful time playing.\n";
                continuePlaying = false;
            }
            else{
                continuePlaying = true;
            }
        }
        else{
            cout << "Your chip balance is zero.\nSorry , You cannot proceed further with zero balance.\n ";
            continuePlaying = false;
        }
    }
    
    return 0;   //returns an integer type value
    
}




