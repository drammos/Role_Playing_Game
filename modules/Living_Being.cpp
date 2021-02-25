////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                  LIVING BEING                                          //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////


#include "Living_Being.h"
#include <cstdlib>
#include <ctime>

//constructor
Living_Being::Living_Being( string name, string life_being)
{
    this->name = name;
    this->level = 1;
    this->healthPower = HEALTH_POWER;

    this->life_being = life_being;

    in_life = false;
}

//get name
string Living_Being::get_name()const
{
    return name;
}

//get health_Power
double Living_Being::get_healthPower()const
{
    return healthPower;
}

//get_level
int Living_Being::get_level()const
{
    return level;
}

//set_helathPower
void Living_Being::set_healthPower( double damage)
{
    healthPower = healthPower - damage;
    if( healthPower <= 0)healthPower = 0;
}

//add healthPower
void Living_Being::add_healthPower( double healthpower)
{
    this->healthPower += healthpower;
}

//level_up ( level + 1)
void Living_Being::level_up()
{
    level++;
}

//prints the stats of the living being
void Living_Being::displayStats(){
    cout<<"The name is: "<<this->name<<endl;
    cout<<"The healthpower is: "<< this->healthPower << endl;
    cout<<"The level is: "<< this->level << endl;
    cout<<"This is a "<< this->life_being << endl;
}
/////////////////////////////////




//HERO
const double Hero::point = 1;

//constructor
Hero::Hero( string name, double strenght, double dexterity, double agility, string hero, int x, int y) 
            : Living_Being( name, "Hero")
{
    this->magicPower = MAGIC_POWER;
    this->strength = strenght;
    this->dexterity = dexterity;
    this->agility = agility;
    this->hero = hero;

    this->money = MONEY;

    //the default experience is zero and increases when the heroes win a war.
    this->experience = 0.0;

    //item is null
    weapon = NULL;
    armor = NULL;

    //x and y are the coordinates of the square the hero is at.
    this->x = x;
    this->y = y;

    count_item_and_spell = 0;

}


//get magicPower Hero
double Hero::get_magicPower()const
{
    return magicPower;
}

//get strength Hero
double Hero::get_strength()const
{
    return strength;
}

//get decterity Hero
double Hero::get_dexterity()const
{
    return dexterity;
}

//get agility Hero
double Hero::get_agility()const
{
    return agility;
}

//get money Hero
double Hero::get_money()const
{
    return money;
}

//get experience Hero
double Hero::get_experience()const
{
    return experience;
}

//get Weapon Hero
Item* Hero::get_Weapon()const
{
    return weapon;
}
//get armor Hero
Item* Hero::get_Armor()const
{
    return armor;
}


//get x
int Hero::get_x() const
{
    return x;
}

//get y
int Hero::get_y() const
{
    return y;
}

//get hero
string Hero::get_hero()const
{
    return hero;
}

//get count item and spell
int Hero::get_count_item_and_spell()const
{
    return count_item_and_spell;
}
//SET

//set strength
void Hero::set_strength( double strength)
{
    this->strength = strength;
    if(this->strength > 100)
        this->strength = 100.0;
}

//set dexterity
void Hero::set_dexterity( double dexterity)
{
    this->dexterity = dexterity; 
    if(this->dexterity > 100)
        this->dexterity = 100.0;
}

//set agility
void Hero::set_agility( double agility)
{
    this->agility = agility;
    if(this->agility > 100)
        this->agility = 100.0;
}

//add money
void Hero::add_money( double money)
{
    this->money = this->money + money;
}

//sub money
void Hero::sub_money( double money)
{
    this->money = this->money - money;
}

//set money
void Hero::set_money(double money)
{
    this->money = money;
}

//add experience
void Hero::add_experience( double experience)
{
    this->experience = this->experience + experience;
}

//set weapon
void Hero::set_Weapon( int position)
{
    this->weapon = Weapon_vector.at( position);
}

//set armor
void Hero::set_Armor( int position)
{
    this->armor = Armor_vector.at( position);
}


//set x
void Hero::set_x( int x)
{
    this->x = x;
}

//set y
void Hero::set_y( int y)
{
    this->y = y;
}

//add magic power
void Hero::add_magicPower(double magic)
{
    this->magicPower += magic;
}

