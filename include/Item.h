#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include "information.h"

using namespace std;

struct part{
    int hands;
    string characteristic;
    double power;
};

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

    virtual part get_prices()const;
};

class Weapon:public Item{
    int hands;
    double damage;
public:
    Weapon(string, double, int, int, double);
    ~Weapon(){};
    int get_hands() const;
    double get_damage() const;

    part get_prices()const;
};

class Armor:public Item{
    double reduce_of_damage;
public:
    Armor(string, double, int, double);
    ~Armor(){};
    double get_reduce_of_damage() const;

    part get_prices()const;
};

class Potion:public Item{
    string characteristic;
    double increase;
public:
    Potion(string, double, int, string, double);
    ~Potion();
    string get_characteristic() const;
    double get_increase() const;

    part get_prices()const;
};

#endif