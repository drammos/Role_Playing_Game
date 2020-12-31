#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "Living_Being.h"

using namespace std;

class Square;

class Grid{

    //Διαστασεις πλεγματος
    int x;
    int y;
    Square*** squares;

public:    
    Grid( int, int);
    ~Grid();

    //
    void checkInventory( Hero*);
    void equip( Hero*);
    void use( Hero*);
    void print_Hero( Hero*)const;
    void displayMap()const;
};

class Square{
    vector < Hero* > heroes;
    vector < Monster* > monsters;
    string kind_of_square;
public:
    Square(string);
    ~Square();
    void add_hero(Hero*);
    void add_monster(Monster*);
    void remove_heroes();
    string get_kind_of_square() const;
};

class nonAccessible:public Square{

public:
    nonAccessible():Square("nonAccessible"){};
};

class Market:public Square{
    vector <Item*> items;
    vector <Spell*> spells;
public:
    Market():Square("Market"){};
    ~Market();
    void insert_item(Item*);
    void insert_spell(Spell*);
    void buy(Hero*);
    void sell(Hero*);
};

class Common:public Square{

public:
    Common():Square("Common"){};
};





#endif