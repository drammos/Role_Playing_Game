////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                      GRID                                              //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Grid.h"

//Functions for Grid



//constructor
Grid::Grid(int x, int y){

    //x and y are the dimensions of the grid
    //that the player chooses
    this->x = x;
    this->y = y;

    //consrtuctor coordinates for heroes
    x_heroes = -1;
    y_heroes = -1;

    srand(time(NULL));
    squares = new Square**[x];
    for(int i = 0; i < x; i++)
    {
        squares[i] = new Square*[y];
    }

    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            int r = rand() % 10;
            //depending on a probability the square has one capacity
            if(r == 1)
                this->squares[i][j] = new nonAccessible();
            else if(r == 3 || r == 7)
                this->squares[i][j] = new Market();
            else
                this->squares[i][j] = new Common();
        }
    }
}


//destructor
Grid::~Grid(){
    for(int i = 0; i < x; i++){
        for(int j = 0; j < y; j++){
            delete this->squares[i][j];
        }
    }
}

//puttting the heroes randomly in the grid
void Grid::set_heroes( Hero* hero)
{   
    
    if( x_heroes == -1)
    {
        srand( time(NULL));
        bool in = false;
        while( in != true)
        {   
            x_heroes = rand()%(x);
            y_heroes = rand()%(y);

            //Checking if the squares around the square the heroes are at, are all non accessible.
            int x1_heroes, x2_heroes, y1_heroes, y2_heroes;
            if(x_heroes == 0){
                x1_heroes = this->x - 1;
                x2_heroes = 1;
            }
            else if(x_heroes == this->x - 1){
                x2_heroes = 0;
                x1_heroes = this->x - 2;
            }
            else{
                x1_heroes = x_heroes - 1;
                x2_heroes = x_heroes + 1;
            }

            if(y_heroes == 0){
                y1_heroes = this->y - 1;
                y2_heroes = 1;
            }
            else if(y_heroes == this->y - 1){
                y1_heroes = this->y - 2;
                y2_heroes = 0;
            }
            else{
                y1_heroes = y_heroes - 1;
                y2_heroes = y_heroes + 1;
            }
            //In the beginning heroes are placed in a market square. 
            //to buy weapons
            if( (squares[x_heroes][y_heroes]->get_kind_of_square()).compare( "Market") == 0)
            {   
                if(squares[x1_heroes][y_heroes]->get_kind_of_square().compare("NonAccessible") != 0 || squares[x2_heroes][y_heroes]->get_kind_of_square().compare("NonAccessible") != 0 || squares[x_heroes][y1_heroes]->get_kind_of_square().compare("NonAccessible") != 0 || squares[x_heroes][y2_heroes]->get_kind_of_square().compare("NonAccessible") != 0){
                    in = true;
                }
            }
        }
    }

    hero->set_x( x_heroes);
    hero->set_y( y_heroes);
    squares[x_heroes][y_heroes]->add_hero( hero);
}


//i put the monsters randomly in the grid
void Grid::set_monsters( Monster* monster)
{
    bool in = false;
    int x1;
    int y1;
    while( in != true)
    {   
        x1 = rand()%x;
        y1 = rand()%y;
        //the monster must be in common squares
        if( (squares[x1][y1]->get_kind_of_square()).compare( "Common") == 0)
        {   

            //with a probability the monster is placed on the grid, otherwise it is not
            int num_rand = rand()%7;
            if( num_rand <= 3)
            {
                squares[x1][y1]->add_monster( monster);
            }

            in = true;
        }   
    }
}



