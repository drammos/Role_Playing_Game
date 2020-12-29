#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "Living_Being.h"

using namespace std;

class Grid{

    //Διαστασεις πλεγματος
    int x;
    int y;
    Square*** squares;


    public:
    
    Grid(int, int);

};

class Square{
    vector < Hero* > heroes;
    vector < Monster* > monsters;
public:
    Square(){};
    void add_hero(Hero*);
    void add_monster(Monster*);
};

class nonAccessible:public Square{

public:
    nonAccessible(){};
    
};

class Market:public Square{
    
public:
    Market(){};
};

class Common:public Square{

public:
    Common(){};
};

#endif