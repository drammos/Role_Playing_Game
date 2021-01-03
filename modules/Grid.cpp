#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.h"

//Συναρτήσεις για Grid.
Grid::Grid(int x, int y){
    this->x = x;
    this->y = y;
    srand(time(NULL));
    squares = new Square**[x];
    for(int i = 0; i < x; i++)
    {
        squares[i] = new Square*[y];
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int r = rand() % 3;
            if(r == 0)
                this->squares[i][j] = new nonAccessible();
            else if(r == 1)
                this->squares[i][j] = new Market();
            else
                this->squares[i][j] = new Common();
        }
    }
}

Grid::~Grid(){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            delete this->squares[i][j];
        }
    }
}


void Grid::checkInventory( Hero* hero)
{
    hero->print_item();
}

void Grid::equip( Hero* hero)
{
    cout << "Τι θελετε να αλλαξετε;" << endl;
    cout << "1) Weapon" << endl;
    cout << "2) Armor" << endl;

    //δεχομαστε 1 ή 2 απο χρηστη
    int in;
    cin >> in; 
    while( in != 1 && in != 2)
    {
        cout << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << endl;
        cin >> in;
    }
    
    if( in == 1)
    {
        cout << "What you want to take?" << endl;
        int number_Weapon = hero->print_Weapon();
        int w;
        if(number_Weapon != 0)
        {
            
            cin >> w;
            while( w <= 0 || w > number_Weapon)
            {
                cout << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << endl;
                cin >> w;
            }

            hero->set_Weapon( w - 1);
        }
    }
    else
    {
        cout << "What you want to take?" << endl;
        int number_Armor = hero->print_Armor();
        int a;
        if(number_Armor != 0)
        {
            cin >> a;
            while( a <= 0 || a > number_Armor)
            {
                cout << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << endl;
                cin >> a;
            }

            hero->set_Armor( a - 1);
        }
    }

}

void Grid::use( Hero* hero)
{
    cout << "What potion you want to use?" << endl;
    int number_Potion = hero->print_Potion();
    int p;
    if(number_Potion != 0)
    {
        cin >> p;
        while( p <= 0 || p > number_Potion)
        {
            cout << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << endl;
            cin >> p;
        }

        hero->Take_Potion( p - 1);
    }
}

void Grid::print_Hero( Hero* hero)const
{
    hero->print_hero();
}

void Grid::displayMap()const
{
    for(int i = 0; i<8;i++)
    {   
        cout << "\u2500" << endl;
        cout << "\u2502\u2500";
        
        
        // cout << "\u2518";
        // cout << "\u2551 ";
    }
    cout << endl;
}
















//////////////////////////////////////////

//Συναρτήσεις για Square.
Square::Square(string s){
    this->kind_of_square.assign(s);
}

Square::~Square(){
    this->heroes.clear();
    this->monsters.clear();
}

void Square::add_hero(Hero* h){
    this->heroes.push_back(h);
}

void Square::add_monster(Monster* m){
    this->monsters.push_back(m);
}

void Square::remove_heroes(){
    this->heroes.clear();
}

string Square::get_kind_of_square() const{
    return this->kind_of_square;
}


//Συναρτήσεις για Market.
Market::~Market(){
    this->items.clear();
    this->spells.clear();
}

void Market::insert_item(Item* item){
    this->items.push_back(item);
}

void Market::insert_spell(Spell* spell){
    this->spells.push_back(spell);
}

void Market::buy(Hero* hero){
    cout<<"What would you like to buy?"<<endl;
    cout<<"Press 1 for Items"<<endl;
    cout<<"Press 2 for Spells"<<endl;
    int a;
    cin>>a;
    if(a == 1){
        cout<<"The items available in the market are:"<<endl;
        for(int i = 0; i < this->items.size(); i++){
            cout<<i+1<<") ";
            this->items.at(i)->print();
        }
        cout<<"Press the number of the item you would like to purchase"<<endl;
        int a1;
        cin>>a1;
        while(a1 > this->items.size() || a1 <= 0){
            cout<<"Invalid number, try again!"<<endl;
            cin>>a1;
        }
        Item* item = this->items.at(a1-1);
        hero->buy_Item(item);
    }
    else{
        cout<<"The spells available in the market are:"<<endl;
        for(int i = 0; i < this->spells.size(); i++){
            cout<<i+1<<") ";
            this->spells.at(i)->print();
        }
        cout<<"Press the number of the spell you would like to purchase"<<endl;
        int a1;
        cin>>a1;
        while(a1 > this->spells.size() || a1 <= 0){
            cout<<"Invalid number, try again!"<<endl;
            cin>>a1;
        }
        Spell* spell = this->spells.at(a1-1);
        hero->buy_Spell(spell);
    }
}

void Market::sell(Hero* hero){
    cout<<"What would you like to sell?"<<endl;
    cout<<"Press 1 for Items"<<endl;
    cout<<"Press 2 for Spells"<<endl;
    int a;
    cin>>a;
    if(a == 1){
        int number = hero->print_item();
        cout<<"Press the number of the item you would like to sell"<<endl;
        int a1;
        cin>>a1;
        while(a1 <= 0 || a1> number){
            cout<<"Invalid number, try again!"<<endl;
            cin>>a1;
        }
        hero->sell_Item(a1-1);
    }
    else{
        int number = hero->print_spell();
        cout<<"Press the number of the spell you would like to sell"<<endl;
        int a1;
        cin>>a1;
        while(a1 <= 0 || a1> number){
            cout<<"Invalid number, try again!"<<endl;
            cin>>a1;
        }
        hero->sell_Spell(a1-1);
    }
}
