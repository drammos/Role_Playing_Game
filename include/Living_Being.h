#ifndef LIVING_BEING_H
#define LIVING_BEING_H

#include <string>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "information.h"

using namespace std;


class Living_Being{
    string name;
    int level;
    double healthPower;

    //Kind of living being (hero or monster).
    string life_being;
    bool in_life;
    
    public:

    Living_Being( string, string);

    virtual void level_up();

    //get
    string get_name()const;
    double get_healthPower()const;
    int get_level()const;

    //Changes the healthpower.
    void set_healthPower( double);
    //Adds to the healthpower.
    void add_healthPower(double);

    //Prints the info of the living being.
    virtual void displayStats();
};

class Monster;

class Hero : public Living_Being{
    double magicPower;
    //The three following characteristic have an upper bound of 100.
    double strength;
    double dexterity;
    double agility;

    double money;
    double experience;

    //kind of hero (warrior, sorcerer or paladin).
    string hero;

    static const double point;

    //vector for spell and items
    vector <Spell*>spell_vector;

    vector <Item*>Weapon_vector;
    vector <Item*>Armor_vector;
    vector <Item*>Potion_vector;

    //The items that the hero currently uses.
    Item* weapon;
    Item* armor;
    Item* potion;

    //Coordinates of the square the hero is at.
    int x;
    int y;

    //Number of items and spells.
    int count_item_and_spell;
    
    public:
    
    Hero( string, double, double, double, string, int, int);
    
    double get_magicPower()const;
    double get_strength()const;
    double get_dexterity()const;
    double get_agility()const;
    double get_money()const;
    double get_experience()const;
    Item* get_Weapon()const;
    Item* get_Armor()const;
    Item* get_Potion()const;
    //Returns the kind of the hero in a string.
    string get_hero()const;
    int get_count_item_and_spell()const;

    void set_strength( double);
    void set_dexterity( double);
    void set_agility( double);
    //Adds money.
    void add_money( double);
    //Subtructs money.
    void sub_money( double);
    void set_money(double);
    void add_experience( double);
    void set_Weapon( int);
    void set_Armor( int);
    void set_Potion( Item*);
    void add_magicPower(double);
    

    //for level up
    virtual void level_up();

    //for buy spell and item
    void buy_Item( Item*);
    void buy_Spell( Spell*);

    //for sell spell and item
    bool sell_Item(unsigned int);
    bool sell_Spell( int);

    //print list for spell and item
    int print_spell()const;
    int print_item()const;

    int print_Weapon()const;
    int print_Armor()const;
    int print_Potion()const;

    void Take_Potion( int);

    //Prints the info of the hero.
    void print_hero()const;

    //The two following functions return thw coordinates of the hero.
    int get_x() const;
    int get_y() const;

    //Change the coordinates of the hero.
    void set_x(int);
    void set_y(int);

    //Prints info of the hero.
    virtual void displayStats();

    void attack( Monster*);
    bool castSpell( Monster*);
};


class Warrior : public Hero{
    //Percentage of the increase of the strength.
    static const double point_strength;
    //Percentage of the increase of the agility.
    static const double point_agility;

    public:

    Warrior( string, double, double, double, int, int);;

    void level_up();

    void diplayStats();
};

class Sorcerer : public Hero{
    //Percentage of the increase of the dexterity.
    static const double point_dexterity;
    //Percentage of the increase of the agility.
    static const double point_agility;

    public:

    Sorcerer(  string, double, double, double, int, int);

    void level_up();

    void displayStats();
};

class Paladin : public Hero{
    //Percentage of the increase of the strength.
    static const double point_strength;
    //Percentage of the increase of the dexterity.
    static const double point_dexterity;

    public:

    Paladin(  string, double, double, double, int, int);

    void level_up();

    void displayStats();
};




//Monster

class Monster : public Living_Being{
    
    //Damage range.
    double damage_low;
    double damage_high;
    double defence;
    double probability_of_escape; //[0,100]

    //Original damage range.
    double original_damage_low;
    double original_damage_high;
    double original_defence;
    double original_probability_of_escape; //[0,100]
    double rounds;
    
    //percentage.
    static const double point;

    string monster;

    public:

    Monster( string, double, double, double, double, string);

    double get_damage_low()const;
    double get_damage_high()const;
    double get_defence()const;
    double get_probability_of_escape()const; //[0,100]
    int get_rounds()const;

    void set_damage( double, double);
    void set_defence( double);
    void set_probability_of_escape( double);
    void set_rounds( int);

    //Assisting function for when the fields must be reset.
    void reset_fields();

    //Prints the info about the monster.
    void print_monster();

    virtual void level_up();

    virtual void displayStats();

    void attack(Hero*);
};



class Dragon : public Monster{
    //percentage of the increase of the attack.
    static const double point_attack;

    public:

    Dragon(string, double, double, double, double);

    void level_up();

    void displayStats();
};

class Exoskeleton : public Monster{
    //percentage of the increase of the defence.
    static const double point_defence;

    public:

    Exoskeleton(string, double, double, double, double);

    void level_up();

    void displayStats();
};

class Spirit : public Monster{
    //percentage of the increase of the probability of escape.
    static const double point_probability_of_escape;

    public:

    Spirit(string, double, double, double, double);

    void level_up();

    void displayStats();
};




#endif