/*
 * File:   Cards.h
 * Author: ling
*/

#ifndef CARDS_H
#define CARDS_H

//  No where in requirements/instructions required face differentiation,
//  so I'm just gonna simplify this by pooling all the card types together and
//  just turn suits into the amount of the types left in the card pool/deck
struct Cards {
    int numbers[9] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
    int faces[3]   = {10, 10, 10};
    int aces[3]    = {11, 11, 11};     //  Techinically string would be easier
                                    //  then parse with function to treat after
    //  With this in mind, all I need to do is use a function to manipulate or
    //  rather, subtract the value every time one of these is drawn. That way
    //  when getting the random card, there's no worry.
    //int numberP = 4;
    //int facesP  = 4;
    //int acesP   = 4;
    int numberP[9] = {4, 4, 4, 4, 4, 4, 4, 4, 4};
    int facesP     = 12;
    int acesP      = 4;
};


#endif /* CARDS_H */
