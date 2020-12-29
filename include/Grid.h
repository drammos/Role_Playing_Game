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
    double x;
    double y;


    public:
    
    Grid( double, double);

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