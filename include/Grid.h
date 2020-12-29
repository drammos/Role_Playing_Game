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


    public:
    
    Grid( int, int);

};

class Square{
    double x;
public:
    Square(double);
};

class nonAccessible:public Square{
    
};

class Market:public Square{
    
};

#endif