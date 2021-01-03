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

    static const double point;

    //vector for spell and items
    vector <Spell*>spell_vector;

    vector <Item*>Weapon_vector;
    vector <Item*>Armor_vector;
    vector <Item*>Potion_vector;

    //Τα αντικειμενα που χρησιμοποιει ο Hero
    Item* weapon;
    Item* armor;
    Item* potion;

    //Οι συντεταγμένες του τετραγώνου που βρίσκεται ο ήρωας.
    int x;
    int y;
    
    public:
    
    Hero( string, double, double, double, double, double, double, string, int, int);
    
    double get_magicPower()const;
    double get_strength()const;
    double get_dexterity()const;
    double get_agility()const;
    double get_money()const;
    double get_experience()const;
    Item* get_Weapon()const;
    Item* get_Armor()const;
    Item* get_Potion()const;

    void set_strength( double);
    void set_dexterity( double);
    void set_agility( double);
    void add_money( double);
    void add_experience( double);
    void set_Weapon( int);
    void set_Armor( int);
    void set_Potion( Item*);
    

    //for level up
    virtual void level_up();

    //for buy spell and item
    void buy_Item( Item*);
    void buy_Spell( Spell*);

    //for sell spell and item
    bool sell_Item( int);
    bool sell_Spell( int);

    //print list for spell and item
    int print_spell()const;
    int print_item()const;

    int print_Weapon()const;
    int print_Armor()const;
    int print_Potion()const;

    void Take_Potion( int);

    void print_hero()const;

    int get_x() const;
    int get_y() const;

    void set_x(int);
    void set_y(int);

};


class Warrior : public Hero{
    static const double point_strength;
    static const double point_agility;

    public:

    Warrior( string, double, double, double, double, double, double, int, int);;

    void level_up();
};

class Sorcerer : public Hero{
    static const double point_dexterity;
    static const double point_agility;

    public:

    Sorcerer(  string, double, double, double, double, double, double, int, int);

    void level_up();

};

class Paladin : public Hero{
    static const double point_strength;
    static const double point_dexterity;

    public:

    Paladin(  string, double, double, double, double, double, double, int, int);

    void level_up();

};




//Monster

class Monster : public Living_Being{
    double attack;
    double defence;
    double probability_of_escape;

    static const double point;

    string monster;

    public:

    Monster( string, double, double, double, double, string);

    double get_attack()const;
    double get_defence()const;
    double get_probability_of_escape()const;

    void set_attack( double);
    void set_defence( double);
    void set_probability_of_escape( double);

    virtual void level_up();
};



class Dragon : public Monster{
    static const double point_attack;

    public:

    Dragon(string, double, double, double, double);

    void level_up();
};

class Exoskeleton : public Monster{
    static const double point_defence;

    public:

    Exoskeleton(string, double, double, double, double);

    void level_up();
};

class Spirit : public Monster{
    static const double point_probability_of_escape;

    public:

    Spirit(string, double, double, double, double);

    void level_up();
};




#endif