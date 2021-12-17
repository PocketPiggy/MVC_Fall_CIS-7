/*
 * File:        main.cpp
 * Author:      Matthew Mickey aka ling
 * Purpose:     Final project - Option #4: Blackjack. To demonstrate
 *              and show CIS-7 concepts within a C/C++ program.
*/

//  System Libraries
#include <iostream>  // Input/Output Library
#include <iomanip>   // Formatting Library
#include <cmath>     // Math Library
#include <cstdlib>   // C Standard Library
#include <string>    // String Library
#include <chrono>    // Required for sleep like function for all of C11++
#include <thread>    // Required for cross platform
#include <vector>    // Vector Library for ease of use

using namespace std;

//  User Libraries
//  These are all going to be simple structs rather than classes for simplicity
//  and ease of coding, technically, they can just be regular variables
#include "Cards.h"      //  Holds card data/info
#include "Entity.h"     //  Holds entity score & cards held data
//  Function Prototypes
void greeting();                //  Greeting for when game first starts
int  drawCard();                //  Rolls random number, draws card
void addScore(Entity *score);   //  Adds score
//void checkCard(Cards *pool, Entity *hand, int value);    //  Checks if card is available in pool/deck
//void checkCard(Cards *pool, vector<int> &, int);    //  Checks if card is available in pool/deck
int checkCard(Cards *pool, vector<int> &, int);    //  Checks if card is available in pool/deck
//void rmCardPool(Cards *pool, char type);   //  Removes card from pool
//void hitMeBaby(Cards *pool, Entity *hand);   //   Full draw card wrapper
void hitMeBaby(Cards *pool, Entity *hand, vector<int> playerCards, vector<int> cpuCards); //   Full draw card wrapper
//void hitMeBaby(Cards *pool, Entity *hand, vector<int> *playerCards); //   Full draw card wrapper
//void hitMeBaby(Cards *pool, Entity *hand, int cards[10]); //   Full draw card wrapper
void addHand(Entity *hand);                  // Adds card to hand

//  Main Program
int main(int argc, char** argv) {
    //  Set the random number seed
    srand(time(NULL));
    //  Initialize or input i.e. set variable values
    //greeting();
    Entity player;
    Entity cpu;
    Cards cards;
    //int playerCards[10];
    //int cpuCards[10];
    vector<int> playerCards;
    vector<int> cpuCards;

    bool gameStatus = true;     //  Checks if game is running
    int activeCard = 0;         //  Current card value drawn from deck

    //cout << player.score << endl;
    //addScore(&player);
    //cout << player.score << endl;

    //for (int i = 0; i < 40; i++) {
        //drawCard();
    //}

    //checkCard(&cards);

    //int keks = 0;
    //  Main gameplay loop
    //while (gameStatus) {
        //cout << keks << endl;
        //if (keks < 10) {
            //keks++;
        //}
        //else {
            //gameStatus = false;
        //}
    //}

    //cout << "Cards in aces pool: " << cards.acesP << endl;
    //rmCardPool(&cards, 'a');
    //cout << "Cards in aces pool: " << cards.acesP << endl;
    //cout << "Cards in numbers pool: " << cards.numberP << endl;
    for (int i = 0; i < 9; i++) {
        cout << "Cards in number " << (i + 2) << " pool: " << cards.numberP[i] << endl;
    }
    cout << "Cards in faces pool: " << cards.facesP << endl;
    cout << "Cards in aces pool: " << cards.acesP << endl;
    cout << endl << endl;

    hitMeBaby(&cards, &player, playerCards, cpuCards);
    cout << endl << endl;

    for (int i = 0; i < 9; i++) {
        cout << "Cards in number " << (i + 2) << " pool: " << cards.numberP[i] << endl;
    }
    cout << "Cards in faces pool: " << cards.facesP << endl;
    cout << "Cards in aces pool: " << cards.acesP << endl;
    cout << endl << endl;


    //cout << "Player hand is: "; << (*player).cardsHeld
    cout << "Player hand size is: " << playerCards.size() << endl;
    cout << "Player hand contains: ";
    //playerCards.push_back(1);
    //playerCards.push_back(3);
    //playerCards.push_back(10);
    //playerCards.push_back(4);
    //cout << "Player hand is: " << playerCards[0] << endl;
    for (int i = 0; i < playerCards.size(); i++) {
    //for (int i = 0; i < 10; i++) {
        cout << "[card#" << i << " "<< playerCards[i] << "] ";
    }
    cout << endl;
    //for (int i = 0; i < 20; i++) {
        //  If it's not a valid number
        //if ((player).cardsHeld[i] < 1 || (player).cardsHeld[i] > 13) {
            //break;
        //}
        //cout << *(player).cardsHeld << " ";
    //}

    //  Map inputs -> outputs

    //  Display the outputs
    return 0;
}

//  Functions
void greeting() {
    cout << "Hello and welcome to this program. It's just blackjack." << endl
         << "To play, press 1 to hit, 2 to stand." << endl
         << "After standing, game will end, and you'll need to restart the "
         << "program to play again." << endl << endl;
    cout << "With that in mind, let's begin!" << endl;
}

