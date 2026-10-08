#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class Bender {
public:
    string name;
    string element;
    int hp;
    int attack;
    int defense;
    int speed;
    int HP;
    std::vector<std::pair<std::string,int>> moves;
    //this is for constructor
    Bender(string n, string el, int hp, int atk, int def, int spd,std::vector<std::pair<std::string,int>> moves){
        name = n;
        element = el;
        this->hp = hp;
        attack = atk;
        defense = def;
        speed = spd;
        this->moves = moves;
        HP = hp;
    }
    //stat display function
    void display_stats() {
        cout << name << " " << "(" << element << ")" << " - ";
        if (hp < 0) {  cout << "HP:" << " " << 0 << "/" << HP << ", ";}
        else { cout << "HP:" << " " << hp << "/" << HP << ", ";}
        cout << "Attack:" << " " << attack << ", ";
        cout << "Defense:" << " " << defense << ", ";
        cout << "Speed:" << " " << speed << endl;
        cout << "Moves: ";
        cout << moves.at(0).first << "(" << moves.at(0).second << ") , ";
        cout << moves.at(1).first << "(" << moves.at(1).second << ") , ";
        cout << moves.at(2).first << "(" << moves.at(2).second << ") , ";
        cout << moves.at(3).first << "(" << moves.at(3).second << ")" << endl;


    }
    //attack function
    void attacker(Bender& n, int idx) {
        if (idx >= 0 && idx < moves.size()) {
            cout << name << " used " << moves.at(idx).first << "!"<< endl;
            int damage;
            damage = attack * moves.at(idx).second/n.defense;
            cout << n.name << " took " << damage << " damage!" << endl;
            n.hp -= damage;
        }
        
    }
    //check if fainted
    void is_fainted() {
        bool x;
        if (hp <= 0) {x = true;}
        else {x = false;}
        cout << std::boolalpha << x << endl;
    }
    //Display attacks
    void showAttacks() {
        for (int i = 0; i <= 3; i++) {
           cout << i+1 << "." << moves.at(i).first <<"\n";
        }
    }
    //new class for variable objects
    Bender() {
        name = "";
        element = "";
        this->hp = 0;
        attack = 0;
        defense = 0;
        speed = 0;
    }


};

int main() {
//Create Kael
Bender Kael("Kael", "Fire", 100, 58, 38, 88,
    {{"Ember Slash", 40}, {"Quick Jab", 30}, {"Focus", 0}, {"Flame Surge", 70}});

//Create Mira
Bender Mira("Mira", "Water", 92, 50, 45, 60,
     {{"Water Whip", 35}, {"Tide Push", 25}, {"Mist Veil", 0}, {"Tidal Wave", 60}});

//Create Terra
Bender Terra("Terra", "Earth", 105, 52, 48, 72,
     {{"Rock Throw", 35}, {"Stone Wall", 25}, {"Grounding", 0}, {"Earthquake", 65}});

//Create Zephyr
Bender Zephyr("Zephyr", "Air", 90, 62, 35, 92,
      {{"Gust", 35}, {"Air Dash", 25}, {"Meditate", 0}, {"Cyclone", 65}});
//Create Nadia
Bender Nadia("Nadia", "Water", 85, 48, 60, 72,
              {{"Wave Crash", 35}, {"Splash Kick", 25}, {"Guard", 0}, {"Riptide", 50}});
//Create Talon
Bender Talon("Talon", "Air", 90, 52, 55, 72,
              {{"Gale Strike", 38}, {"Wind Cutter", 28}, {"Updraft", 0}, {"Cyclone Blast", 48}});

//variable objects for operations
Bender x;
Bender y;
int z;

cout << "Choose your Characters: \n";
cout << "Kael (Fire) \n";
cout << "Mira (Water) \n";
cout << "Terra (Earth) \n";
cout << "Zephyr (Air) \n";
cout << "\n";
cout << "Attacker : " ;

string h;
cin>> h;
if (h == "Kael") {x = Kael;}
else if (h == "Mira") {x = Mira;}
else if (h == "Terra") {x = Terra;}
else if (h == "Zephyr") {x = Zephyr;}
else {return 0;}

cout << "\n";
cout << "Defender : " ;

string g;
cin>> g;
if (g == "Kael") {y = Kael;}
else if (g == "Mira") {y = Mira;}
else if (g == "Terra") {y = Terra;}
else if (g == "Zephyr") {y = Zephyr;}
else {return 0;}

cout << "\n";
cout << "Choose your attack : \n";
x.showAttacks();
cout<< "\n";
int q;
cin>> q;
cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";cout<< "\n";

x.display_stats();
cout<< "\n";
y.display_stats();


cout<< "\n";
cout<< "\n";

x.attacker(y,q-1);
cout<< "\n";
y.display_stats();
cout<< "\n";
cout << y.name << " fainted : ";
y.is_fainted();


}

