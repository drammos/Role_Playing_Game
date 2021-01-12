#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include "Grid.h"

//Συναρτήσεις για Grid.
Grid::Grid(int x, int y){
    this->x = x;
    this->y = y;

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
            if(r == 1)
                this->squares[i][j] = new nonAccessible();
            else if(r == 3 || r == 7)
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

//βαζω τους ηρωες σε ενα τυχαιο market τετραγωνο
void Grid::set_heroes( Hero* hero)
{   
    
    if( x_heroes == -1)
    {
        srand( time(NULL));
        bool in = false;
        while( in != true)
        {
            x_heroes = rand()%(x+1);
            y_heroes = rand()&(y+1);
            if( (squares[x_heroes][y_heroes]->get_kind_of_square()).compare( "Market") == 0)
            {
                in = true;
            }
        }
    }

    hero->set_x( x_heroes);
    hero->set_y( y_heroes);
    squares[x_heroes][y_heroes]->add_hero( hero);
}

void Grid::set_monsters( Monster* monster)
{
    srand(time(NULL));
    bool in = false;
    int x1;
    int y1;
    while( in != true)
    {
        x1 = rand()%(x+1);
        y1 = rand()&(y+1);
        if( (squares[x1][y1]->get_kind_of_square()).compare( "Common") == 0)
        {
            in = true;
            squares[x1][y1]->add_monster( monster);
        }   
    }
}


void Grid::StartGame()
{
    
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
        cout << RED << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << RESET << endl;
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
                cout << RED << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << RESET << endl;
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
                cout << RED << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << RESET << endl;
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
            cout << RED << "Δεν ηταν εγκυρη η επιλογη σας! Προσπαθηστε ξανα." << RESET << endl;
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
                cout << YELLOW << " S " << RESET;
            }
            else if( squares[i][j]->get_kind_of_square() == "nonAccessible")
            {
                cout << RED << " X " << RESET;
            }
            else
            {   
                int k = squares[i][j]->contains();
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


void Grid::quitGame()
{
    cout << BOLDRED << "YOU LOSE!" << endl;
    exit(EXIT_FAILURE);
}

void Grid::move(Hero* hero){
    cout<<"Where do you want to go?"<<endl;
    cout<<"Press 1 for up."<<endl;
    cout<<"Press 2 for down."<<endl;
    cout<<"Press 3 for left."<<endl;
    cout<<"Press 4 for right."<<endl;
    int answer;
    cin>>answer;
    while(answer < 1 || answer > 4){
        cout << RED << "Invalid number, try again!" << RESET << endl;
        cin >> answer;
    }
    if(answer == 1){
        if(squares[hero->get_x() - 1][hero->get_y()]->get_kind_of_square().compare("nonAccessible") == 0){
            cout<<"This is a nonAccessible square!"<<endl;
        }
        else{
            vector <Hero*> vec = squares[hero->get_x()][hero->get_y()]->remove_heroes();
            for(int i = 0; i < vec.size(); i++){
                squares[hero->get_x() - 1][hero->get_y()]->add_hero(vec.at(i));
            }
        }
    }
    else if(answer == 2){
        if(squares[hero->get_x() + 1][hero->get_y()]->get_kind_of_square().compare("nonAccessible") == 0){
            cout<<"This is a nonAccessible square!"<<endl;
        }
        else{
            vector <Hero*> vec = squares[hero->get_x()][hero->get_y()]->remove_heroes();
            for(int i = 0; i < vec.size(); i++){
                squares[hero->get_x() + 1][hero->get_y()]->add_hero(vec.at(i));
            }
        }
    }
    else if(answer == 3){
        if(squares[hero->get_x()][hero->get_y() - 1]->get_kind_of_square().compare("nonAccessible") == 0){
            cout<<"This is a nonAccessible square!"<<endl;
        }
        else{
            vector <Hero*> vec = squares[hero->get_x()][hero->get_y()]->remove_heroes();
            for(int i = 0; i < vec.size(); i++){
                squares[hero->get_x()][hero->get_y() - 1]->add_hero(vec.at(i));
            }
        }
    }
    else{
        if(squares[hero->get_x()][hero->get_y() + 1]->get_kind_of_square().compare("nonAccessible") == 0){
            cout<<"This is a nonAccessible square!"<<endl;
        }
        else{
            vector <Hero*> vec = squares[hero->get_x()][hero->get_y()]->remove_heroes();
            for(int i = 0; i < vec.size(); i++){
                squares[hero->get_x()][hero->get_y() + 1]->add_hero(vec.at(i));
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

void Square::add_hero(Hero* h){
    this->heroes.push_back(h);
}

void Square::add_monster(Monster* m){
    this->monsters.push_back(m);
}

vector <Hero*> Square::remove_heroes(){
    vector <Hero*> vec;
    for(int i = 0; i < this->heroes.size(); i++){
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
    int h = 0;
    for(int i = 0; i < this->heroes.size(); i++){
        if(this->heroes.at(i)->get_healthPower() != 0.0)
            h++;
    }
    int m = 0;
    for(int i = 0; i < this->monsters.size(); i++){
        if(this->monsters.at(i)->get_healthPower() != 0.0)
            m++;
    }
    if(m && h)
        return 0;
    else if(m > 0)
        return 1;
    else
        return 2;
}

void Square::War(){   

    if(this->monsters.size() == 0)return;
    int r = rand()%3;
    if(r)return;

    cout<<"You are on a war with "<<this->monsters.size()<<" monsters"<<endl;
    if(this->heroes.at(0)->get_level() > this->monsters.at(0)->get_level()){
        for(int i = 0; i < this->monsters.size(); i++){
            this->monsters.at(i)->level_up();
        }
    }
    while(this->alive() == 0){
        for(int i = 0; i < this->heroes.size(); i++){
            if(this->heroes.at(i)->get_healthPower() == 0.0)
                continue;
            cout << "How do you want to attack your oponents?" << endl; 
            cout << "Press 1 for Attack" << endl;
            cout << "Press 2 for CastSpell" << endl;
            cout << "Press 3 for Potion" << endl;

            int w;
            cin >> w;
            while( w <=0 || w > 3){
                cout << RED << "Invalid number, try again!" << RESET << endl;
                cin >> w;
            }
            if( w == 3){
                int p = this->heroes.at(i)->print_Potion();
                if(p == 0){
                    cout<<"Select another way of attack"<<endl;
                    cin>>w;
                    while(w != 1 && w != 2){
                        cout<<"Invalid number, try again!"<<endl;
                        cin>>w;
                    }
                    Monster* monster;
                    cout << "Which monster do you want to fight against?" << endl;
                    for(int i = 0; i < this->monsters.size(); i++){
                        if(this->monsters.at(i)->get_healthPower() > 0){
                            cout<<i+1<<")";
                            this->monsters.at(i)->print_monster();
                            cout<<endl;
                        }
                    }
                    cout<<"Press the number of the monster you want to fight against"<<endl;
                    int a1;
                    cin>>a1;
                    while(a1 <= 0 || a1 > this->monsters.size()){
                        cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                        cin>>a1;
                    }
                    while(this->monsters.at(a1-1)->get_healthPower() <= 0){
                        cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                        cin>>a1;
                    }
                    if(w == 1){
                        this->heroes.at(i)->attack(this->monsters.at(a1-1));
                    }
                    else{
                        bool f = this->heroes.at(i)->castSpell(this->monsters.at(a1-1));
                        if(f == false){
                            cout<<"The only way to attack is by a simple attack"<<endl;
                            this->heroes.at(i)->attack(this->monsters.at(a1-1));
                        }
                    }
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
            else{   
                Monster* monster;
                cout << "Which monster do you want to fight against?" << endl;
                for(int i = 0; i < this->monsters.size(); i++){
                    if(this->monsters.at(i)->get_healthPower() > 0){
                        cout<<i+1<<")";
                        this->monsters.at(i)->print_monster();
                        cout<<endl;
                    }
                }
                cout<<"Press the number of the monster you want to fight against"<<endl;
                int a1;
                cin>>a1;
                while(a1 <= 0 || a1 > this->monsters.size()){
                    cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                    cin>>a1;
                }
                while(this->monsters.at(a1-1)->get_healthPower() <= 0){
                    cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                    cin>>a1;
                }
                if(w == 1){
                    this->heroes.at(i)->attack(this->monsters.at(a1-1));
                }
                else{
                    bool f = this->heroes.at(i)->castSpell(this->monsters.at(a1-1));
                    if(f == false){
                        cout<<"Select another way of attack"<<endl;
                        cin>>w;
                        while(w != 1 && w != 3){
                            cout<<RED<<"Invalid number, try again!"<<RESET<<endl;
                            cin>>w;
                        }
                        if(w == 1){
                            this->heroes.at(i)->attack(this->monsters.at(a1-1));
                        }
                        else{
                            int p = this->heroes.at(i)->print_Potion();
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
        for(int i = 0;  i < this->monsters.size(); i++){
            if(this->monsters.at(i)->get_healthPower() == 0.0)
                continue;
            int j = 0;
            while(this->heroes.at(j)->get_healthPower() == 0.0){
                j++;
            }
            this->monsters.at(i)->attack(this->heroes.at(j));
            this->monsters.at(i)->reset_fields();
        }
        for(int i = 0; i < this->heroes.size(); i++){
            if(this->heroes.at(i)->get_healthPower() != 0.0){
                this->heroes.at(i)->add_healthPower(0.1 * this->heroes.at(i)->get_healthPower());
                this->heroes.at(i)->add_magicPower(0.1 * this->heroes.at(i)->get_magicPower());
            }
        }
        for(int i = 0; i < this->monsters.size(); i++){
            if(this->monsters.at(i)->get_healthPower() != 0.0)
                this->monsters.at(i)->add_healthPower(0.1 * this->heroes.at(i)->get_healthPower());
        }
        cout<<"Do you want to view Statistics?"<<endl;
        cout<<"Yes or No"<<endl;
        string answer;
        cin>>answer;
        while(answer.compare("Yes") && answer.compare("No")){
            cout<<"Invalid answer, try again!"<<endl;
            cin>>answer;
        }
        if(answer.compare("Yes") == 0){
            for(int i = 0; i < this->heroes.size(); i++){
                this->heroes.at(i)->displayStats();
            }
            for(int i = 0; i < this->monsters.size(); i++){
                this->monsters.at(i)->displayStats();
            }
        }
    }
    if(this->alive() == 1){
        cout<<"You lost the war"<<endl;
        for(int i = 0; i < this->heroes.size(); i++){
            this->heroes.at(i)->set_money(this->heroes.at(i)->get_money() / 2.0);
        }
    }
    else{
        cout<<"You won the war. Congratulations!"<<endl;
        for(int i = 0; i < this->heroes.size(); i++){
            this->heroes.at(i)->add_experience((this->heroes.at(i)->get_level() + EXPERIENCE) * this->monsters.size());
            this->heroes.at(i)->add_money((this->heroes.at(i)->get_level() + MONEY) * this->monsters.size());
        }
    }
    for(int i = 0; i < this->monsters.size(); i++){
        this->monsters.at(i)->set_rounds(1);
        this->monsters.at(i)->reset_fields();
        if(this->monsters.at(i)->get_healthPower() == 0.0)
            this->monsters.at(i)->set_healthPower(HEALTH_POWER/2.0);
    }
    for(int i = 0; i < this->heroes.size(); i++){
        if(this->heroes.at(i)->get_healthPower() == 0.0)
            this->heroes.at(i)->set_healthPower(HEALTH_POWER/2.0);
    }
    double exp = NEEDED_EXPERIENCE;
    for(int i = 0; i < this->heroes.at(0)->get_level(); i++){
        exp *= 2.0;
    }
    if(this->heroes.at(0)->get_experience() >= exp){
        for(int i = 0; i < this->heroes.size(); i++){
            this->heroes.at(i)->level_up();
        }
        for(int i = 0; i < this->monsters.size(); i++){
            this->monsters.at(i)->level_up();
        }
    }
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
            cout << RED << "Invalid number, try again!" << RESET << endl;
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
            cout << RED << "Invalid number, try again!" << RESET << endl;
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
            cout << RED << "Invalid number, try again!" << RESET << endl;
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