//the hero level up
void Hero::level_up()
{
    //strength, dexterity and agility increase
    strength = strength + strength*point;
    dexterity = dexterity + dexterity*point;
    agility = agility + agility*point;
    
    //call level up for living being
    Living_Being::level_up();

    cout<< GREEN << "You made it to the next level!" << RESET << endl;
}



//for buy item
void Hero::buy_Item( Item* item)
{
    string kind_of_item = item->get_kind_of_item();

    count_item_and_spell++;
    if( kind_of_item == "Weapon")
    {   
        if( weapon == NULL)
        {
            weapon = item;
        }
        Weapon_vector.push_back( item);
    }   
    else if( kind_of_item == "Armor")
    {   
        if( armor == NULL)
        {
            armor = item;
        }
        Armor_vector.push_back( item);
    }
    else
    {
        Potion_vector.push_back( item);
    }
    
}

//for buy spell
void Hero::buy_Spell( Spell* spell)
{   
    count_item_and_spell++;
    spell_vector.push_back( spell);
}


//for sell spell and item

//i return true if the hero sells an item
bool Hero::sell_Item(unsigned int position)
{   
    unsigned int size = Weapon_vector.size() + Armor_vector.size() + Potion_vector.size();

    if( position >= 0 && position < size)
    {    

        if( position < Weapon_vector.size())
        {   
            vector <Item*> :: iterator it;
            it = Weapon_vector.begin();
            for(unsigned int i = 0; i < position; i++){
                it++;
            }

            Weapon_vector.erase(it);
        }
        else if( position < Weapon_vector.size() + Armor_vector.size())
        {   
            position = position - Weapon_vector.size();

            vector <Item*> :: iterator it;
            it = Armor_vector.begin();
            for(unsigned int i = 0; i < position; i++){
                it++;
            }

            Armor_vector.erase(it);
        }
        else
        {
            position = position - Weapon_vector.size() - Armor_vector.size();

            vector <Item*> :: iterator it;
            it = Potion_vector.begin();
            for(unsigned int i = 0; i < position; i++){
                it++;
            }

            Potion_vector.erase(it);
        }
        count_item_and_spell--;
        
        return true;
    }
    return false;
}

//returns true if the hero sells a spell
bool Hero::sell_Spell( int position)
{
    int size = spell_vector.size(); 
    if( position >= 0 && position < size )
    {
        vector <Spell*> :: iterator it;
        it = spell_vector.begin();
        for(int i = 0; i < position; i++){
            it++;
        }

        spell_vector.erase(it);

        count_item_and_spell--;
        return true;
    }

    return false;
}


//prints the available spells
int Hero::print_spell()const
{   
    int size = spell_vector.size();
    if( size == 0)
    {
        cout << "You don´t have any spells!" << endl;
        return 0;
    }
    if(size > 0)
    {
        cout << "Your spells are:" << endl;
    }
    for( int i =0; i < size; i++ )
    {
        Spell* spell = spell_vector.at(i);
        cout << (i+1) << ") ";
        spell->print();
    }
    return size;
}

