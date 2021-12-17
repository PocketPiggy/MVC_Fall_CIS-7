/*
 * File:   Entity.h
 * Author: ling
*/

#ifndef ENTITY_H
#define ENTITY_H
#include <vector>
struct Entity {
    int     score = 0;
    //  Instead of bothering with vectors, which I usually prefer, since there
    //  is no need for optimization, I've elected to just allocate more memory
    //  instead
    int     cardsHeld[20] = {13};
    std::vector<int>     cards;
};


#endif /* ENTITY_H */
