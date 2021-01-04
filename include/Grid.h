#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "Living_Being.h"

using namespace std;

const int MAX_LEVEL = 5;
double MONEY = 5.0;
double EXPERIENCE = 3.0;
double NEEDED_EXPERIENCE = 10.0;

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
    void move(Hero*);
    void quitGame();

    void War( Square*);
};

class Square{
    string kind_of_square;
    vector < Hero* > heroes;
    vector < Monster* > monsters;
public:
    Square(string);
    virtual ~Square();
    void add_hero(Hero*);
    void add_monster(Monster*);
    vector <Hero*> remove_heroes();
    string get_kind_of_square() const;
    virtual int contains();

};

class nonAccessible:public Square{

public:
    nonAccessible():Square("nonAccessible"){};
    int contains();
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
    int contains();
};

class Common:public Square{


public:
    Common():Square("Common"){};
    int contains();
};





#endif