//Startgame from here
void Grid::StartGame()
{

    //vector with heroes    
    vector<Hero*> vector_heroes;
    vector_heroes = squares[x_heroes][y_heroes]->get_heroes();
    

    for(unsigned int i = 0; i < vector_heroes.size(); i++)
    {   
        bool buy_weapon = false;
        Hero* hero =  vector_heroes.at(i);

        //every heroe must buy a weapon for the war
        while(buy_weapon == false){

            cout << RED << "You must buy a Weapon for " << hero->get_name() << RESET << endl;
            buy_weapon = squares[x_heroes][y_heroes]->buy( hero);
            
            if( hero->get_money() == 0 && buy_weapon == false)
            {
                cout << RED << "YOU LOSE!!!, BECAUSE YOU DON'T HAVE ENOUGH MONEY TO BUY A WEAPON FOR WAR!!!" << RESET << endl;
                quitGame();
            }
        }
    }
    

    bool level_heroes = false;
    //if the level of the heroes is MAX_LEVEL then the game is over
    while( level_heroes == false)
    {   
        string kind_of_square = squares[x_heroes][y_heroes]->get_kind_of_square();

        //if the heroes are in a Market square
        if( kind_of_square.compare( "Market") == 0)
        {   
            for(unsigned int i = 0; i < vector_heroes.size(); i++)
            {   
                Hero* hero =  vector_heroes.at(i);
                cout << "Hero: " << BLUE <<hero->get_hero() << RESET << " " << endl;    
                buy_sell_and_equip( hero);
            }
        }
        //if the heroes are in a Common square
        else if( kind_of_square.compare( "Common") == 0)
        {   
            squares[x_heroes][y_heroes]->War();
        }

        //the heroes have to move
        move( vector_heroes);

        //print map
        displayMap();

        //if all heroes are in the max level the game is over
        unsigned int size_max_level = 0;
        for(unsigned int i = 0; i < vector_heroes.size(); i++)
        {
            Hero* hero =  vector_heroes.at(i);
            if( hero->get_level() == MAX_LEVEL)
            {
                size_max_level++;
            }
        }
        if( size_max_level == vector_heroes.size())
        {
            level_heroes = true;
        }
    }

    //print map 
    displayMap();
    
}

//
void Grid::checkInventory( Hero* hero)
{
    hero->print_item();
}

//change the Weapon or the Armor a hero currently uses.
void Grid::equip( Hero* hero)
{   
    cout << "What do you want to change?" << endl;
    cout << "Press 1 Weapon" << endl;
    cout << "Press 2 Armor" << endl;

    //take input from User
    int in;
    cin >> in; 
    while( in != 1 && in != 2)
    {   
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> in;
    }
    
    //Change Weapon
    if( in == 1)
    {
        //print all the weapons the player has bought for a hero
        int number_Weapon = hero->print_Weapon();
        int w;
        if(number_Weapon != 0)
        {
            cout << endl << BOLDBLUE << "What do you want to change?" << RESET << endl;   
            cin >> w;
            while( w <= 0 || w > number_Weapon)
            {
                cout << RED << "Invalid number, try again!" << RESET << endl;
                cin >> w;
            }


            hero->set_Weapon( w - 1);
        }
    }
    //Change Armor
    else
    {
        //print all the armors the player has bought for a hero
        int number_Armor = hero->print_Armor();
        int a;
        if(number_Armor != 0)
        {   
            cout << endl << BOLDBLUE << "What you want to change?" << RESET << endl; 
            cin >> a;
            while( a <= 0 || a > number_Armor)
            {
                cout << RED << "Invalid number, try again!" << RESET << endl;
                cin >> a;
            }

            hero->set_Armor( a - 1);
        }
    }

}

//Use Potion for Hero
void Grid::use( Hero* hero)
{
    int number_Potion = hero->print_Potion();
    int p;
    if(number_Potion != 0)
    {
        cout << endl << BOLDBLUE <<"What potion you want to use?" << RESET << endl;
        cin >> p;
        while( p <= 0 || p > number_Potion)
        {
            cout << RED << "Invalid number, try again!" << RESET << endl;
            cin >> p;
        }

        //take potion for the hero is called
        hero->Take_Potion( p - 1);
    }
}

//print hero
void Grid::print_Hero( Hero* hero)const
{
    hero->print_hero();
}

