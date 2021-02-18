#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "Living_Being.h"
#include "information.h"

using namespace std;


class Square;

class Grid{

    //Dimensions.
    int x;
    int y;

    //Two-dimensional matrix of the squares of the grid.
    Square*** squares;

    //Coordinates of the square the heroes are at.
    int x_heroes;
    int y_heroes;

    //Prints the items and spells a hero has.
    void checkInventory( Hero*);
    //Change of the weapon or armor a hero uses at a certain time.
    void equip( Hero*);
    //Use of a potion.
    void use( Hero*);
    //Prints info about the hero.
    void print_Hero( Hero*)const;
    //Movement to one of the up, down, left, right squares if they are accessible.
    void move(vector <Hero*>);
    void quitGame();
    //Prints the grid.
    void displayMap()const;
    //Assisting function.
    void buy_sell_and_equip( Hero*);
    
public:    
    Grid( int, int);
    ~Grid();
    //Puts the heroes in the grid.
    void set_heroes( Hero*);
    //Puts the monsters in the grid.
    void set_monsters( Monster*);
    //Making of the game.
    void StartGame();
    //Supply of the market with items.
    void provide(Item*);
    //Supply of the market with spells.
    void provide(Spell*);
};

class Square{
    //Market, nonAccesible or Common.
    string kind_of_square;
    //Heroes in the square.
    vector < Hero* > heroes;
    //Monsters in the square.
    vector < Monster* > monsters;
public:
    Square(string);
    virtual ~Square();
    //Adds heroes to the square.
    void add_hero(Hero*);
    //Adds monsters to the square.
    void add_monster(Monster*);
    //Removes heroes from the square..
    vector<Hero*> remove_heroes();
    //Returns the kind of the square.
    string get_kind_of_square() const;
    //Returns an integer depending on the number of heroes and monsters in the square.
    virtual int contains();
    //Returns an integer depending on the number of heroes and monsters alive in the square.
    int alive();
    void War();

    virtual bool buy( Hero*);
    virtual void sell( Hero*);
    //Assisting
    virtual void insert_item(Item*){};
    virtual void insert_spell(Spell*){};

    //Returns the heroes of the square.
    vector<Hero*> get_heroes();
};

class nonAccessible:public Square{

public:
    nonAccessible():Square("nonAccessible"){};
    //Same as the superclass.
    int contains();
};

class Market:public Square{
    vector <Item*> items;
    vector <Spell*> spells;
public:
    Market():Square("Market"){};
    ~Market();
    //Inserts items in the market.
    void insert_item(Item*);
    //Inserts spells in the market.
    void insert_spell(Spell*);
    bool buy(Hero*);
    void sell(Hero*);
    //Same as the superclass.
    int contains();
};

class Common:public Square{


public:
    Common():Square("Common"){};
    //Same as the superclass.
    int contains();
};





#endif