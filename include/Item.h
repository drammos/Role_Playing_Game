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