//Prints the Grid
//with ascii characters
void Grid::displayMap()const
{   

    cout << BOLDMAGENTA << "The Map" << RESET << endl;
    
    for(int i = 0; i< x;i++)
    {   
        for(int j = 0; j < y; j++)
        {
            
            cout << "\u250C";
            cout << "\u2500\u2500\u2500";
            cout << "\u2510";       
        }
        cout << endl;
        for(int j = 0; j < y; j++)
        {
            cout << "\u2502";
            if(squares[i][j]->get_kind_of_square() == "Market" )
            {   
                int k = squares[i][j]->contains();
                //H is for Heroes
                //S is for store(MARKET)
                if( k == 0)
                {
                    cout << BLUE << "H " << RESET;
                    cout << YELLOW << "S" << RESET;
                }
                else
                {
                    cout << YELLOW << " S " << RESET;
                }
            }
            else if( squares[i][j]->get_kind_of_square() == "nonAccessible")
            {   
                //X is for NonAccesible
                cout << RED << " X " << RESET;
            }
            else
            {   
                int k = squares[i][j]->contains();
                //H is for Heroes
                //M is for Monsters
                //B is for Both( Monsters and heroes)
                if( k == 0)
                {
                    cout << BLUE << " H " << RESET;
                }
                else if( k == 1)
                {
                    cout << MAGENTA << " M " << RESET;
                }
                else if( k == 2)
                {
                    cout << GREEN << " B " << RESET;
                }
                else
                {
                    cout << "   " << RESET;
                }
            }
            
            cout << "\u2502";      
        }
        cout << endl;

        for(int j = 0; j < y; j++)
        {
            cout << "\u2514";
            cout << "\u2500\u2500\u2500";
            cout << "\u2518";    
        }
        cout << endl;
    }
    cout << endl;
}


//STOP THE GAME
void Grid::quitGame()
{
    cout << BOLDRED << "YOU LOSE!" << RESET << endl;
    exit(EXIT_FAILURE);
}




//
void Grid::move(vector <Hero*> heroes){
    //Prints the grid.
    displayMap();
    //For the north direction.
    int a;
    int f1 = 1;
    //If the heroes are at the first row then, following the "up" direction, they move to the last row.
    if(heroes.at(0)->get_x() == 0){
        a = this->x-1;
    }
    else{
        a = heroes.at(0)->get_x() - 1;
    }
    if(squares[a][heroes.at(0)->get_y()]->get_kind_of_square().compare("nonAccessible") == 0){
        f1 = 0;
    }
    //For the south direction.
    int f2 = 2;
    //If the heroes are at the last row then, following the "down" direction, they move to the first row.
    if(heroes.at(0)->get_x() == this->x-1){
        a = 0;
    }
    else{
        a = heroes.at(0)->get_x() + 1;
    }
    if(squares[a][heroes.at(0)->get_y()]->get_kind_of_square().compare("nonAccessible") == 0){
        f2 = 0;
    }
    //For the west direction.
    int f3 = 3;
    //If the heroes are at the first column then, following the "left" direction, they move to the last column.
    if(heroes.at(0)->get_y() == 0){
        a = this->y-1;
    }
    else{
        a = heroes.at(0)->get_y() - 1;
    }
    if(squares[heroes.at(0)->get_x()][a]->get_kind_of_square().compare("nonAccessible") == 0){
        f3 = 0; 
    }
    //For the east direction.
    int f4 = 4;
    //If the heroes are at the last column then, following the "right" direction, they move to the first column.
    if(heroes.at(0)->get_y() == this->y-1){
        a = 0;
    }
    else{
        a = heroes.at(0)->get_y() + 1;
    }
    if(squares[heroes.at(0)->get_x()][a]->get_kind_of_square().compare("nonAccessible") == 0){
        f4 = 0;
    }
    cout<<"Where do you want to go?"<<endl;
    //Only the accessible directions are printed.
    if(f1 == 1)
        cout<<"Press 1 for up."<<endl;
    if(f2 == 2)
        cout<<"Press 2 for down."<<endl;
    if(f3 == 3)
        cout<<"Press 3 for left."<<endl;
    if(f4 == 4)
        cout<<"Press 4 for right."<<endl;
    int answer;
    cin>>answer;
    while(answer == 0 && answer != f1 && answer != f2 && answer != f3 && answer != f4){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }
    if(answer == 1){
        int a;
        if(heroes.at(0)->get_x() == 0){
            a = this->x-1;
        }
        else{
            a = heroes.at(0)->get_x() - 1;
        }
        //Heroes are removed from the current square.
        squares[heroes.at(0)->get_x()][heroes.at(0)->get_y()]->remove_heroes();
        //and added to the other one.
        for(unsigned int i = 0; i < heroes.size(); i++){
            squares[a][heroes.at(0)->get_y()]->add_hero(heroes.at(i));
            heroes.at(i)->set_x(a);
            x_heroes = a;
        }
    }
    else if(answer == 2){
        int a;
        if(heroes.at(0)->get_x() == this->x-1){
            a = 0;
        }
        else{
            a = heroes.at(0)->get_x() + 1;
        }
        squares[heroes.at(0)->get_x()][heroes.at(0)->get_y()]->remove_heroes();
        for(unsigned int i = 0; i < heroes.size(); i++){
            squares[a][heroes.at(0)->get_y()]->add_hero(heroes.at(i));
            heroes.at(i)->set_x(a);
            x_heroes = a;
        }
    }
    else if(answer == 3){
        int a;
        if(heroes.at(0)->get_y() == 0){
            a = this->y-1;
        }
        else{
            a = heroes.at(0)->get_y() - 1;
        }
        squares[heroes.at(0)->get_x()][heroes.at(0)->get_y()]->remove_heroes();
        for(unsigned int i = 0; i < heroes.size(); i++){
            squares[heroes.at(0)->get_x()][a]->add_hero(heroes.at(i));
            heroes.at(i)->set_y(a);
            y_heroes = a;
        }
    }
    else{
        int a;
        if(heroes.at(0)->get_y() == this->y-1){
            a = 0;
        }
        else{
            a = heroes.at(0)->get_y() + 1;
        }
        squares[heroes.at(0)->get_x()][heroes.at(0)->get_y()]->remove_heroes();
        for(unsigned int i = 0; i < heroes.size(); i++){
            squares[heroes.at(0)->get_x()][a]->add_hero(heroes.at(i));
            heroes.at(i)->set_y(a);
            y_heroes = a;
        }
    }
}

