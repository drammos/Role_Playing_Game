#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "information.h"

using namespace std;

class Item{
    string name;
    double price;
    int level;
    string kind_of_item;
public:
    Item(string, double, int, string);
    virtual ~Item();
    string get_name() const;
    double get_price() const;
    int get_level() const;
    void print();
    string get_kind_of_item() const;
    virtual double get_damage() const;
};

class Weapon:public Item{
    int hands;
    double damage;
public:
    Weapon(string, double, int, int, double);
    ~Weapon(){};
    //returns the number of the hands a weapon needs to be held.
    int get_hands() const;
    double get_damage() const;
};

class Armor:public Item{
    double reduce_of_damage;
public:
    Armor(string, double, int, double);
    ~Armor(){};
    double get_reduce_of_damage() const;
};

class Potion:public Item{
    //The characteristic that the potion has an impact on.
    string characteristic;
    //The amount of the increase of that characteristic.
    double increase;
public:
    Potion(string, double, int, string, double);
    ~Potion();
    string get_characteristic() const;
    double get_increase() const;
};

#endif