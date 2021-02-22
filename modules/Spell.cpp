#include <iostream>
#include "Spell.h"

using namespace std;

//Spell functions.
Spell::Spell(string n, double p, int l, double low, double high, double e, string s){
    this->name.assign(n);
    this->price = p;
    this->level = l;
    this->damage_low = low;
    this->damage_high = high;
    this->energy = e;
    this->kind_of_spell.assign(s);
}

Spell::~Spell(){
    this->name.clear();
}

string Spell::get_name() const{
    return this->name;
}

double Spell::get_price() const{
    return this->price;
}

int Spell::get_level() const{
    return this->level;
}

double Spell::get_low_damage() const{
    return this->damage_low;
}

double Spell::get_high_damage() const{
    return this->damage_high;
}

double Spell::get_energy() const{
    return this->energy;
}

void Spell::set_low_damage(double d){
    this->damage_low = d;
}

void Spell::print(){
    cout<<"This is a "<<this->kind_of_spell<<endl;
    cout<<"Name: "<<this->name<<", Price: "<<this->price<<", Required Level: "<<this->level<<", Range of damage: "<<this->damage_low<<" - "<<this->damage_high<<", Required magic energy: "<<this->energy<<endl;
}

string Spell::get_kind_of_spell() const{
    return this->kind_of_spell;
}

//Assisting functions.
double Spell::get_damage()const
{
    return 0.0;
}
int Spell::get_rounds()const
{
    return 0;
}


//IceSpell functions.
IceSpell::IceSpell(string n, double p, int l, double dl, double dh, double e, double nl, int r):Spell(n, p, l, dl, dh, e, "IceSpell"){
    this->damage_low_new = nl;
    this->rounds = r;
}

double IceSpell::get_damage() const{
    return this->damage_low_new;
}

int IceSpell::get_rounds() const{
    return this->rounds;
}

//FireSpell functions.
FireSpell::FireSpell(string n, double p, int l, double dl, double dh, double e, double dr, int r):Spell(n, p, l, dl, dh, e, "FireSpell"){
    this->defense_reduce = dr;
    this->rounds = r;
}

double FireSpell::get_damage() const{
    return this->defense_reduce;
}

int FireSpell::get_rounds() const{
    return this->rounds;
}

//LightingSpell functions.
LightingSpell::LightingSpell(string n, double p, int l, double dl, double dh, double e, double dpr, int r):Spell(n, p, l, dl, dh, e, "LightingSpell"){
    this->defense_prob_reduce = dpr;
    this->rounds = r;
}

double LightingSpell::get_damage() const{
    return this->defense_prob_reduce;
}

int LightingSpell::get_rounds() const{
    return this->rounds;
}