//fuction for heroes
//buy, sell and change item/spell
void Grid::buy_sell_and_equip( Hero* hero)
{
    string answer;

    //if the player wants to buy something
    do{
        cout << "Do you want to buy anything?" << endl;
        cin >> answer;

        while( answer != "Yes" && answer != "No"){
            
            if( answer.compare("quitGame") == 0)
            {
                quitGame();
            }
            
            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> answer;
        }

        if( answer.compare( "Yes") == 0)
        {
            squares[x_heroes][y_heroes]->buy( hero);
        }

    }while(  answer.compare( "Yes") == 0 && hero->get_money() > 0);

    //if the player wants to sell
    int count_item_and_spell;
    do{
        cout << "Do you want to sell anything?" << endl;
        cin >> answer;

        while( answer != "Yes" && answer != "No"){

            if( answer.compare("quitGame") == 0)
            {
                quitGame();
            }

            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> answer;
        }

        if( answer.compare( "Yes") == 0)
        {
            squares[x_heroes][y_heroes]->sell( hero);
        }

        count_item_and_spell = hero->get_count_item_and_spell();

    }while(  answer.compare( "Yes") == 0 && count_item_and_spell > 0);

    //If the hero wants to change the item they currently use
    string in;
    do{
        cout << "You want change Item?" << endl;
        cin >> in;

        while( in.compare("Yes") != 0 && in.compare("No") != 0){

            if( answer.compare("quitGame") == 0)
            {
                quitGame();
            }

            cout << RED << "Invalid answer, try again!" << RESET << endl;
            cin >> in;
        }

        //equip for this hero is called
        if( in.compare("Yes") == 0)
        {
            equip( hero);
        }

    }while( in.compare("Yes") == 0);
        
}


void Grid::provide(Item* item){
    //For every square.
    for(int i = 0; i < this->x; i++){
        for(int j = 0; j < this->y; j++){
            //If the square is a market.
            if(this->squares[i][j]->get_kind_of_square().compare("Market") == 0){
                //Insertion of the item to this square to be available for sale.
                this->squares[i][j]->insert_item(item);
            }
        }
    }
}


