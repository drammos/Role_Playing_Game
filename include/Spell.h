#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "information.h"

using namespace std;


class Spell{
    string name;
    double price;
    int level;
    //damage range.
    double damage_low;
    double damage_high;
    double energy;
    //IceSpell, LightingSpell or FireSpell.
    string kind_of_spell;
public:
    Spell(string, double, int, double, double, double, string);
    ~Spell();
    string get_name() const;
    double get_price() const;
    int get_level() const;
    double get_low_damage() const;
    double get_high_damage() const;
    double get_energy() const;
    void set_low_damage(double);
    //Prints the info of the Spell.
    void print();
    virtual double get_damage()const;
    virtual int get_rounds()const;
    string get_kind_of_spell() const;
};

class IceSpell:public Spell{
    //percentage of the increase of the lower bound of the damage range.
    double damage_low_new;
    //The number of rounds that the spell is going to have an impact on.
    int rounds; 
public:
    IceSpell(string, double, int, double, double, double, double, int);
    ~IceSpell(){};
    double get_damage() const;
    int get_rounds() const;
};

class FireSpell:public Spell{
    //percentage of the decrease of the opponent's defence.
    double defense_reduce;
    //The number of rounds that the spell is going to have an impact on.
    int rounds;
public:
    FireSpell(string, double, int, double, double, double, double, int);
    ~FireSpell(){};
    double get_damage() const;
    int get_rounds() const;
};

class LightingSpell:public Spell{
    //Percentage of the decrease of the oponent's probability of escape.
    double defense_prob_reduce;
    //The number of rounds that the spell is going to have an impact on.
    int rounds;
public:
    LightingSpell(string, double, int, double, double, double, double, int);
    ~LightingSpell(){};

    double get_damage() const;
    int get_rounds() const;


}; 

#endif