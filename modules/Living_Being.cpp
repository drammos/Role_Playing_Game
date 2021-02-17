#include "Living_Being.h"
#include <cstdlib>
#include <ctime>

Living_Being::Living_Being( string name, string life_being)
{
    this->name = name;
    this->level = 1;
    this->healthPower = HEALTH_POWER;

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

void Living_Being::set_healthPower( double damage)
{
    healthPower = healthPower - damage;
    if( healthPower <= 0)healthPower = 0;
}

void Living_Being::add_healthPower( double healthpower)
{
    this->healthPower += healthpower;
}

void Living_Being::level_up()
{
    level++;
}

void Living_Being::displayStats(){
    cout<<"The name is:"<<this->name<<endl;
    cout<<"The healthpower is:"<<this->healthPower<<endl;
    cout<<"The level is:"<<this->level<<endl;
    cout<<"This is a "<<this->life_being<<endl;
}
/////////////////////////////////




//HERO
const double Hero::point = 1;

Hero::Hero( string name, double strenght, double dexterity, double agility, string hero, int x, int y) 
            : Living_Being( name, "Hero")
{
    this->magicPower = MAGIC_POWER;
    this->strength = strenght;
    this->dexterity = dexterity;
    this->agility = agility;
    this->hero = hero;

    this->money = MONEY;

    //η εμπειρια αρχικοποειται 0 και μεγαλωνει αναλογα με τις ενεργειες
    //του ηρωα
    this->experience = 0.0;

    //αρχικα δεν εχει αντικειμενα αρα null
    weapon = NULL;
    armor = NULL;
    potion = armor;

    this->x = x;
    this->y = y;

    count_item_and_spell = 0;

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

string Hero::get_hero()const
{
    return hero;
}

int Hero::get_count_item_and_spell()const
{
    return count_item_and_spell;
}
//SET

void Hero::set_strength( double strength)
{
    this->strength = strength;
    if(this->strength > 100)
        this->strength = 100.0;
}

void Hero::set_dexterity( double dexterity)
{
    this->dexterity = dexterity; 
    if(this->dexterity > 100)
        this->dexterity = 100.0;
}

void Hero::set_agility( double agility)
{
    this->agility = agility;
    if(this->agility > 100)
        this->agility = 100.0;
}

void Hero::add_money( double money)
{
    this->money = this->money + money;
}

void Hero::sub_money( double money)
{
    this->money = this->money - money;
}

void Hero::set_money(double money)
{
    this->money = money;
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

void Hero::add_magicPower(double magic)
{
    this->magicPower += magic;
}

//ανεβαινει επιπεδο
void Hero::level_up()
{

    strength = strength + strength*point;
    dexterity = dexterity + dexterity*point;
    agility = agility + agility*point;
    

    Living_Being::level_up();

    cout<<GREEN<<"You made it to the next level!"<<RESET<<endl;
}



//for buy spell and item
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

void Hero::buy_Spell( Spell* spell)
{   
    count_item_and_spell++;
    spell_vector.push_back( spell);
}


//for sell spell and item

//επιστρεφω  true αν υπαρχει το στοιχειο και τοτε αφαιρειται
//αλλιως false
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

//επιστρεφω  true αν υπαρχει το στοιχειο και τοτε αφαιρειται
//αλλιως false
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
        // Spell* spell_in = spell_vector.at(position);
        // Spell* sp = spell_vector.at( size - 1);
        
        // spell_vector.assign( position, sp);
        // spell_vector.assign( size -1, spell_in);

        // spell_vector.pop_back();
        count_item_and_spell--;
        return true;
    }

    return false;
}


//print list for spell and item
int Hero::print_spell()const
{   
    int size = spell_vector.size();
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

int Hero::print_item()const
{
    int size_all = Weapon_vector.size() + Armor_vector.size() + Potion_vector.size();
    if(size_all == 0)
    {
        cout << "You don't have any items!" << endl;
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


int Hero::print_Weapon()const
{   
    int size = Weapon_vector.size();
    if( size == 0)
    {   
        cout << "You don't have any weapons!" << endl;
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


int Hero::print_Armor()const
{
    int size = Armor_vector.size();
    if( size == 0)
    {   
        cout << "You don't have any armors!" << endl;
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
    
    for(unsigned int i = 0; i < Potion_vector.size(); i++)
    {
        Item* item = Potion_vector.at(i);
        cout << (i+1) << ") ";
        item->print();
    }

    return size;
}


void Hero::Take_Potion( int position)
{
    vector <Item*> :: iterator it;
    it = Potion_vector.begin();
    for(int i = 0; i < position; i++){
        it++;
    }

    Potion_vector.erase(it);
}

void Hero::print_hero()const
{
    cout << "The Hero is: " << hero << " name is: " << get_name() << " HealthPower is: " << get_healthPower();
    cout << " and level is: " << get_level() << endl; 
    cout << "The magic Power is: " << magicPower << " the Strength is: " << strength << " the dexterity is: " << dexterity;
    cout << " the agility is: " << agility << endl;
    cout << "The money is: " << money << " and the experience is: " << experience << endl;
}

void Hero::displayStats(){
    this->print_hero();
}

void Hero::attack( Monster* monster)
{
    part p_w = weapon->get_prices();
    double damage = p_w.power;

    double power = damage + strength;
    if(power <= 0)return;

    double monster_defence = monster->get_defence();
    double monster_probablity_of_escape = monster->get_probability_of_escape();

    double r = rand()%100;
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

bool Hero::castSpell( Monster* monster)
{
    int size = print_spell();
    if( size == 0){
        cout<<"You don't have any spells"<<endl;
        return false;
    }

    cout << "Which spell do you want to cast?" << endl;
    cout << "Press the correct number" << endl;

    int answer;
    cin >> answer;

    while(answer < 1 || answer > size){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }

    Spell* spell = spell_vector.at( answer - 1);

    double power_magic = spell->get_energy();
    
    bool spell_change[size];
    for( int i = 0; i < size; i++)
    {
        spell_change[i] = false;
    }
    int spell_change_count = 1;

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
        if( an == "No")return false;

        print_spell();
        cout << "Which spell do you want to cast?" << endl;
        cout << "Press the correct number" << endl;
        
        cin >> answer;

        while(answer < 1 || answer > size)
        {
            cout << RED << "Invalid number, try again!" << RESET << endl;
            cin >> answer;
        }

        while( spell_change[answer - 1] == true)
        {
            cout << RED << "You don't have this spell, try again!" << RESET << endl;
            cin >> answer; 
        }

        spell = spell_vector.at( answer - 1);
        power_magic = spell->get_energy();

        //check this spell
        spell_change[answer - 1] = true;
        spell_change_count++;


    }

    string kind_of_spell = spell->get_kind_of_spell();
    magicPower = magicPower - power_magic;

    double low_damage = spell->get_low_damage();
    double high_damage = spell->get_high_damage();

    double damage_for_monster;
    //int level = get_level();
    double dif = high_damage - low_damage;
    if( dif == 0)
    {
        damage_for_monster = low_damage;
    }
    else
    {
        damage_for_monster = low_damage + (int)dexterity%((int)dif); 
    }

    double monster_defence = monster->get_defence();
    double monster_probablity_of_escape = monster->get_probability_of_escape();

    double r = rand()%100;
    if( r <= monster_probablity_of_escape)
    {
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

    if(kind_of_spell == "IceSpell")
    {
        double damage_low_monster = monster->get_damage_low() - damage;
        if( damage_low_monster < 0)damage_low_monster = 0;

        double damage_high_monster = monster->get_damage_high() - damage;
        if( damage_high_monster < 0)damage_high_monster = 0;
        
        monster->set_damage( damage_low_monster, damage_high_monster);
        monster->set_rounds( rounds);
    }
    else if( kind_of_spell == "FireSpell")
    {
        damage = monster->get_defence() - damage;
        if( damage < 0)damage = 0;

        monster->set_defence( damage);
        monster->set_rounds( rounds);
    }
    else
    {
        damage = monster->get_probability_of_escape() - damage;
        if( damage < 0)damage = 0;

        monster->set_probability_of_escape( damage);
        monster->set_rounds( rounds);
    }

    return true;
    

}



////////////////////////////////////







//WARRIOR
const double Warrior::point_strength = 0.4;
const double Warrior::point_agility = 0.2;

Warrior::Warrior( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght + strenght*point_strength, dexterity, agility + agility*point_agility, "Warrior", x, y){}

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

void Warrior::diplayStats(){
    Hero::displayStats();
}
/////////////////////////////////


//SORCERER
const double Sorcerer::point_dexterity = 0.4;
const double Sorcerer::point_agility = 0.3;

Sorcerer::Sorcerer( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght, dexterity + dexterity*point_dexterity, agility + agility*point_agility, "Sorcerer", x, y){}

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

void Sorcerer::displayStats(){
    Hero::displayStats();
}


//////////////////////////


//PALADIN
const double Paladin::point_strength = 0.4;
const double Paladin::point_dexterity = 0.3;

Paladin::Paladin( string name, double strenght, double dexterity, double agility, int x, int y)
        : Hero( name, strenght + strenght*point_strength, dexterity + dexterity*point_dexterity, agility, "Paladin", x, y){}

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

void Paladin::displayStats(){
    Hero::displayStats();
}

////////////////////////////




//MONSTER
const double Monster::point = 0.4;
Monster::Monster( string name, double damage_low, double damage_high, double defence, double probability_of_escape, string monster)
        : Living_Being( name, "Monster")
{
    this->damage_high = damage_high;
    this->damage_low = damage_low;
    this->defence = defence;
    this->probability_of_escape = probability_of_escape;

    this->monster = monster;

    //Original Εύρος ζημιάς.
    original_damage_low = damage_low;
    original_damage_high = damage_high;
    original_defence = defence;
    original_probability_of_escape = probability_of_escape; //[0,100]
    rounds = 0;

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

int Monster::get_rounds()const
{
    return rounds;
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

void Monster::set_rounds( int rounds)
{
    this->rounds = rounds;
}

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

void Monster::attack(Hero* hero){
    srand(time(NULL));
    double damage = this->damage_low + rand()%(int)(damage_high - damage_low);
    int r = rand() % 100; 
    if(r > hero->get_agility())return;
    hero->set_healthPower(damage);
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

void Monster::displayStats(){
    this->print_monster();
}
///////////////////////////////////////




//DRAGON
const double Dragon::point_attack = 0.3;
Dragon::Dragon( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low + point_attack*damage_low, damage_high + damage_high*point_attack, defence, probability_of_escape, "Dragon"){}

void Dragon::level_up()
{
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

Exoskeleton::Exoskeleton( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low, damage_high, defence + defence*point_defence, probability_of_escape, "Exoskeletion"){}

void Exoskeleton::level_up()
{
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

Spirit::Spirit( string name, double damage_low, double damage_high, double defence, double probability_of_escape)
        : Monster( name, damage_low, damage_high, defence, probability_of_escape + point_probability_of_escape*probability_of_escape, "Spirit"){}

void Spirit::level_up()
{
    double probability_of_escape = get_probability_of_escape();
    probability_of_escape = probability_of_escape + probability_of_escape*point_probability_of_escape;
    set_probability_of_escape( probability_of_escape);
    
    Monster::level_up();
}

void Spirit::displayStats(){
    Monster::displayStats();
}
//////////////////////////////////////
