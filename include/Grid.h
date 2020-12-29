#include <iostream>
#include <vector>
#include "items.h"
#include "Living_Being.h"

using namespace std;

class Grid{
    double x;
    double y;

};

class Square{
    double x;
};

class nonAccessible:public Square{
    
};

class Market:public Square{
    
};