//prints the available items
int Hero::print_item()const
{
    int size_all = Weapon_vector.size() + Armor_vector.size() + Potion_vector.size();
    if(size_all == 0)
    {
        cout << "You don´t have any items!" << endl;
    }
    else
    {
        cout << "Your items are:" << endl;
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
    size_previous += size;

    size = Potion_vector.size();
    for( int i =0; i < size; i++ )
    {
        Item* item = Potion_vector.at(i);
        cout << (i+1+size_previous) << ") ";
        item->print();
    }

    return size_all;
}


//prints the available weapons
int Hero::print_Weapon()const
{   
    int size = Weapon_vector.size();
    if( size == 0)
    {   
        cout << "You don´t have any weapons!" << endl;
        return 0;
    }
    else
    {
        cout << "Your Weapons are:" << endl;
    }
    
    for(unsigned int i = 0; i < Weapon_vector.size(); i++)
    {
        Item* item = Weapon_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}

//prints the available armors
int Hero::print_Armor()const
{
    int size = Armor_vector.size();
    if( size == 0)
    {   
        cout << "You don´t have any armors!" << endl;
        return 0;
    }
    else
    {
        cout << "Your armors are:" << endl;
    }
    
    for(unsigned int i = 0; i < Armor_vector.size(); i++)
    {
        Item* item = Armor_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}

//prints the available potions
int Hero::print_Potion()const
{
    int size = Potion_vector.size();
    if( size == 0)
    {   
        cout << "You don´t have any potions." << endl;
        return 0;
    }
    else
    {
        cout << "Your Potions are:" << endl;
    }
    
    for(unsigned int i = 0; i < Potion_vector.size(); i++)
    {
        Item* item = Potion_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}

//the hero takes one potion that the have already bought.
void Hero::Take_Potion( int position)
{
    vector <Item*> :: iterator it;
    it = Potion_vector.begin();
    for(int i = 0; i < position; i++){
        it++;
    }

    Potion_vector.erase(it);
}

//Print hero
void Hero::print_hero()const
{
    cout << "The Hero is a  " << BOLDBLUE << hero  << RESET << ", with name: " << get_name() << endl;

    cout << "HealthPower: " << GREEN << get_healthPower() << RESET << ", Level: " << GREEN << get_level() << RESET << endl; 
    
    cout << "Magic Power: " << BOLDBLACK << magicPower << RESET << ", Strength: " << BOLDBLACK << strength << RESET << ", Dexterity: " << BOLDBLACK << dexterity << RESET;
    cout << "Agility: " << BOLDBLACK << agility << RESET << endl;
    cout << "Money: " << BOLDBLUE << money << RESET << ", Experience: " << BOLDBLUE << experience << RESET << endl << endl;
}

void Hero::displayStats(){
    this->print_hero();
}

//attack for hero
void Hero::attack( Monster* monster)
{   
    //the damage his weapon can cause
    double damage = weapon->get_damage();

    double power = damage + strength;
    if(power <= 0)return;

    //defence of monster and probability of a escaping an attack during a war
    double monster_defence = monster->get_defence();
    double monster_probablity_of_escape = monster->get_probability_of_escape();

    double r = rand()%100;
    //the monster can avoid this attack
    if( r <= monster_probablity_of_escape)
    {
        return;
    }
    else
    {
        power = power - monster_defence;
        if( power <= 0)return;
        monster->set_healthPower( power);
    }
    
}

//attack with spell for hero
bool Hero::castSpell( Monster* monster)
{
    //prints the available spells.
    int size = print_spell();
    if( size == 0)
    {
        return false;
    }

    cout << endl << BOLDBLUE << "Which spell do you want to cast?" << RESET << endl;
    cout << BOLDBLACK <<"Press the correct number" << RESET << endl;

    int answer;
    cin >> answer;

    while(answer < 1 || answer > size){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }

    //the spell that the hero chooses.
    Spell* spell = spell_vector.at( answer - 1);

    //get energy for spell
    double power_magic = spell->get_energy();
    
    //count the spells that the hero does not have enough magic power to cast.
    bool spell_change[size];
    for( int i = 0; i < size; i++)
    {
        spell_change[i] = false;
    }
    int spell_change_count = 1;

    //the spell must need less magic power than the hero has.
    while( power_magic > magicPower)
    {   
        
        if( spell_change_count == size)return false;

        cout << "You don't have the needed magicPower. Do you want cast another Spell? Yes or No." << endl;
        string an;
        cin >> an;

        while( an.compare("Yes") && an.compare("No"))
        {
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> an;
        }
        //returns false if the hero does not want to use another spell
        if( an == "No")return false;

        print_spell();
        
        cout << endl << BOLDBLUE << "Which spell do you want to cast?" << RESET << endl;
        cout << BOLDBLACK <<"Press the correct number" << RESET << endl;

        cin >> answer;

        while(answer < 1 || answer > size)
        {
            cout << RED << "Invalid number, try again!" << RESET << endl;
            cin >> answer;
        }

        //if the hero does not have enough magic power for this spell.
        while( spell_change[answer - 1] == true)
        {
            cout << RED << "You don't have enough magic power for this spell, try again!" << RESET << endl;
            cin >> answer; 
        }

        spell = spell_vector.at( answer - 1);
        power_magic = spell->get_energy();

        //check this spell
        if(power_magic > magicPower){
            spell_change[answer - 1] = true;
            spell_change_count++;
        }


    }

    
    string kind_of_spell = spell->get_kind_of_spell();
    magicPower = magicPower - power_magic;

    //low and high damage for spell
    double low_damage = spell->get_low_damage();
    double high_damage = spell->get_high_damage();

    double damage_for_monster;
    double dif = high_damage - low_damage;
    //damage for monster
    if( dif == 0)
    {
        damage_for_monster = low_damage;
    }
    else
    {
        damage_for_monster = low_damage + (int)dexterity%((int)dif); 
    }

    //monster defence and probability of escape
    double monster_defence = monster->get_defence();
    double monster_probablity_of_escape = monster->get_probability_of_escape();

    double r = rand()%100;
    if( r <= monster_probablity_of_escape)
    {
        cout<<MAGENTA<<"The monster escaped your attack"<<RESET<<endl;
        return  true;
    }
    else
    {
        damage_for_monster = damage_for_monster - monster_defence;
        if( damage_for_monster > 0)
            monster->set_healthPower( damage_for_monster);
    }

    double damage = spell->get_damage();
    int rounds = spell->get_rounds();

    //every spell has one property that affects the monster
    //the change that is caused from that property remains for a number of rounds.
    if(kind_of_spell == "IceSpell")
    {
        double damage_low_monster = monster->get_damage_low() + damage*monster->get_damage_low();

        double damage_high_monster = monster->get_damage_high() + damage*monster->get_damage_high();
        
        monster->set_damage( damage_low_monster, damage_high_monster);
        monster->set_rounds( rounds);
    }
    else if( kind_of_spell == "FireSpell")
    {
        damage = monster->get_defence() - damage*monster->get_defence();
        if( damage < 0)damage = 0;

        monster->set_defence( damage);
        monster->set_rounds( rounds);
    }
    else
    {
        damage = monster->get_probability_of_escape() - damage*monster->get_probability_of_escape();
        if( damage < 0)damage = 0;

        monster->set_probability_of_escape( damage);
        monster->set_rounds( rounds);
    }

    //i return true if the hero uses a spell
    return true;
    

}



////////////////////////////////////







//WARRIOR
const double Warrior::point_strength = 0.4;
const double Warrior::point_agility = 0.2;

//constructor
Warrior::Warrior( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght + strenght*point_strength, dexterity, agility + agility*point_agility, "Warrior", x, y){}

//level up for warrior
void Warrior::level_up()
{   

    //the upgrade of the level increases some characteristics for the hero
    double strength = get_strength();
    strength = strength + strength*point_strength;
    set_strength( strength);

    double agility = get_agility();
    agility = agility + agility*point_agility;
    set_agility( agility);
    
    Hero::level_up();
}

void Warrior::diplayStats(){
    Hero::displayStats();
}
/////////////////////////////////


//SORCERER
const double Sorcerer::point_dexterity = 0.4;
const double Sorcerer::point_agility = 0.3;

//constructor
Sorcerer::Sorcerer( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght, dexterity + dexterity*point_dexterity, agility + agility*point_agility, "Sorcerer", x, y){}

//level up for SORCERER
void Sorcerer::level_up()
{
    //the upgrade of the level increases some characteristics for the hero
    double dexterity = get_dexterity();
    dexterity = dexterity + dexterity*point_dexterity;
    set_dexterity( dexterity);

    double agility = get_agility();
    agility = agility + agility*point_agility;
    set_agility( agility);
    
    Hero::level_up();
}

void Sorcerer::displayStats(){
    Hero::displayStats();
}


//////////////////////////


//PALADIN
const double Paladin::point_strength = 0.4;
const double Paladin::point_dexterity = 0.3;

//constructor
Paladin::Paladin( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght + strenght*point_strength, dexterity + dexterity*point_dexterity, agility, "Paladin", x, y){}

//level up for paladin
void Paladin::level_up()
{
    //the upgrade of the level increases some characteristics for the hero
    double strength = get_strength();
    strength = strength + strength*point_strength;
    set_strength( strength);

    double dexterity = get_dexterity();
    dexterity = dexterity + dexterity*point_dexterity;
    set_dexterity( dexterity);

    Hero::level_up();
}

void Paladin::displayStats(){
    Hero::displayStats();
}

////////////////////////////




//MONSTER
const double Monster::point = 0.4;

//constructor for monster
Monster::Monster( string name, double damage_low, double damage_high, double defence, double probability_of_escape, string monster)
        : Living_Being( name, "Monster")
{
    this->damage_high = damage_high;
    this->damage_low = damage_low;
    this->defence = defence;
    this->probability_of_escape = probability_of_escape;

    this->monster = monster;

    //Original fields.
    original_damage_low = damage_low;
    original_damage_high = damage_high;
    original_defence = defence;
    original_probability_of_escape = probability_of_escape; //[0,100]

    //rounds for war/castspell
    rounds = 0;

}

//get

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

int Monster::get_rounds()const
{
    return rounds;
}

//SET

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

void Monster::set_rounds( int rounds)
{
    this->rounds = rounds;
}

//reset fields to the originals if rounds == 0
//else rounds is decreased by one
void Monster::reset_fields()
{
    if( rounds <= 0)return;

    rounds--;
    if( rounds == 0)
    {
        damage_low = original_damage_low;
        damage_high = original_damage_high;
        defence = original_defence;
        probability_of_escape = original_probability_of_escape;
    }
}

//attack monster
void Monster::attack(Hero* hero){
    srand(time(NULL));
    
    double damage = this->damage_low + rand()%(int)(damage_high - damage_low);
    int r = rand() % 100; 
    if(r < hero->get_agility())return;
    hero->set_healthPower(damage);
    cout<<"The monster with name "<<this->get_name()<<" attacked the hero with name "<<hero->get_name()<<endl;
}


//level up for monster
void Monster::level_up()
{
    //the upgrade of the level increases some characteristics for the monster
    damage_high = damage_high + damage_high*point;
    damage_low = damage_low + damage_low*point;
    defence = defence + defence*point;
    probability_of_escape = probability_of_escape + probability_of_escape*point;
    

    Living_Being::level_up();
}

//print monster
void Monster::print_monster()
{   
    cout << "The Monster is a " <<  MAGENTA << this->monster << RESET << ", with name: " << get_name() << endl;
    cout << "HealthPower: " << BOLDBLUE <<get_healthPower() << RESET << endl;
    cout << "Level: " << BOLDBLUE << get_level() << RESET << endl; 
    cout << "Damage range: " << BOLDBLACK <<  this->damage_low << RESET << " - " << BOLDBLACK << this->damage_high << RESET << ", Probability of ascaping an attack:" << BOLDBLACK << this->probability_of_escape << RESET  << endl;
}

void Monster::displayStats(){
    this->print_monster();
}
///////////////////////////////////////




//DRAGON
const double Dragon::point_attack = 0.3;
//constructor
Dragon::Dragon( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low + point_attack*damage_low, damage_high + damage_high*point_attack, defence, probability_of_escape, "Dragon"){}

//level up
void Dragon::level_up()
{   
    //the upgrade of the level increases some characteristics for the dragon
    double damage_low = get_damage_low();
    damage_low =  damage_low + damage_low*point_attack;
    double damage_high = get_damage_high();
    damage_high =  damage_high + damage_high*point_attack;
    set_damage( damage_low, damage_high);
    
    Monster::level_up();
}

void Dragon::displayStats(){
    Monster::displayStats();
}
///////////////////////////////////////


//EXOSKELETON
const double Exoskeleton::point_defence = 0.3;

//consrtcutor
Exoskeleton::Exoskeleton( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low, damage_high, defence + defence*point_defence, probability_of_escape, "Exoskeletion"){}

//level up
void Exoskeleton::level_up()
{   
    //the upgrade of the level increases some characteristics for the exoskeleton
    double defence = get_defence();
    defence = defence + defence*point_defence;
    set_defence( defence);
    
    Monster::level_up();
}

void Exoskeleton::displayStats(){
    Monster::displayStats();
}
//////////////////////////////////////

//SPIRIT
const double Spirit::point_probability_of_escape = 0.3;

//constructor
Spirit::Spirit( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low, damage_high, defence, probability_of_escape + point_probability_of_escape*probability_of_escape, "Spirit"){}

//level up
void Spirit::level_up()
{   
    //the upgrade of the level increases some characteristics for the spirit
    double probability_of_escape = get_probability_of_escape();
    probability_of_escape = probability_of_escape + probability_of_escape*point_probability_of_escape;
    set_probability_of_escape( probability_of_escape);
    
    Monster::level_up();
}

void Spirit::displayStats(){
    Monster::displayStats();
}



////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                      END                                               //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////