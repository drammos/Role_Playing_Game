#include "Living_Being.h";
#include <ctime>

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
const double Hero::point = 1;

Hero::Hero( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, string hero, int x, int y) 
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

    //αρχικα δεν εχει αντικειμενα αρα null
    weapon = nullptr;
    armor = nullptr;
    potion = armor;

    this->x = x;
    this->y = y;

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

double Hero::get_experience()const
{
    return experience;
}

Item* Hero::get_Weapon()const
{
    return weapon;
}

Item* Hero::get_Armor()const
{
    return armor;
}

Item* Hero::get_Potion()const
{
    return potion;
}

int Hero::get_x() const
{
    return x;
}

int Hero::get_y() const
{
    return y;
}
//SET

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

void Hero::add_money( double money)
{
    this->money = this->money + money;
}

void Hero::add_experience( double experience)
{
    this->experience = this->experience + experience;
}

void Hero::set_Weapon( int position)
{
    this->weapon = Weapon_vector.at( position);
}

void Hero::set_Armor( int position)
{
    this->armor = Armor_vector.at( position);
}

void Hero::set_Potion( Item* potion)
{
    this->potion = potion;
}

void Hero::set_x( int x)
{
    this->x = x;
}

void Hero::set_y( int y)
{
    this->y = y;
}


//ανεβαινει επιπεδο
void Hero::level_up()
{

    strength = strength + strength*point;
    dexterity = dexterity + dexterity*point;
    agility = agility + agility*point;
    

    Living_Being::level_up();
}



//for buy spell and item
void Hero::buy_Item( Item* item)
{
    string kind_of_item = item->get_kind_of_item();
    if( kind_of_item == "Weapon")
    {
        Weapon_vector.push_back( item);
    }   
    else if( kind_of_item == "Armor")
    {
        Armor_vector.push_back( item);
    }
    else
    {
        Potion_vector.push_back( item);
    }
    
}

void Hero::buy_Spell( Spell* spell)
{
    spell_vector.push_back( spell);
}


//for sell spell and item

//επιστρεφω  true αν υπαρχει το στοιχειο και τοτε αφαιρειται
//αλλιως false
bool Hero::sell_Item( int position)
{   
    int size = Weapon_vector.size() + Armor_vector.size() + Potion_vector.size();


    if( position >= 0 && position < size)
    {      
        Item* item_in;
        Item* it;


        if( position < Weapon_vector.size())
        {
            item_in = Weapon_vector.at(position);
            it = Weapon_vector.at( Weapon_vector.size() - 1);
    
            Weapon_vector.assign( position, it);
            Weapon_vector.assign( Weapon_vector.size() -1, item_in);

            Weapon_vector.pop_back();
        }
        else if( position < Weapon_vector.size() + Armor_vector.size())
        {   
            position = position - Weapon_vector.size();
            item_in = Armor_vector.at(position);
            it = Armor_vector.at( Armor_vector.size() - 1);
    
            Armor_vector.assign( position, it);
            Armor_vector.assign( Armor_vector.size() -1, item_in);

            Armor_vector.pop_back();
        }
        else
        {
            position = position - Weapon_vector.size() - Armor_vector.size();
            item_in = Potion_vector.at(position);
            it = Potion_vector.at( Potion_vector.size() - 1);
    
            Potion_vector.assign( position, it);
            Potion_vector.assign( Potion_vector.size() -1, item_in);

            Potion_vector.pop_back();
        }
        
        return true;
    }

    return false;
}

//επιστρεφω  true αν υπαρχει το στοιχειο και τοτε αφαιρειται
//αλλιως false
bool Hero::sell_Spell( int position)
{
    int size = spell_vector.size(); 
    if( position >= 0 && position < size )
    {
        Spell* spell_in = spell_vector.at(position);
        Spell* sp = spell_vector.at( size - 1);
        
        spell_vector.assign( position, sp);
        spell_vector.assign( size -1, spell_in);

        spell_vector.pop_back();
        return true;
    }

    return false;
}