void Grid::provide(Spell* spell){
    //For every square.
    for(int i = 0; i < this->x; i++){
        for(int j = 0; j < this->y; j++){
            //If the square is a market.
            if(this->squares[i][j]->get_kind_of_square().compare("Market") == 0){
                //Insertion of the spell to this square to be available for sale.
                this->squares[i][j]->insert_spell(spell);
            }
        }
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

//STOP THE GAME
void Square::quitGame()
{
    cout << BOLDRED << "YOU LOSE!" << RESET << endl;
    exit(EXIT_FAILURE);
}

void Square::add_hero(Hero* h){
    this->heroes.push_back(h);
}

void Square::add_monster(Monster* m){
    this->monsters.push_back(m);
}

vector <Hero*> Square::remove_heroes(){
    //The heroes are kept in a vector which is returned.
    vector <Hero*> vec;
    for(unsigned int i = 0; i < this->heroes.size(); i++){
        vec.push_back(this->heroes.at(i));
    }
    this->heroes.clear();
    return vec;
}

string Square::get_kind_of_square() const{
    return this->kind_of_square;
}

int Square::contains(){
  if(this->heroes.size() > 0 && this->monsters.size() > 0)
        return 2;
    else if(this->monsters.size() > 0)
        return 1;
    else if(this->heroes.size() > 0)
        return 0;
    else
        return 3;  
}

int Square::alive(){
    //Counting the alive heroes.
    int h = 0;
    for(unsigned int i = 0; i < this->heroes.size(); i++){
        if(this->heroes.at(i)->get_healthPower() != 0.0)
            h++;
    }
    //Counting the alive monsters.
    int m = 0;
    for(unsigned int i = 0; i < this->monsters.size(); i++){
        if(this->monsters.at(i)->get_healthPower() != 0.0)
            m++;
    }
    if(m != 0 && h != 0)
        return 0;
    else if(m > 0)
        return 1;
    else
        return 2;
}

void Square::War(){   
    //If the are no monters in the square there is no point in having a war.
    if(this->monsters.size() == 0)return;
    //there is 0.33 possibility for the heroes to fight againts the monsters.
    int r = rand()%3;
    if(r)return;

    cout<< MAGENTA << "You are on a war with "<<this->monsters.size()<<" monsters"<< RESET << endl;
    //The heroes an the monsters must have the same level to fight against each other.
    if(this->heroes.at(0)->get_level() > this->monsters.at(0)->get_level()){
        for(unsigned int i = 0; i < this->monsters.size(); i++){
            this->monsters.at(i)->level_up();
        }
    }
    //If there are both monsters and heroes alive.
    while(this->alive() == 0){
        for(unsigned int i = 0; i < this->heroes.size(); i++){
            cout << endl << endl << "The Hero " << BOLDGREEN << this->heroes.at(i)->get_hero() << RESET <<", with name: "<<this->heroes.at(i)->get_name() << endl;
            if(this->heroes.at(i)->get_healthPower() == 0.0)
                continue;
            cout << BLUE <<"How do you want to attack your oponents?" << RESET << endl; 
            cout << "Press 1 for Attack" << endl;
            cout << "Press 2 for CastSpell" << endl;
            cout << "Press 3 for Potion" << endl;

            int w;
            cin >> w;
            while( w <=0 || w > 3){
                cout << RED << "Invalid number, try again!" << RESET << endl;
                cin >> w;
            }
            //Potion.
            if( w == 3){
                //If the hero hasn't bought any potions they have to select another way of attack.
                int p = this->heroes.at(i)->print_Potion();
                if(p == 0){
                    cout<< MAGENTA << "Select another way of attack" << RESET << endl;
                    cin>>w;
                    while(w != 1 && w != 2){
                        cout<< RED <<"Invalid number, try again!"<< RESET << endl;
                        cin>>w;
                    }
                    cout << MAGENTA << "Which monster do you want to fight against?" << RESET << endl << endl;
                    for(unsigned int j = 0; j < this->monsters.size(); j++){
                        if(this->monsters.at(j)->get_healthPower() > 0){
                            cout<<j+1<<")";
                            this->monsters.at(j)->print_monster();
                            cout<<endl;
                        }
                    }
                    //If all the monsters are dead the war is over.
                    if(this->alive() == 2)
                        break;
                    cout<<"Press the number of the monster you want to fight against"<<endl;
                    unsigned int a1;
                    cin>>a1;
                    while(a1 <= 0 || a1 > this->monsters.size()){
                        cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                        cin>>a1;
                    }
                    while(this->monsters.at(a1-1)->get_healthPower() <= 0){
                        cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                        cin>>a1;
                    }
                    //Simple attack.
                    if(w == 1){
                        this->heroes.at(i)->attack(this->monsters.at(a1-1));
                    }
                    //Attack by spell.
                    else{
                        //If the hero can't cast a spell.
                        bool f = this->heroes.at(i)->castSpell(this->monsters.at(a1-1));
                        if(f == false){
                            //The only choice is a simple attack.
                            cout<<"The only way to attack is by a simple attack"<<endl;
                            this->heroes.at(i)->attack(this->monsters.at(a1-1));
                        }
                    }
                }
                //If there are available potions.
                else{
                    cout<< MAGENTA << "Please press the number of the Potion you want to take" << RESET <<endl;
                    int a;
                    cin>>a;
                    while(a <= 0 || a > p){
                        cout<< RED << "Invalid number, try again!" << RESET << endl;
                        cin>>a;
                    }
                    this->heroes.at(i)->Take_Potion(a-1);
                }
            }
            //If the player chooses another way of attack, other than a potion.
            else{   
                cout << MAGENTA <<"Which monster do you want to fight against?" << RESET << endl;
                for(unsigned int j = 0; j < this->monsters.size(); j++){
                    if(this->monsters.at(j)->get_healthPower() > 0){
                        cout<<j+1<<")";
                        this->monsters.at(j)->print_monster();
                        cout<<endl;
                    }
                }
                //If all the monsters are dead, the war is over.
                if(this->alive() == 2)
                    break;
                
                cout << endl << MAGENTA <<"Press the number of the monster you want to fight against" << RESET <<endl;
                
                unsigned int a1;
                cin>>a1;
                
                while(a1 <= 0 || a1 > this->monsters.size())
                {
                    cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                    cin>>a1;
                }
                
                while(this->monsters.at(a1-1)->get_healthPower() <= 0){
                    cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                    cin>>a1;
                }
                
                //If the choice of the player is a simple attack.
                if(w == 1){
                    this->heroes.at(i)->attack(this->monsters.at(a1-1));
                }
                //If the player chooses to cast a spell.
                else
                {   
                    //If the player can't cast a spell.
                    bool f = this->heroes.at(i)->castSpell(this->monsters.at(a1-1));
                    if(f == false){
                        cout<< BLUE <<"Select another way of attack"<< RESET <<endl;
                        cin>>w;
                        while(w != 1 && w != 3){
                            cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                            cin>>w;
                        }
                        //Somple attack.
                        if(w == 1){
                            this->heroes.at(i)->attack(this->monsters.at(a1-1));
                        }
                        //Potion.
                        else{
                            int p = this->heroes.at(i)->print_Potion();
                            //If the player doesn't have any potions the have to do a simple attack.
                            if(p == 0){
                                cout<<"The only way to attack is by a simple attack"<<endl;
                                this->heroes.at(i)->attack(this->monsters.at(a1-1));
                            }
                            else{
                                cout<<"Please press the number of the Potion you want to take"<<endl;
                                int a;
                                cin>>a;
                                while(a <= 0 || a > p){
                                    cout<< RED << "Invalid number, try again!" << RESET << endl;
                                    cin>>a;
                                }
                                this->heroes.at(i)->Take_Potion(a-1);
                            }
                        }
                    }
                }
            }
        }
        //Every alive monster attacks the first hero that is still alive.
        for(unsigned int i = 0;  i < this->monsters.size(); i++)
        {
            if(this->monsters.at(i)->get_healthPower() == 0.0)
                continue;

            int j = 0;
            while(this->heroes.at(j)->get_healthPower() == 0.0)
            {
                j++;
            }
        
            this->monsters.at(i)->attack(this->heroes.at(j));
            this->monsters.at(i)->reset_fields();
        }
        for(unsigned int i = 0; i < this->heroes.size(); i++)
        {   
            //After every round if a hero has some health power then it is increased by 10%.
            if(this->heroes.at(i)->get_healthPower() != 0.0){
                this->heroes.at(i)->add_healthPower(0.1 * this->heroes.at(i)->get_healthPower());
                //Same for the magic power.
                this->heroes.at(i)->add_magicPower(0.1 * this->heroes.at(i)->get_magicPower());
            }
        }
        for(unsigned int i = 0; i < this->monsters.size(); i++)
        {   
            //After every round if a monster has some health power then it is increased by 10%.
            if(this->monsters.at(i)->get_healthPower() != 0.0)
                this->monsters.at(i)->add_healthPower(0.1 * this->monsters.at(i)->get_healthPower());
        }
        cout<< endl << endl << YELLOW << "Do you want to view Statistics?"<< RESET << endl;
        cout<<"Yes or No"<<endl;
        
        string answer;
        cin >> answer;
        while( answer.compare("Yes") != 0 && answer.compare("No") != 0)
        {   
            if( answer.compare("quitGame") == 0)
            {
                quitGame();
            }
            
            cout<< RED << "Invalid number, try again!" << RESET << endl;
            cin >> answer;
        }
        
        if(answer.compare("Yes") == 0){
            for(unsigned int i = 0; i < this->heroes.size(); i++){
                this->heroes.at(i)->displayStats();
            }
            for(unsigned int i = 0; i < this->monsters.size(); i++){
                this->monsters.at(i)->displayStats();
            }
        }
    }
    //If there are only monsters left alive.
    if(this->alive() == 1)
    {
        cout << endl << endl <<BOLDRED <<"You lost the war"<< RESET << endl;
        for(unsigned int i = 0; i < this->heroes.size(); i++)
        {
            this->heroes.at(i)->set_money(this->heroes.at(i)->get_money() / 2.0);
        }
    }
    else
    {
        cout<< endl << endl << BOLDGREEN<<"You won the war. Congratulations!"<< RESET<<endl;
        for(unsigned int i = 0; i < this->heroes.size(); i++)
        {
            this->heroes.at(i)->add_experience((this->heroes.at(i)->get_level() + EXPERIENCE) * this->monsters.size());
            this->heroes.at(i)->add_money((this->heroes.at(i)->get_level() + MONEY) * this->monsters.size());
        }
    }
    for(unsigned int i = 0; i < this->monsters.size(); i++)
    {
        //The monsters' characteristics that have been changed from the spells or the potions are changed back to the original form after each war.
        this->monsters.at(i)->set_rounds(1);
        this->monsters.at(i)->reset_fields();
        //If a monster has 0 health power after a war it's health power is set to half of the original to be ready for the next war.
        if(this->monsters.at(i)->get_healthPower() == 0.0)
            this->monsters.at(i)->set_healthPower(HEALTH_POWER/2.0);
    
    }
    for(unsigned int i = 0; i < this->heroes.size(); i++)
    {
        //If a hero has 0 health power after a war it's health power is set to half of the original to be ready for the next war.
        if(this->heroes.at(i)->get_healthPower() == 0.0)
            this->heroes.at(i)->set_healthPower(HEALTH_POWER/2.0);
    }
    //If the heroes have gathered the neede experience for the next level then they level up.
    double exp = NEEDED_EXPERIENCE;
    for(int i = 0; i < this->heroes.at(0)->get_level(); i++)
    {
        exp *= 2.0;
    }
    if(this->heroes.at(0)->get_experience() >= exp){
        for(unsigned int i = 0; i < this->heroes.size(); i++)
        {
            this->heroes.at(i)->level_up();
        }
        for(unsigned int i = 0; i < this->monsters.size(); i++)
        {
            this->monsters.at(i)->level_up();
        }
    }
}


//Assisting functions.
bool Square::buy( Hero* hero)
{
    return true;
}

vector<Hero*> Square::get_heroes()
{
    return heroes;
}

//Market functions..
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

bool Market::buy(Hero* hero){
    cout<<"What would you like to buy?"<<endl;
    cout<<"Press 1 for Items"<<endl;
    cout<<"Press 2 for Spells"<<endl;
    int a;
    cin>>a;

    while(a != 1 && a != 2){
        cout<< RED << "Invalid number, try again!" << RESET <<endl;
        cin>>a;
    }
    //Checking if they buy a weapon.
    bool back = false;

    //If the player wants to buy an item.
    if(a == 1){

        cout<< BOLDBLACK <<"The items available in the market are:" << RESET << endl;
        for(unsigned int i = 0; i < this->items.size(); i++)
        {
            cout<<i+1<<") ";
            this->items.at(i)->print();
        }

        cout<< endl << BOLDBLUE << "Press the number of the item you would like to purchase" << RESET <<endl;
        unsigned int a1;
        cin>>a1;

        //The player can't buy an item he has not the needed level to use.
        while(a1 > this->items.size() || a1 <= 0 || this->items.at(a1-1)->get_level() > hero->get_level())
        {
            if(this->items.at(a1-1)->get_level() > hero->get_level())
                cout << RED << "You must choose an item you have the needed level to buy, try again!"<< RESET << endl;
            else
                cout << RED << "Invalid number, try again!" << RESET << endl;
            cin>>a1;
        }

        //Checking if the hero has enough money to buy the item they want.
        Item* item = this->items.at(a1-1);
        if( item->get_price() <= hero->get_money())
        {
            if( (item->get_kind_of_item()).compare("Weapon") == 0)
            {
                back = true;
            }

            hero->sub_money( item->get_price());
            hero->buy_Item(item);
        }
        else
        {
            cout << RED << "You don't have enough money for this Item!" << RESET << endl;
        }
        
    }
    //I the player wants to but a spell.
    else
    {
        cout << BOLDBLACK << "The spells available in the market are:" << RESET <<endl;
        for(unsigned int i = 0; i < this->spells.size(); i++){
            cout<<i+1<<") ";
            this->spells.at(i)->print();
        }
        cout<< endl << BOLDBLUE<<"Press the number of the spell you would like to purchase" << RESET << endl;
        unsigned int a1;
        cin>>a1;

        while(a1 > this->spells.size() || a1 <= 0 || this->spells.at(a1-1)->get_level() > hero->get_level())
        {
            if(this->spells.at(a1-1)->get_level() > hero->get_level())
                cout << RED << "You must choose an item you have the needed level to buy, try again!"<<endl;
            else
                cout << RED << "Invalid number, try again!" << RESET << endl;
            cin>>a1;
        }
        Spell* spell = this->spells.at(a1-1);

        if( spell->get_price() <= hero->get_money())
        {
            hero->sub_money( spell->get_price());
            hero->buy_Spell(spell);
        }
        else
        {
            cout << RED << "You don't have enough money for this Spell!" << RESET << endl;
        }
    }
    //Returns whether the hero bought a weapon or not.
    return back;
}

void Market::sell(Hero* hero){

    cout<<"What would you like to sell?"<<endl;
    cout<<"Press 1 for Items"<<endl;
    cout<<"Press 2 for Spells"<<endl;
    int a;
    cin>>a;
    //If the player wants to sell an item.
    if(a == 1){
        unsigned int number = hero->print_item();
        if( number == 0)
            return;

        cout << endl << BOLDBLACK << "Press the number of the item you would like to sell" << RESET <<endl;
        
        unsigned int a1;
        cin>>a1;
        while(a1 <= 0 || a1> number){
            cout << RED << "Invalid number, try again!" << RESET << endl;
            cin>>a1;
        }
        hero->sell_Item(a1-1);
    }
    //If the player wants to sell a spell.
    else
    {
        unsigned int number = hero->print_spell();
        if( number == 0)
            return;

        cout<< endl << BOLDBLACK << "Press the number of the spell you would like to sell" << RESET <<endl;
        
        unsigned int a1;
        cin>>a1;

        while(a1 <= 0 || a1 > number){
            cout << RED << "Invalid number, try again!" << RESET << endl;
            cin>>a1;
        }
        hero->sell_Spell(a1-1);
    }
}

int Market::contains(){
    return Square::contains();
}

//Συναρτήσεις για Common.
int Common::contains(){
    return Square::contains();
}

//Συναρτήσεις για nonAccessible.
int nonAccessible::contains(){
    return Square::contains();
}


////////////////////////////////////////////////////////////////////////////////////////////
//                                                                                        //  
//                                                                                        //
//                                      END                                               //
//                                                                                        //
//                                                                                        // 
////////////////////////////////////////////////////////////////////////////////////////////