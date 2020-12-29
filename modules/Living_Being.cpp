#include "Living_Being.h";


Living_Being::Living_Being( string name, double healthPower, string life_being)
{
    this->name = name;
    this->level = 1;
    this->healthPower = healthPower;

    this->life_being = life_being;

    in_life = false;
}

//get

string Living_Being::get_name()const
{
    return name;
}

double Living_Being::get_healthPower()const
{
    return healthPower;
}

int Living_Being::get_level()const
{
    return level;
}



void Living_Being::level_up()
{
    level++;
}
/////////////////////////////////








//HERO

Hero::Hero( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, string hero) 
            : Living_Being( name, healthPower, "Hero")
{
    this->magicPower = magicPower;
    this->strength = strenght;
    this->dexterity = dexterity;
    this->agility = agility;
    this->hero = hero;

    this->money = money;

    //η εμπειρια αρχικοποειται 0 και μεγαλωνει αναλογα με τις ενεργειες
    //του ηρωα
    this->experience = 0;
}



double Hero::get_magicPower()const
{
    return magicPower;
}

double Hero::get_strength()const
{
    return strength;
}

double Hero::get_dexterity()const
{
    return dexterity;
}

double Hero::get_agility()const
{
    return agility;
}

double Hero::get_money()const
{
    return money;
}

double Hero::get_experiend()const
{
    return experience;
}


//for level up

void Hero::set_strength( double strength)
{
    this->strength = strength;
}

void Hero::set_dexterity( double dexterity)
{
    this->dexterity = dexterity; 
}

void Hero::set_agility( double agility)
{
    this->agility = agility;
}


//ανεβαινει επιπεδο
void Hero::level_up()
{

    strength = strength + strength*point;
    dexterity = dexterity + dexterity*point;
    agility = agility + agility*point;
    

    Living_Being::level_up();
}
////////////////////////////////////







//WARRIOR
Warrior::Warrior( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, "Warrior"){}

void Warrior::level_up()
{
    double strength = get_strength();
    strength = strength + strength*point_strength;
    set_strength( strength);

    double agility = get_agility();
    agility = agility + agility*point_agility;
    set_agility( agility);
    
    Hero::level_up();
}
/////////////////////////////////


//SORCERER
Sorcerer::Sorcerer( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, "Sorcerer"){}

void Sorcerer::level_up()
{
    double dexterity = get_dexterity();
    dexterity = dexterity + dexterity*point_dexterity;
    set_dexterity( dexterity);

    double agility = get_agility();
    agility = agility + agility*point_agility;
    set_agility( agility);
    
    Hero::level_up();
}

//////////////////////////


//PALADIN
Paladin::Paladin( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, "Paladin"){}

void Paladin::level_up()
{
    double strength = get_strength();
    strength = strength + strength*point_strength;
    set_strength( strength);

    double dexterity = get_dexterity();
    dexterity = dexterity + dexterity*point_dexterity;
    set_dexterity( dexterity);

    Hero::level_up();
}

////////////////////////////




//MONSTER

Monster::Monster( string name, double healthPower, double attack, double defence, double probability_of_escape, string monster)
        : Living_Being( name, healthPower, "Monster")
{
    this->attack = attack;
    this->defence = defence;
    this->probability_οf_escape = probability_of_escape;

    this->monster = monster;

}


double Monster::get_attack()const
{
    return attack;
}

double Monster::get_defence()const
{
    return defence;
}

double Monster::get_probability_of_escape()const
{
    return probability_οf_escape;
}

///////////////////////////////////////




//DRAGON
Dragon::Dragon( string name, double healthPower, double attack, double defence, double probability_of_escape)
        : Monster( name, healthPower, attack + point_attack*attack, defence, probability_of_escape, "Dragon"){}
///////////////////////////////////////

//EXOSKELETION
Exoskeleton::Exoskeleton( string name, double healthPower, double attack, double defence, double probability_of_escape)
        : Monster( name, healthPower, attack, defence + defence*point_defence, probability_of_escape, "Exoskeletion"){}

//////////////////////////////////////

//SPIRIT
Spirit::Spirit( string name, double healthPower, double attack, double defence, double probability_of_escape)
        : Monster( name, healthPower, attack , defence, probability_of_escape + point_probability_οf_escape*probability_of_escape, "Spirit"){}

//////////////////////////////////////
