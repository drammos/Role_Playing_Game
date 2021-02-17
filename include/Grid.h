#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include "Item.h"
#include "Spell.h"
#include "Living_Being.h"
#include "information.h"

using namespace std;


class Square;

//Πλέγμα
class Grid{

    //Διαστασεις πλεγματος
    int x;
    int y;
    //Δισδυάστατος πίνακας των τετραγώνων του πλέγματος.
    Square*** squares;

    //Συντεταγμένες του τετραγώνου που βρίσκονται οι ήρωες.
    int x_heroes;
    int y_heroes;

    //Εμφάνιση των αντικειμένων που έχει ένας ήρωας υπό την κατοχή του.
    void checkInventory( Hero*);
    //Αλλαγή της πανοπλίας ή του όπλου που χρησιμοποιεί ένας ήρωας τη δεδομένη χρονική στιγμή.
    void equip( Hero*);
    //Χρήση φίλτρου.
    void use( Hero*);
    //Εμφάνιση των στοιχείων του ήρωα.
    void print_Hero( Hero*)const;
    //Μετακίνηση σε ένα από τα πάνω, κάτω, δεξιά, αριστερά τετράγωνα του πλέγματος αν αυτά είναι διαθέσιμα.
    void move(vector <Hero*>);
    //Έξοδος από το παιχνίδι.
    void quitGame();
    //Εμφάνιση πλέγματος.
    void displayMap()const;
    //Βοηθητική συνάρτηση για αγορά, πώληση και εξοπλισμό.
    void buy_sell_and_equip( Hero*);
    
public:    
    Grid( int, int);
    ~Grid();
    //Βάζει τους ήρωες μέσα στο πλέγμα.
    void set_heroes( Hero*);
    //Βάζει τα τέρατα μέσα στο πλέγμα.
    void set_monsters( Monster*);
    //Υλοποίηση παιχνιδιού.
    void StartGame();
    //Εφοδιασμός της αγοράς με τα αντικείμενα προς πώληση.
    void provide(Item*);
    //Εφοδιασμός της αγοράς με τα ξόρκια προς πώληση.
    void provide(Spell*);
};

//Τετράγωνο.
class Square{
    //Είδος τετραγώνου (Market, nonAccesible or Common).
    string kind_of_square;
    //Ήρωες που υπάρχουν στο τετράγωνο.
    vector < Hero* > heroes;
    //Τέρατα που υπάρχουν στο τετράγωνο.
    vector < Monster* > monsters;
public:
    Square(string);
    virtual ~Square();
    //Προσθέτει ήρωες στο τετράγωνο.
    void add_hero(Hero*);
    //Προσθέτει τέρατα στο τετράγωνο.
    void add_monster(Monster*);
    //Αφαιρεί τους ήρωες από το τετράγωνο.
    vector<Hero*> remove_heroes();
    //Επιστρέφει το είδος του τετραγώνου.
    string get_kind_of_square() const;
    //Επιστρέφει έναν ακέραιο ανάλογα με τον αριθμό των ηρώων και των τεράτων στο τετράγωνο.
    virtual int contains();
    //Επιστρέφει έναν ακέραιο ανάλογα με τον αριθμό των ζωντανών ηρώων και των ζωντανών τεράτων στο τετράγωνο.
    int alive();
    //Μάχη.
    void War();
    
    //Αγορά.
    virtual bool buy( Hero*);
    //Πώληση.
    virtual void sell( Hero*);
    //Βοηθητικές.
    virtual void insert_item(Item*){};
    virtual void insert_spell(Spell*){};

    //Επιστρέφει τους ήρωες των τετραγώνων.
    vector<Hero*> get_heroes();
};

class nonAccessible:public Square{

public:
    nonAccessible():Square("nonAccessible"){};
    int contains();
};

class Market:public Square{
    vector <Item*> items;
    vector <Spell*> spells;
public:
    Market():Square("Market"){};
    ~Market();
    void insert_item(Item*);
    void insert_spell(Spell*);
    bool buy(Hero*);
    void sell(Hero*);
    int contains();
};

class Common:public Square{


public:
    Common():Square("Common"){};
    int contains();
};





#endif