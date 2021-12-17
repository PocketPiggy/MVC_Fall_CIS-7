/*
 * File:   Gamestate.h
 * Author: ling
 *
*/

#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>

//  Some lazy initialization instead of doing it at run time.
struct Gamestate {
    bool    gameStatus = false;    //  Sees if game is running or not.
    int     playerScore = 0;       //  Usuually I would do array but oh well
    int     dealerScore = 0;
};

#endif /* GAMESTATE_H */