//void hitMeBaby(Cards *pool, Entity *hand, vector<int> playerCards, vector<int> cpuCards) {
void hitMeBaby(Cards *pool, Entity *hand, vector<int> playerCards, vector<int> cpuCards) {
    bool notDone = true;
    int tempCard = 0;
    int turns = 0;
    int scoreSum = 0;
    //  Rolls until it gets a valid card still in deck/pool
    while (notDone) {
        if (turns == 10) {
            notDone = false;
        }
        tempCard = drawCard();
        cout << "Result is: " << tempCard << "\tRunning score is: " << scoreSum << endl;
        //checkCard(pool, hand, tempCard);
        scoreSum += checkCard(pool, playerCards, tempCard);
        turns++;
    }
}

int drawCard() {
    int result = 0;
    result = (rand() % 13 + 1) % 14;
    //cout << "Result is: " << result << endl;
    return result;
}

void addHand(Entity *hand, Cards ) {
    //(*hand).cardsHeld
}

void addScore(Entity *score) {
    (*score).score++;
}

//void checkCard(Cards *pool, Entity *hand, int value) {
int checkCard(Cards *pool, vector<int> &playerCards, int value) {
    int result = 0;
    cout << endl << endl;
    for (int i = 0; i < playerCards.size(); i++) {
    //for (int i = 0; i < 10; i++) {
        cout << "[card#" << i << " "<< playerCards[i] << "] ";
    }

    //  Aces
    if (value == 1) {
        //  Checks if there are no more aces in deck/pool
        if ((*pool).acesP < 1) {
            cout << "No Aces." << endl;
        }
        else {
            (*pool).acesP--;
            playerCards.push_back(value);
            //return;
        }
    }
    //  Number cards 2 ~ 10
    if (value >= 2 && value <= 10) {
        //  Checks if there are no more numbers in deck/pool
        //  OH GOD PLEASE FORGIVE ME LOL WHY DID I DO THIS
        //if (value == 2) { if ((*pool).numberP[0] < 1) {cout << "No 2s." << endl;} else {(*pool).numberP[0]--;  (*hand).cardsHeld; return;}}   //  2
        //if (value == 2) { if ((*pool).numberP[0] < 1) {cout << "No 2s." << endl;} else {(*pool).numberP[0]--; playerCards.push_back(2); return;}}   //  2
        //if (value == 2) { if ((*pool).numberP[0] < 1) {cout << "No 2s." << endl;} else {(*pool).numberP[0]--; (*hand).cards.push_back(2); return;}}   //  2
        if (value == 2) { if ((*pool).numberP[0] < 1) {cout << "No 2s." << endl;} else {(*pool).numberP[0]--; playerCards.push_back(value); }}   //  2
        if (value == 3) { if ((*pool).numberP[1] < 1) {cout << "No 3s." << endl;} else {(*pool).numberP[1]--; playerCards.push_back(value); }}   //  3
        if (value == 4) { if ((*pool).numberP[2] < 1) {cout << "No 4s." << endl;} else {(*pool).numberP[2]--; playerCards.push_back(value); }}   //  4
        if (value == 5) { if ((*pool).numberP[3] < 1) {cout << "No 5s." << endl;} else {(*pool).numberP[3]--; playerCards.push_back(value); }}   //  5
        if (value == 6) { if ((*pool).numberP[4] < 1) {cout << "No 6s." << endl;} else {(*pool).numberP[4]--; playerCards.push_back(value); }}   //  6
        if (value == 7) { if ((*pool).numberP[5] < 1) {cout << "No 7s." << endl;} else {(*pool).numberP[5]--; playerCards.push_back(value); }}   //  7
        if (value == 8) { if ((*pool).numberP[6] < 1) {cout << "No 8s." << endl;} else {(*pool).numberP[6]--; playerCards.push_back(value); }}   //  8
        if (value == 9) { if ((*pool).numberP[7] < 1) {cout << "No 9s." << endl;} else {(*pool).numberP[7]--; playerCards.push_back(value); }}   //  9
        if (value == 10) { if ((*pool).numberP[8] < 1) {cout << "No 10s." << endl;} else {(*pool).numberP[8]--; playerCards.push_back(value); }}   //  10
    }
    //  Face cards
    if (value >= 11 && value <= 13) {
    //  Checks if there are no more faces in deck/pool
        if ((*pool).facesP < 1) {
            cout << "No Faces." << endl;
        }
        else {
            (*pool).facesP--;
            playerCards.push_back(value);
            //return;
        }
    }
    result = value;
    //for (int i = 0; i < playerCards.size(); i++) {
        //cout << "CHECKCARD: playerCards-" << playerCards[i];
    //}
    return result;
}

//void rmCardPool(Cards *pool, char type) {
    //switch (type) {
        //case 'n':
            //(*pool).numberP--;
            //break;
        //case 'f':
            //(*pool).facesP--;
            //break;
        //case 'a':
            //(*pool).acesP--;
            //break;
        //default:
            //cout << "Something broke!" << endl;
            //break;
    //}
//}
