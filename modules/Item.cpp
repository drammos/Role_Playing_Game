#include <iostream>
#include "Item.h"

using namespace std;

//Item functions
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
    cout<<"Name: "<<this->name<<", Price: "<<this->price<<", Required Level: "<<this->level<<endl;
}

string Item::get_kind_of_item() const{
    return this->kind_of_item;
}

double Item::get_damage() const{
    return 0.0;
}

//Weapon functions.
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

//Armor functions.
Armor::Armor(string n, double p, int l, double d):Item(n, p, l, "Armor"){
    this->reduce_of_damage = d;
}

double Armor::get_reduce_of_damage() const{
    return this->reduce_of_damage;
}

//Potion functions.
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