// #include "Grid.h"//
#include "Living_Being.h"
#include "Item.h"
#include "Spell.h"
#include "information.h"
#include <iostream>
#include "Grid.h"

#include <fstream>
#include <iostream> // Χρειάζεται για την έξοδο κειμένου στη γραμμή εντολών
#include <cstdlib>
using namespace std;


//struct for heroes and monster
struct input_1{
    string name;
    double x1;
    double x2;
    double x3;   
    double x4; //null for heroes
};

//struct for armors and potion
struct input_2{
    string name;
    string characteristic; //null for armors
    double x1;
    int level;
    double x2;
};

int main( void)
{
    cout << BOLDBLACK << "ROLE PLAYING GAME" << RESET << endl;

    cout << "Press 1 to Start Game" << endl;
    cout << "Press 2 to Quit" << endl;

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
    double x1;
    double x2;
    double x3;
    double x4;

    vector< input_1> vector_heroes;

    //string filename = "/files/heroes.txt";
    ifstream file_heroes;
    file_heroes.open("/files/heroes.txt");

    while( file_heroes >> name >> x1 >> x2 >> x3)
    {   cout << "ela" << endl;
        input_1 in;
        in.name = name;
        in.x1 = x1;
        in.x2 = x2;
        in.x3 = x3;
        in.x4 = NULL;

        vector_heroes.push_back( in);
    }
    file_heroes.close();
    //ο παικτης επιλεγει 1 - 3 ηρωες αρα κραταω 3 ηρωες τυχαια
    //και διαγραφω τους υπολοιπους

    input_1 in_1;
    input_1 in_2;
    input_1 in_3;

    int i = rand()%( vector_heroes.size());
    int k = rand()%( vector_heroes.size());
    int f = rand()%( vector_heroes.size());
    while( i == f || i == k || k == f)
    {
        i = rand()%( vector_heroes.size());
        k = rand()%( vector_heroes.size());
        f = rand()%( vector_heroes.size());
    }
    in_1 = vector_heroes.at( i);
    in_2 = vector_heroes.at( k);
    in_3 = vector_heroes.at( f);

    vector_heroes.clear();


    //διαβαζω τα τερατα
    ifstream file_monsters;
    file_monsters.open("/files/monsters.txt");
    //ifstream file_monsters(filename );
    vector< input_1> vector_monsters;

    while( file_monsters >> name >> x1 >> x2 >> x3 >> x4)
    {
        input_1 in;
        in.name = name;
        in.x1 = x1;
        in.x2 = x2;
        in.x3 = x3;
        in.x4 = x4;

        vector_heroes.push_back( in);
    }
    file_monsters.close();

    int level;
    string characteristic;
    
    //διαβαζω τισ πανοπλιες
    ifstream file_armors;
    file_armors.open("/files/armors.txt");
    //ifstream file_armors(filename );

    vector< input_2> vector_armors;

    while( file_armors >> name >> x1 >> level >> x2)
    {
        input_2 in_;
        in_.name = name;
        in_.x1 = x1;
        in_.x2 = x2;
        in_.level = level;
        in_.characteristic = nullptr;

        vector_armors.push_back( in_);
    }
    file_armors.close();

    //διαβαζω τα φιλτρα
    //filename = "potions.txt";
    ifstream file_potions;
    file_potions.open("/files/potions.txt");

    vector< input_2> vector_potions;


    while( file_potions >> name >> name >> x1 >> level >> characteristic >> x2)
    {
        input_2 in_;
        in_.name = name;
        in_.x1 = x1;
        in_.x2 = x2;
        in_.level = level;
        in_.characteristic = characteristic;

        vector_potions.push_back( in_);    
    }
    file_potions.close();

    //διαβαζω τα ξορκια
    
    filename = "spells.txt";
    ifstream file_spells( filename);

    vector< string> vector_spells;

    while( file_spells >> name)
    {
        vector_spells.push_back( name);
    }


    //διαβαζω τα Weapons
    //filename = "weapons.txt";
    ifstream file_weapons;
    file_weapons.open("/files/weapons.txt");

    vector< string> vector_weapons;

    while( file_weapons >> name)
    {
        vector_weapons.push_back( name);
    }
    file_weapons.close();

    //FOR HEROES
    cout << BOLDBLUE << "Which Heroes do you want to choose?" << RESET << endl;
    
    bool heroes_change = false;

    do{
        //FOR WARRIOR
        cout << "Do you want a Warrior? Yes/No." << endl;
    
        cin >> in;
        while( in != "Yes" && in != "No"){
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        if( in == "Yes")
        {   
        
            Warrior* warrior = new Warrior( in_1.name, in_1.x1, in_1.x2, in_1.x3, x, y);
            heroes_change = true;
        }

        //FOR SORCERER
        cout << "Do you want a Sorcerer? Yes/No." << endl;

        cin >> in;
        while( in != "Yes" && in != "No"){
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        if( in == "Yes")
        {
            Sorcerer* sorcerer = new Sorcerer( in_2.name, in_2.x1, in_2.x2, in_2.x3, x, y);
            heroes_change = true;
        }

        //FOR PALADIN
        cout << "Do you want a Paladin? Yes/No." << endl;

        cin >> in;
        while( in != "Yes" && in != "No"){
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        if( in == "Yes")
        {
            Paladin* paladin = new Paladin( in_3.name, in_3.x1, in_3.x2, in_3.x3, x, y);
            heroes_change = true;
        }

        if( heroes_change == false)
        {
            cout << RED << "YOU MUST CHANGE FROM 1 UNTIL 3 HEROES!" << RESET << endl;
        }

    }while( heroes_change == false);

    grid->displayMap();

    // grid->quitGame();
    
}