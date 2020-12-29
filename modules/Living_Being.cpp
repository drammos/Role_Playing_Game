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

Hero::Hero( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, double experience, string hero) 
            : Living_Being( name, healthPower, "Hero")
{
    this->magicPower = magicPower;
    this->strength = strenght;
    this->dexterity = dexterity;
    this->agility = agility;
    this->hero = hero;

    this->money = 0;
    this->experience = 0;
}


//ανεβαινει επιπεδο
void Hero::level_up()
{

    strength = strength + point;
    dexterity = dexterity + point;
    agility = agility + point;

    //ο καθες ηρωας αναλογως ευνοειται σε καποιες τιμες
    if( hero == "Warrior")
    {
        strength = Warrior::point_strength + strength;
        agility = Warrior::point_agility + agility;
    }
    else if( hero == "Sorcerer")
    {
        agility = Sorcerer::point_agility + agility;
        dexterity = Sorcerer::point_dexterity + dexterity;
    }
    else
    {
        strength = Paladin::point_strength + strength;
        dexterity = Paladin::point_dexterity + dexterity;
    }
    

    Living_Being::level_up();
}
////////////////////////////////////







//WARRIOR
Warrior::Warrior( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, double experience)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, experience, "Warrior")
{

}
/////////////////////////////////






//SORCERER
Sorcerer::Sorcerer( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, double experience)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, experience, "Sorcerer")
{

}
//////////////////////////






//PALADIN
Paladin::Paladin( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, double experience)
        : Hero( name, healthPower, magicPower, strenght, dexterity, agility, money, experience, "Paladin")
{

}
