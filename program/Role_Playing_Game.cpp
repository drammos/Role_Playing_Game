// #include "Grid.h"//
#include "Living_Being.h"
#include "Item.h"
#include "Spell.h"
#include "information.h"
#include <iostream>
#include "Grid.h"

#include <fstream>
#include <iostream> // Χρειάζεται για την έξοδο κειμένου στη γραμμή εντολών
using namespace std;

int main( void)
{
    cout << BOLDBLACK << "ROLE PLAYING GAME" << RESET << endl;

    cout << "Press 1 for Start Game" << endl;
    cout << "Press 2 for Quit" << endl;

    int answer;
    cin >> answer;
    while(answer != 1 && answer != 2){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }

    if( answer == 2)return -1;

    cout << GREEN <<"Change Grid for Game." << RESET <<endl;
    cout << "Press 1 for 8x8" << endl;
    cout << "Press 2 for 10x10" << endl;
    cout << "Press 3 for 12x12" << endl;
    cout << "Press 4 for 15x10" << endl;
    cout << "Press 5 for 20x15" << endl;
    cout << "Press 6 for 20x20" << endl;


    cin >> answer;
    while(answer < 1 || answer > 6){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }

    int x;
    int y;
    if( answer == 1){ x = 8; y = 8;}
    else if( answer == 2){ x = 10; y = 10;}
    else if( answer == 3){ x = 12; y = 12;}
    else if( answer == 4){ x = 15; y = 10;}
    else if( answer == 5){ x = 20; y = 15;}
    else{ x = 20; y = 20;}

    Grid* grid = new Grid( x, y);

    string in;

    string name;
    double strenght;
    double agility;
    double dexterity;

    string filename = "heroes.txt";
    ifstream file_heroes(filename );

    while( file_heroes >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }

    filename = "monsters.txt";
    ifstream file_monsters(filename );

    while( file_monsters >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }
    
    filename = "armors.txt";
    ifstream file_armors(filename );

    while( file_armors >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }

    filename = "potions.txt";
    ifstream file_potions(filename );

    while( file_potions >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }

    filename = "spells.txt";
    ifstream file_spells(filename );

    while( file_spells >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }

    filename = "weapons.txt";
    ifstream file_weapons(filename );

    while( file_weapons >> name >> strenght >> dexterity >> agility)
    {
        cout << name << " " << strenght << " " << dexterity << " " << agility << endl;
    }


    //FOR HEROES
    cout << BOLDBLUE << "Who Heroes you want?" << RESET << endl;
    
    //FOR WARRIOR
    cout << "You want Warrior? Yes/No." << endl;
    
    cin >> in;
    while( in != "Yes" && in != "No"){
        cout << RED << "Invalid answer, try again!" << RESET << endl;
        cin >> in;
    }

    if( in == "Yes")
    {
        Warrior* warrior = new Warrior( name, strenght, dexterity, agility, x, y);
    }

    //FOR SORCERER
    cout << "You want Sorcerer? Yes/No." << endl;

    cin >> in;
    while( in != "Yes" && in != "No"){
        cout << RED << "Invalid answer, try again!" << RESET << endl;
        cin >> in;
    }

    if( in == "Yes")
    {
        Sorcerer* sorcerer = new Sorcerer( name, strenght, dexterity, agility, x, y);
    }

    //FOR PALADIN
    cout << "You want Paladin? Yes/No." << endl;

    cin >> in;
    while( in != "Yes" && in != "No"){
        cout << RED << "Invalid answer, try again!" << RESET << endl;
        cin >> in;
    }

    if( in == "Yes")
    {
        Paladin* paladin = new Paladin( name, strenght, dexterity, agility, x, y);
    }

    grid->displayMap();

    // grid->quitGame();
    
}