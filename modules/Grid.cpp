#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Grid.h"

//Συναρτήσεις για Grid.
Grid::Grid(int x, int y){
    this->x = x;
    this->y = y;
    srand(time(NULL));
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

    }
    else
    {
        
    }
    

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
