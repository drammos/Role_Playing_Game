#include <iostream>
#include "Item.h"

using namespace std;

//Συναρτήσεις για Item.
Item::Item(string n, double p, int l, string s){
    this->name.assign(n);
    this->price = p;
    this->level = l;
    this->kind_of_item.assign(s);
}

Item::~Item(){
    this->name.clear();
    this->kind_of_item.clear();
}

string Item::get_name() const{
    return this->name;
}

double Item::get_price() const{
    return this->price;
}

int Item::get_level() const{
    return this->level;
}

void Item::print(){
    cout<<"This is a "<<this->kind_of_item<<endl;
    cout<<"Name is: "<<this->name<<", price is: "<<this->price<<", the required leve is: "<<this->level<<endl;
}

string Item::get_kind_of_item() const{
    return this->kind_of_item;
}

double Item::get_damage() const{
    return 0.0;
}

// // Βοηθητική virtual συνάρτηση.

// part Item::get_prices()const
// {
//     part p;
//     p.hands = 0;
//     p.characteristic = "NOTHING";
//     p.power = 0.0;

//     return p;
// }


//Συναρτήσεις για Weapon.
Weapon::Weapon(string n, double p, int l, int h, double d):Item(n, p, l, "Weapon"){
    this->hands = h;
    this->damage = d;
}

int Weapon::get_hands() const{
    return this->hands;
} 

double Weapon::get_damage() const{
    return this->damage;
}

// part Weapon::get_prices()const
// {
//     part p;
//     p.hands = hands;
//     p.characteristic = "NOTHING";
//     p.power = damage;
//     return p;
// }


//Συναρτήσεις για Armor.
Armor::Armor(string n, double p, int l, double d):Item(n, p, l, "Armor"){
    this->reduce_of_damage = d;
}

double Armor::get_reduce_of_damage() const{
    return this->reduce_of_damage;
}

// part Armor::get_prices()const
// {
//     part p;
//     p.hands = -1;
//     p.characteristic = "NOTHING";
//     p.power = reduce_of_damage;
//     return p;
// }


//Συναρτήσεις για Potion.
Potion::Potion(string n, double p, int l, string c, double i):Item(n, p, l, "Potion"){
    this->characteristic.assign(c);
    this->increase = i;
}

Potion::~Potion(){
    this->characteristic.clear();
}

string Potion::get_characteristic() const{
    return this->characteristic;
}

double Potion::get_increase() const{
    return this->increase;
}

// part Potion::get_prices()const
// {
//     part p;
//     p.hands = -1;
//     p.characteristic = characteristic;
//     p.power = increase;
//     return p;
// }
