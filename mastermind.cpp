/* 
Name: Michael Gunter
Course: CGS 3406
Assignment: Assignment #3
About this Project: A fun mini-game
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

// function PROTOTYPES are included here.

void GenerateSequence(int & a, int & b, int & c);
bool IsHit(int x, int y);
int NumMatches(int u, int v, int w, int x, int y, int z);
 
int main(){

    bool replayVerify = false; // this variable is to determine if the user wants to play again.
    bool exitGame = false; // this variable is to determine if the user wants to exit.

    do {

        // the three target variables represents the sequence of numbers used for game.
        int target1 = 0;
        int target2 = 0;
        int target3 = 0;

        // three input variables used for the user's input in the game.
        int input1 = 0;
        int input2 = 0;
        int input3 = 0;

        // roundCount is the counter for number of rounds
        int roundCount = 0;

        // numHits refers to the number of hits. Useful for the while loop "while numHits != 3"
        int numHits = 0;

        // matchCount refers to the number of matches
        int matchCount = 0;

        // user input that determines if they would like to play the game again.
        char replayInput = ' '; 
        // introduce user to the program
        cout << "~~~~~Welcome to the Game!~~~~~" << endl;

        // After this function call, the values of targets 1-3 will contain unique
        // random numbers between 1 and 7.
        GenerateSequence(target1, target2, target3);

        // print content to the command line
        cout << "Numbers selected. You'll never guess them!" << endl;

        while (numHits != 3){
            roundCount++; // increment round number by one
            numHits = 0; // value gets reset after every failed round.
            matchCount = 0; // value gets reset after every failed round.
            cout << "\nRound " << roundCount << ":" << endl;

            do { 
                /* continue to prompt the user for their guesses if they provide
                   duplicate values
                */

                // prompt the user for input
                cout << "Please input your guesses in order: ";
                cin >> input1 >> input2 >> input3;
                cout << "--------------------------------------------------" << endl;
                cout << "\n";


                // if the user provides duplicate input, then notify them.
                if (input1 == input2 || input2 == input3 || input1 == input3){
                    cout << "Invalid input. You cannot have duplicate values. Please try again." << endl;
                }

            } while (input1 == input2 || input2 == input3 || input1 == input3);

            if (IsHit(input1, target1) == 1){ // if there is a hit, increment numHits by one
                numHits++;
            }
            if (IsHit(input2, target2) == 1){ // if there is a hit, increment numHits by one
                numHits++;
            }
            if (IsHit(input3, target3) == 1){ // if there is a hit, increment numHits by one
                numHits++;
            }
            matchCount = NumMatches(input1, input2, input3, target1, target2, target3);
            cout << numHits << " hits" << endl;
            cout << matchCount << " matches." << endl;

            if (numHits == 3){
                // congratulate the user for getting all three hits correct on round 1.
                if (roundCount == 1){
                    cout << "\n*****Congratulations! You won the game! It only took you 1 round!*****" << endl;
                } else {
                    // congratulate the user for getting all three hits correct on round 2 or later.
                    cout << "\n*****Congratulations! You won the game! It only took you " << roundCount << " rounds!*****" << endl;
                }

            } else {
                cout << "\nToo bad. You guessed wrong." << endl;
                cout << "--------------------------------------------------" << endl;
            }
        }

        // keep asking the user for valid input if they provide invalid input
        do {
            // ask the user if they would like to play again    
            cout << "Do you want to play again? ";
            cin >> replayInput;
            cout << endl;
            if (replayInput == 'N' || replayInput == 'n'){
                cout << "See you next time!" << endl;
                cout << "--------------------------------------------------" << endl;
                exitGame = true;
            } else if (replayInput == 'y' || replayInput == 'Y'){
                // no code necessary due to the while in line.
                // the program should restart since the user picked "yes"
            } else { // In the case of invalid input
                cout << "\nInvalid input. Please try again.\n" << endl;
            }

            if (replayInput == 'y' || replayInput == 'Y'){
                replayVerify = true; // changes value to true if the user wants
            }

        } while (replayVerify == false && exitGame == false); // keep asking the user questions if they didn't type 'y'

    } while (replayVerify == true && exitGame == false); 
    /* restart the game if the user wants to play again and does 
       not want to exit.
    */
    
    return 0;
}

void GenerateSequence(int & a, int & b, int & c){ // use
    // set up random number generator
    srand(time(0));	
    
    int first = 0;
    int second = 0;
    int third = 0;
    
    // generate three unique numbers between 1 and 7 (refer to the "Random Number Generator" slides)

    do {
        first = rand() % 7 + 1;
        second = rand() % 7 + 1;
        third = rand() % 7 + 1;
    } while (first == second || second == third || first == third ); 
    // no two numbers in the sequence should be equal, so we will do a do/while loop.

    // make changes to the original variables passed in.

    a = first;
    b = second;
    c = third;

}

bool IsHit(int x, int y){
    // this function tests to see if there are hits.

    if (x == y){ // if x is equal to y, set the return value of function IsHit() to true...
        return true;
    } else { // otherwise, set the return value to false.
        return false;
    }

}

int NumMatches(int u, int v, int w, int x, int y, int z){ 
    /* this function takes three values ( u, v, and w) and tests to see
     if there are matches. If there is a match increment matchCount by 1.
    */

    int matchCount = 0; // counter for the number of matches

    if (u == y || u == z ){ // if 'u' matches the second group
        matchCount++;
    }

    if (v == x || v == z ){ // if 'v' matches the second group
        matchCount++;
    }

    if (w == x || w == y ){ // if 'w' matches the second group
        matchCount++;
    }
    return matchCount;
}