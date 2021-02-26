////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                ROLE PLAYING GAME                                       //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////


#include "Living_Being.h"
#include "Item.h"
#include "Spell.h"
#include "information.h"
#include <iostream>
#include "Grid.h"

#include <fstream>
#include <iostream> 
#include <cstdlib>
#include <ctime>

using namespace std;


//struct for heroes and monster
//this struct help us in read file
struct input_1{
    string name;
    double x1;
    double x2;
    double x3;   
    double x4; //null for heroes
}; 



int main( void)
{      
    srand(time(NULL));

    
    //Start the game
    cout << BOLDBLACK << "ROLE PLAYING GAME" << RESET << endl;

    cout << "Press 1 to Start Game" << endl;
    cout << "Press 2 to Quit" << endl;

    int answer;
    cin >> answer;
    while(answer != 1 && answer != 2){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }

    if( answer == 2){
        cout<<"You just quit"<<endl;
        return -1;
    }

    //the player chooses the dimensions of the grid for the game 
    cout << GREEN <<"Choose Grid for Game." << RESET <<endl;
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


    ////x and y are the dimensions of the grid
    int x;
    int y;
    if( answer == 1){ x = 8; y = 8;}
    else if( answer == 2){ x = 10; y = 10;}
    else if( answer == 3){ x = 12; y = 12;}
    else if( answer == 4){ x = 15; y = 10;}
    else if( answer == 5){ x = 20; y = 15;}
    else{ x = 20; y = 20;}

    //create grid with x and y
    Grid* grid = new Grid( x, y);

    string in;

    //for read file with heroes and monsters
    string name;
    double x1;
    double x2;
    double x3;
    double x4;

    vector< input_1> vector_heroes;
    //file with heroes
    ifstream file_heroes;
    file_heroes.open("../files/heroes.txt");

    while( file_heroes >> name >> x1 >> x2 >> x3)
    {   
        input_1 in;
        in.name = name;
        in.x1 = x1;
        in.x2 = x2;
        in.x3 = x3;
        in.x4 = 0;

        //create vector with heroes
        vector_heroes.push_back( in);
    }
    file_heroes.close();

    //the player choose 1-3 heroes in random
    //from all heroes where have the vector, i choose 3 players in random

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


    //i read the monsters
    ifstream file_monsters;
    file_monsters.open("../files/monsters.txt");

    vector< input_1> vector_monsters;
    
    while( file_monsters >> name >> x1 >> x2 >> x3 >> x4)
    {
        input_1 in;
        in.name = name;
        in.x1 = x1;
        in.x2 = x2;
        in.x3 = x3;
        in.x4 = x4;

        //create vector with monsters
        vector_monsters.push_back( in);
    }
    file_monsters.close();


    int level;
    string characteristic;
    
    //i read armors
    ifstream file_armors;
    file_armors.open("../files/armors.txt");

    vector< Item* > vector_armors;

    while( file_armors >> name >> x1 >> level >> x2)
    {
        Item* armor = new Armor(name, x2, level, x2);

        //i create vector with armors
        vector_armors.push_back(armor);
    }
    file_armors.close();

    //i read potions
    ifstream file_potions;
    file_potions.open("../files/potions.txt");

    vector< Item* > vector_potions;


    while( file_potions >> name >> x1 >> level >> characteristic >> x2)
    {
        Item* potion = new Potion(name, x1, level, characteristic, x2);

        //i create vector with potions
        vector_potions.push_back( potion);    
    }
    file_potions.close();

    int I1;
    int I2;


    //i read Weapons
    ifstream file_weapons;
    file_weapons.open("../files/weapons.txt");

    vector< Item* > vector_weapons;

    while( file_weapons >> name >> x1 >> I1 >> I2 >> x2)
    {   
        Item* weapon = new Weapon(name, x1, I1, I2, x2);

        //i create vector with weapons
        vector_weapons.push_back(weapon);
    }
    
    file_weapons.close();
    
    double x5;

    //i read the spells
    

    //i read the Lightspells
    ifstream file_lightingspells;
    file_lightingspells.open("../files/lightingspells.txt");

    vector< Spell* > vector_lightingspells;

    while( file_lightingspells >> name >> x1 >> I1 >> x2 >> x3 >> x4 >> x5 >> I2)
    {   
        Spell* spell = new LightingSpell(name, x1, I1, x2, x3, x4, x4, I2);
        
        //i create vector with lightspells
        vector_lightingspells.push_back(spell);
    }
    file_lightingspells.close();


    //i read the Icespells
    ifstream file_icespells;
    file_icespells.open("../files/icespells.txt");

    vector< Spell* > vector_icespells;

    while( file_icespells >> name >> x1 >> I1 >> x2 >> x3 >> x4 >> x5 >> I2)
    {   
        Spell* spell = new IceSpell(name, x1, I1, x2, x3, x4, x5, I2);

        //i create vector with icespells
        vector_icespells.push_back(spell);
    }
    file_icespells.close();

    //i read the Firespells
    ifstream file_firespells;
    file_firespells.open("../files/firespells.txt");

    vector< Spell* > vector_firespells;

    while( file_firespells >> name >> x1 >> I1 >> x2 >> x3 >> x4 >> x5 >> I2)
    {   
        Spell* spell = new FireSpell(name, x1, I1, x2, x3, x4, x5, I2);

        //i create vector with firespells
        vector_firespells.push_back(spell);
    }
    file_firespells.close();



    
    //FOR HEROES
    //the player must choose 1-3 heroes for the game
    cout << BOLDBLUE << "Which Heroes do you want to choose?" << RESET << endl;
    
    bool heroes_change = false;

    do{
        //FOR WARRIOR
        cout << "Do you want a Warrior? Yes/No." << endl;
    
        cin >> in;
        while( in != "Yes" && in != "No"){
            
            if( in.compare("quitGame") == 0)
            {
                grid->quitGame();
            }

            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }


        if( in == "Yes")
        {   
            Warrior* warrior = new Warrior( in_1.name, in_1.x1, in_1.x2, in_1.x3, x, y);
            heroes_change = true;
            Hero* hero = warrior;
            
            grid->set_heroes( hero);
        
        }

        //FOR SORCERER
        cout << "Do you want a Sorcerer? Yes/No." << endl;

        cin >> in;
        while( in != "Yes" && in != "No"){

            if( in.compare("quitGame") == 0)
            {
                grid->quitGame();
            }

            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        if( in == "Yes")
        {
            Sorcerer* sorcerer = new Sorcerer( in_2.name, in_2.x1, in_2.x2, in_2.x3, x, y);
            heroes_change = true;
            Hero* hero = sorcerer;
            grid->set_heroes( hero);
        }

        //FOR PALADIN
        cout << "Do you want a Paladin? Yes/No." << endl;

        cin >> in;
        while( in != "Yes" && in != "No"){

            if( in.compare("quitGame") == 0)
            {
                grid->quitGame();
            }
            
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        if( in == "Yes")
        {
            Paladin* paladin = new Paladin( in_3.name, in_3.x1, in_3.x2, in_3.x3, x, y);
            heroes_change = true;
            Hero* hero = paladin;
            grid->set_heroes( hero);
        }

        if( heroes_change == false)
        {
            cout << RED << "YOU MUST CHANGE FROM 1 TO 3 HEROES!" << RESET << endl;
        }
    
    //if the player hasn't chosen a player repeat the questions
    }while( heroes_change == false);


    //i give in monsters with random capacity
    int size = vector_monsters.size();
    for( int i = 0; i < size; i++)
    {
        input_1 in_1 = vector_monsters.at( i);
        int random = rand()%3;
        
        Monster* monster;
        if( random == 0)
        {
            Dragon* dragon = new Dragon( in_1.name, in_1.x1, in_1.x2, in_1.x3, in_1.x4);
            monster = dragon;
        }
        else if( random == 1)
        {
            Exoskeleton* exoskeleton = new Exoskeleton( in_1.name, in_1.x1, in_1.x2, in_1.x3, in_1.x4);
            monster = exoskeleton;
        }
        else
        {
            Spirit* spirit = new Spirit( in_1.name, in_1.x1, in_1.x2, in_1.x3, in_1.x4);
            monster = spirit;
        }

        //set the monsters in grid
        grid->set_monsters( monster);
    }

    //provide the grid with armors, potions, weapons and spells
    int size_vector = vector_armors.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_armors.at(i));
    }

    size_vector = vector_weapons.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_weapons.at(i));
    }

    size_vector = vector_potions.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_potions.at(i));
    }



    //spells

    size_vector = vector_icespells.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_icespells.at(i));
    }
    
    size_vector = vector_firespells.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_firespells.at(i));
    }

    size_vector = vector_lightingspells.size();
    for(int i = 0; i < size_vector; i++){
        grid->provide(vector_lightingspells.at(i));
    }

    //START THE GAME
    grid->StartGame();
}



////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                      END                                               //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////