#include <iostream>

using namespace std;

class Item{
    string name;
    double price;
    int level;
public:
    Item(string, double, int);
    ~Item();
    string get_name() const;
    double get_price() const;
    int get_level() const;
};

class Weapon:public Item{
    int hands;
    double damage;
public:
    Weapon(string, double, int, int, double);
    ~Weapon();
    int get_hands() const;
    double get_damage() const;
};

class Armor:public Item{
    double reduce_of_damage;
public:
    Armor(string, double, int, double);
    ~Armor();
    double get_reduce_of_damage() const;
};

class Potion:public Item{
    string characteristic;
    double increase;
public:
    Potion(string, double, int, string, double);
    ~Potion();
    string get_characteristic() const;
    double get_increase() const;
};

class Spell{
    string name;
    double price;
    int level;
    double damage_low;
    double damage_high;
    double energy;
public:
    Spell(string, double, int, double, double, double);
    ~Spell();
    string get_name() const;
    double get_price() const;
    int get_level() const;
    double get_low_damage() const;
    double get_high_damage() const;
    double get_energy() const;
    void set_low_damage(double);
};

class IceSpell:public Spell{
    double damage_low_new;
    int rounds; 
public:
    IceSpell(string, double, int, double, double, double, double, int);
    ~IceSpell();
    double get_new_low() const;
    int get_rounds() const;
};

class FireSpell:public Spell{
    double defense_reduce;
    int rounds;
public:
    FireSpell(string, double, int, double, double, double, double, int);
    ~FireSpell();
    double get_defense_reduce() const;
    int get_rounds() const;
};

class LightingSpell:public Spell{
    double defense_prob_reduce;
    int rounds;
public:
    LightingSpell(string, double, int, double, double, double, double, int);
    ~LightingSpell();
    double get_defense_prob_reduce() const;
    int get_rounds() const;
}; 