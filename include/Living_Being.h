#ifndef LIVING_BEING_H
#define LIVING_BEING_H

#include <string>
#include <vector>
#include "Item.h"
#include "Spell.h"
using namespace std;

class Living_Being{
    string name;
    int level;
    double healthPower;

    string life_being;
    bool in_life;
    
    public:

    Living_Being( string, double, string);

    virtual void level_up();

    //get
    string get_name()const;
    double get_healthPower()const;
    int get_level()const;

};


class Hero : public Living_Being{
    double magicPower; //ποσο μαγικης ενεργειας
    double strength;  //τιμη δυναμης
    double dexterity; //τιμη επιδεξιοτητας
    double agility;   //τιμης ευκυνισιας

    double money;     //ποσο χρηματων που διαθετει ο ηρωας
    double experience; //ποσο εμπειριας ηρωα

    //who hero
    string hero;

    static const double point = 1;

    //vector for spell and items
    vector <Item>item_vector;
    vector <Spell>spell_vector;

    public:
    
    Hero( string, double, double, double, double, double, double, string);
    
    double get_magicPower()const;
    double get_strength()const;
    double get_dexterity()const;
    double get_agility()const;
    double get_money()const;
    double get_experience()const;

    void set_strength( double);
    void set_dexterity( double);
    void set_agility( double);
    void set_money( double);
    void set_experience( double);
    

    //for level up
    virtual void level_up();

    //for buy spell and item
    void buy_Item( Item item);
    void buy_Spell( Spell spell);

    //for sell spell and item
    bool sell_Item( Item item);
    bool sell_Spell( Spell spell);


};


class Warrior : public Hero{
    static const double point_strength = 0.8;
    static const double point_agility = 0.5;

    public:

    Warrior( string, double, double, double, double, double, double);;

    void level_up();
};

class Sorcerer : public Hero{
    static const double point_dexterity = 0.7;
    static const double point_agility = 0.6;

    public:

    Sorcerer(  string, double, double, double, double, double, double);

    void level_up();

};

class Paladin : public Hero{
    static const double point_strength = 0.9;
    static const double point_dexterity = 0.7;

    public:

    Paladin(  string, double, double, double, double, double, double);

    void level_up();

};




//Monster

class Monster : public Living_Being{
    double attack;
    double defence;
    double probability_οf_escape;

    string monster;

    public:

    Monster( string, double, double, double, double, string);

    double get_attack()const;
    double get_defence()const;
    double get_probability_of_escape()const;

};



class Dragon : public Monster{
    static const double point_attack = 0.6;

    public:

    Dragon(string, double, double, double, double);

};

class Exoskeleton : public Monster{
    static const double point_defence= 0.7;

    public:

    Exoskeleton(string, double, double, double, double);
};

class Spirit : public Monster{
    static const double point_probability_οf_escape = 0.8;

    public:

    Spirit(string, double, double, double, double);
};




#endif