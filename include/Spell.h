#include <iostream>

using namespace std;

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