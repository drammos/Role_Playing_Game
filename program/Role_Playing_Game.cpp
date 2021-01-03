#include "Grid.h"
#include "Living_Being.h"
#include "Item.h"
#include "Spell.h"

int main( void)
{
    cout << "Hello" << endl;
    Grid* grid = new Grid( 8, 8);
    grid->displayMap();
    
    grid->quitGame();
    
}