#include "Grid.h"
#include "Living_Being.h"
#include "Item.h"
#include "Spell.h"
#include "information.h"
#include <iostream>

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
    grid->displayMap();

    // grid->quitGame();
    
}