//print list for spell and item
int Hero::print_spell()const
{   
    int size = spell_vector.size();
    if(size == 0)
    {
        cout << "Δεν υπαρχουν ξορκια στην διαθεση σας!" << endl;
    }
    else
    {
        cout << "Τα ξορκια σας:" << endl;
    }
    for( int i =0; i < size; i++ )
    {
        Spell* spell = spell_vector.at(i);
        cout << (i+1) << ") ";
        spell->print();
    }
    return size;
}

int Hero::print_item()const
{
    int size_all = Weapon_vector.size() + Armor_vector.size() + Potion_vector.size();
    if(size_all == 0)
    {
        cout << "Δεν υπαρχουν αντικειμενα στην διαθεση σας!" << endl;
    }
    else
    {
        cout << "Τα αντικειμενα σας:" << endl;
    }
    
    int size = Weapon_vector.size();
    for( int i =0; i < size; i++ )
    {
        Item* item = Weapon_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }
    int size_previous = size;

    size = Armor_vector.size();
    for( int i =0; i < size; i++ )
    {
        Item* item = Armor_vector.at(i);
        cout << (i+1 + size_previous) << ") ";
        item->print();
    }
    size_previous = size + size;

    size = Potion_vector.size();
    for( int i =0; i < size; i++ )
    {
        Item* item = Potion_vector.at(i);
        cout << (i+1+size_previous) << ") ";
        item->print();
    }

    return size_all;
}


