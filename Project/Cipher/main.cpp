/*
 * File:        main.cpp
 * Author:      Matthew Mickey
 * Purpose:     Final Project - Option #3: Cipher. To demonstrate and show
 *              CIS-7 concepts within a C/C++ program.
*/

//System Libraries
#include <iostream>  //Input/Output Library

using namespace std;

//Function Prototypes
string initPassKey(string, string); //  Initializes key

string initPassKey(string passKey, string text) {
    int temp = text.size();         //  Gets the length of the string
    int tempKey = passKey.size();   //  Gets length of the key
    int cursor = 0;                 //  Current selection on vin. table

    //  Checks and moves around to initialize key
    while (cursor < temp) {
        //  If the cursor is the same as the size limit, make it 0
        if (cursor == temp) {
            cursor = 0;
        }
        //  If same size, then done since finished moving
        else if (temp == tempKey) {
            //cursor = temp+1;
            break;
        }
        //  Increment since not done
        cursor++;
    }
    //for (int cursor = 0; cursor < temp; cursor++) {
        ////  If the cursor is the same as the size limit, make it 0
        //if (cursor == temp) {
            //cursor = 0;
        //}
    //}
    return passKey;
}

string encrypt(string, string); //  Encrypts user input
string encrypt(string passKey, string text) {
    //  
    string temp = "";

    for (int i = 0; i < )
}

//Execution Begins Here!
int main(int argc, char** argv) {
    //Set the random number seed

    //Declare Variables

    //Initialize or input i.e. set variable values


    //  Map inputs -> outputs

    //Display the outputs


    //Exit stage right or left!
    return 0;
}
