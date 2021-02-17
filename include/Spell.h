#ifndef SPELL_H
#define SPELL_H

#include <iostream>
#include "information.h"

using namespace std;


class Spell{
    string name;
    double price;
    int level;
    double damage_low;
    double damage_high;

    double energy;
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
    void print();

    virtual double get_damage()const;
    virtual int get_rounds()const;
    string get_kind_of_spell() const;
};

class IceSpell:public Spell{
    //PROBABILITY!!!
    double damage_low_new;
    int rounds; 
public:
    IceSpell(string, double, int, double, double, double, double, int);
    ~IceSpell(){};
    double get_damage() const;
    int get_rounds() const;
};

class FireSpell:public Spell{
    double defense_reduce;
    int rounds;
public:
    FireSpell(string, double, int, double, double, double, double, int);
    ~FireSpell(){};
    double get_damage() const;
    int get_rounds() const;
};

class LightingSpell:public Spell{
    //PROBABILITY!!!
    double defense_prob_reduce;
    int rounds;
public:
    LightingSpell(string, double, int, double, double, double, double, int);
    ~LightingSpell(){};

    double get_damage() const;
    int get_rounds() const;


}; 

#endif