int Hero::print_Weapon()const
{   
    int size = Weapon_vector.size();
    if( size == 0)
    {   
        cout << "You havn't Weapon." << endl;
        return 0;
    }
    else
    {
        cout << "Your Weapon:" << endl;
    }
    
    for( int i = 0; i < Weapon_vector.size(); i++)
    {
        Item* item = Weapon_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}


int Hero::print_Armor()const
{
    int size = Armor_vector.size();
    if( size == 0)
    {   
        cout << "You havn't Armor." << endl;
        return 0;
    }
    else
    {
        cout << "Your Armor:" << endl;
    }
    
    for( int i = 0; i < Armor_vector.size(); i++)
    {
        Item* item = Armor_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}



int Hero::print_Potion()const
{
    int size = Potion_vector.size();
    if( size == 0)
    {   
        cout << "You don't have any potions." << endl;
        return 0;
    }
    else
    {
        cout << "Your Potions are:" << endl;
    }
    
    for( int i = 0; i < Potion_vector.size(); i++)
    {
        Item* item = Potion_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}


void Hero::Take_Potion( int position)
{
    Item* potion_item = Potion_vector.at( position);
    srand( time(NULL));

    string characteristic = potion_item->get_characteristic();
    double increase = potion_item->get_increase();
    if( characteristic == "magicPower")
    {
        magicPower = magicPower + increase*magicPower;
    }
    else if( characteristic == "strength")
    {
        strength = strength + increase*strength;
    }
    else if( characteristic == "dexterity")
    {
        dexterity = dexterity + increase*dexterity;
    }
    else
    {
        agility = agility + increase*agility;
    }

    Item* P = Potion_vector.at( Potion_vector.size() - 1);
    
    Potion_vector.assign( position, P);
    Potion_vector.assign( Armor_vector.size() -1, potion_item);

    Potion_vector.pop_back();

    delete potion_item;

    
}

void Hero::print_hero()const
{
    cout << "The Hero is: " << hero << " name is: " << get_name() << " HealthPower is: " << get_healthPower();
    cout << " and level is: " << get_level() << endl; 
    cout << "The magic Power is: " << magicPower << " the Strength is: " << strength << " the dexterity is: " << dexterity;
    cout << " the agility is: " << agility << endl;
    cout << "The money is: " << money << " and the experience is: " << experience << endl;
}
////////////////////////////////////







//WARRIOR
const double Warrior::point_strength = 0.8;
const double Warrior::point_agility = 0.5;

Warrior::Warrior( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, int x, int y)
        : Hero( name, healthPower, magicPower, strenght + strenght*point_strength, dexterity, agility + agility*point_agility, money, "Warrior", x, y){}

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
const double Sorcerer::point_dexterity = 0.7;
const double Sorcerer::point_agility = 0.6;

Sorcerer::Sorcerer( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, int x, int y)
        : Hero( name, healthPower, magicPower, strenght, dexterity + dexterity*point_dexterity, agility + agility*point_agility, money, "Sorcerer", x, y){}

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
const double Paladin::point_strength = 0.9;
const double Paladin::point_dexterity = 0.7;

Paladin::Paladin( string name, double healthPower, double magicPower, double strenght, double dexterity, double agility, double money, int x, int y)
        : Hero( name, healthPower, magicPower, strenght + strenght*point_strength, dexterity + dexterity*point_dexterity, agility, money, "Paladin", x, y){}

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
const double Monster::point = 0.4;
Monster::Monster( string name, double healthPower, double damage_low, double damage_high, double defence, double probability_of_escape, string monster)
        : Living_Being( name, healthPower, "Monster")
{
    this->damage_high = damage_high;
    this->damage_low = damage_low;
    this->defence = defence;
    this->probability_of_escape = probability_of_escape;

    this->monster = monster;

}


double Monster::get_damage_low()const
{
    return damage_low;
}

double Monster::get_damage_high()const
{
    return damage_high;
}

double Monster::get_defence()const
{
    return defence;
}

double Monster::get_probability_of_escape()const
{
    return probability_of_escape;
}

void Monster::set_damage( double low, double high)
{
    this->damage_high = high;
    this->damage_low = low;
}

void Monster::set_defence( double defence)
{
    this->defence = defence;
}

void Monster::set_probability_of_escape( double probability_of_escape)
{
    this->probability_of_escape = probability_of_escape;
}


//ανεβαινει επιπεδο
void Monster::level_up()
{

    damage_high = damage_high + damage_high*point;
    damage_low = damage_low + damage_low*point;
    defence = defence + defence*point;
    probability_of_escape = probability_of_escape + probability_of_escape*point;
    

    Living_Being::level_up();
}

void Monster::print_monster()
{
    cout << "The Monster is: " << this->monster << " name is: " << get_name() << " HealthPower is: " << get_healthPower();
    cout << " and level is: " << get_level() << endl; 
    cout << "The damage range is from " << this->damage_low << " to " << this->damage_high << " and the probability of ascaping an attack is:" << this->probability_of_escape<<endl;
}
///////////////////////////////////////




//DRAGON
const double Dragon::point_attack = 0.6;
Dragon::Dragon( string name, double healthPower, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, healthPower, damage_low + point_attack*damage_low, damage_high + damage_high*point_attack, defence, probability_of_escape, "Dragon"){}

void Dragon::level_up()
{
    double damage_low = get_damage_low();
    damage_low =  damage_low + damage_low*point_attack;
    double damage_high = get_damage_high();
    damage_high =  damage_high + damage_high*point_attack;
    set_damage( damage_low, damage_high);
    
    Monster::level_up();
}
///////////////////////////////////////

//EXOSKELETON
const double Exoskeleton::point_defence = 0.7;

Exoskeleton::Exoskeleton( string name, double healthPower, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, healthPower, damage_low, damage_high, defence + defence*point_defence, probability_of_escape, "Exoskeletion"){}

void Exoskeleton::level_up()
{
    double defence = get_defence();
    defence = defence + defence*point_defence;
    set_defence( defence);
    
    Monster::level_up();
}
//////////////////////////////////////

//SPIRIT
const double Spirit::point_probability_of_escape = 0.8;

Spirit::Spirit( string name, double healthPower, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, healthPower, damage_low, damage_high, defence, probability_of_escape + point_probability_of_escape*probability_of_escape, "Spirit"){}

void Spirit::level_up()
{
    double probability_of_escape = get_probability_of_escape();
    probability_of_escape = probability_of_escape + probability_of_escape*point_probability_of_escape;
    set_probability_of_escape( probability_of_escape);
    
    Monster::level_up();
}
//////////////////////////////////////
