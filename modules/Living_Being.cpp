#include "Living_Being.h";


Living_Being::Living_Being( string name, double healthPower)
{
    this->name = name;
    this->level = 0;
    this->healthPower = healthPower;

    in_life = false;
}

int Living_Being::get_level()const
{
    return level;
}

void Living_Being::level_up()
{
    level++;
}



//HERO

Hero::Hero( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility) 
            : Living_Being( name, healthPower)
{
    this->magicPower = magicPower;
    this->strength = strenght;
    this->dexterity = dexterity;
    this->agility = agility;

    this->money = 0;
    this->experience = 0;
}

void Hero::level_up()
{
    strength = strength + point;
    dexterity = dexterity + point;
    agility = agility + point;

    Living_Being::level_up();
}


//WARRIOR
Warrior::Warrior( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility)
        : Hero( name, healthPower, magicPower, strenght + strenght*point_strength, dexterity, agility + agility*point_agility)
{

}

//SORCERER
Sorcerer::Sorcerer( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility)
        : Hero( name, healthPower, magicPower, strenght, dexterity + dexterity*point_dexterity, agility + agility*point_agility)
{

}

//PALADIN
Paladin::Paladin( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility)
        : Hero( name, healthPower, magicPower, strenght + strenght*point_strenght, dexterity + dexterity*point_dexterity, agility)
{

}
