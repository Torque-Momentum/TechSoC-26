// //Things pending:
// Random selection of benders in case of equal speed;
// Probability thing for calc of critical multiplier
// No. of critical hits and No. of super effective hits (around line 175)



#include <iostream>
#include <vector>
#include <utility> //required for the pair function for storage of attack + move_power
#include <random> //required for the random + probabilistic things in the program.
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

    int type_counter = 0;
    int critical_counter = 0;
    double base_damage, final_damage;
    double type_multiplier = 0;
    double critical_multiplier = 0;
    void attacker(Bender& n, int idx) {
        if (idx >= 0 && idx < moves.size()) {
            cout << name << " used " << moves.at(idx).first << "!"<< endl;
            base_damage = attack * moves.at(idx).second/n.defense;
            
            if ((element == "Fire" && n.element == "Water") ||
                (element == "Water" && n.element == "Earth") ||
                (element == "Earth" && n.element == "Air") ||
                (element == "Air" && n.element == "Fire")) {
                    type_multiplier = 0.5;
                }
            else if ((element == "Water" && n.element == "Fire") ||
                (element == "Earth" && n.element == "Water") ||
                (element == "Air" && n.element == "Earth") ||
                (element == "Fire" && n.element == "Air")) {
                    type_multiplier = 2.0;
                }
            else { type_multiplier = 1.0;}

            if (type_multiplier == 2.0) {
                cout << "Super Effective!" << endl;
                type_counter++;
            }
            else if (type_multiplier == 0.5) {
                cout << "It is not very effective!" << endl;
            }

       
           
            double critical_chance = 0.1;
            std::random_device rd;
            std::mt19937 Prob(rd());
            std::uniform_int_distribution<int> fav_case(1,100);
            if (fav_case(Prob) <=  critical_chance * 100) {critical_multiplier = 2.0;}
            else {critical_multiplier = 1.0;}
            if (critical_multiplier == 2.0) {
                cout << "It's a critical hit!" << endl;
                critical_counter++;
            }
            

            final_damage = base_damage * type_multiplier * critical_multiplier;
            cout << n.name << " took " << final_damage << " damage!" << endl;
            n.hp -= final_damage;
            if (n.hp < 0) {n.hp = 0;}
            cout << n.name << " HP: " << n.hp << "/" << n.HP << endl;
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
    //new constructor for variable objects (x,y)
    Bender() {
        name = "";
        element = "";
        this->hp = 0;
        attack = 0;
        defense = 0;
        speed = 0;
    }


};
class Duel : public Bender {
    public:
    Bender b1;
    Bender b2;
    Duel (Bender b1, Bender b2) {
        this->b1 = b1;
        this->b2 = b2;
    }
    Bender* first;
    Bender* second;
    
    
    void start_duel() {
        cout<< "\n";cout<< "\n";cout<< "\n";
        cout << "=== DUEL BEGINS! ===" << endl;
        cout<< "\n";
        cout << b1.name << " " << "(" << b1.element << ", " << "HP:" << b1.hp << "/" << b1.HP << ") ";
        cout << "VS ";
        cout << b2.name << " " << "(" << b2.element << ", " << "HP:" << b2.hp << "/" << b2.HP << ") " << endl;
        cout<< "\n";cout<< "\n";cout<< "\n";
        int i = 1;
       do {
            if (b1.speed > b2.speed) {
                first = &b1;
                second = &b2;
            }
            else if (b1.speed < b2.speed) {
                first = &b1;
                second = &b1;
            }
            else {
                std::random_device rd;
                std::mt19937 assign(rd());
                std::uniform_int_distribution<int> choice(0,1);
                int h = choice(assign);
                if (h == 0) {
                    first = &b1;
                    second = &b2;
                }
                else if (h == 1) {
                    first = &b2;
                    second = &b1;
                }


            }
            cout << "Turn " << i << ": ";
            cout << first->name << " goes first!" << endl;
            cout<< "\n";
            cout << "Choose your attack : \n";
            first->showAttacks();
            cout<< "\n";
            int q;
            cin>> q;
            cout<< "\n";
            first->attacker(*second,q-1);
            cout<< "\n";
            i++;

            if (second->hp == 0) {break;}
            cout << "Turn " << i << ": ";
            cout << second->name << " strikes back!" << endl;
            cout<< "\n";
            cout << "Choose your attack : \n";
            second->showAttacks();
            cout<< "\n";
            int w;
            cin>> w;
            cout<< "\n";
            second->attacker(*first,w-1);
            cout << "\n";
            i++;

        }  while(!((first->hp == 0 || second->hp == 0))) ;


        if (first->hp == 0) {
            cout << first->name << " fainted!" << endl;
            cout << second->name << " wins the duel!" << endl;
            cout << "\n" ;
            cout << "Duel Summary:" << endl;
            cout << "-Winner: "<< second->name << endl;
            cout << "-Turns:  "<< i-1 << endl;
            cout << "-Critical Hits: "<< first->critical_counter + second->critical_counter << endl;
            cout << "-Super Effective Hits: "<< first->type_counter + second->type_counter << endl;
        }
        else if (second->hp == 0) {
            cout << second->name << " fainted!" << endl;
            cout << first->name << " wins the duel!" << endl;
            cout << "\n" ;
            cout << "Duel Summary:" << endl;
            cout << "-Winner: "<< first->name << endl;
            cout << "-Turns:  "<< i-1 << endl;
            cout << "-Critical Hits: "<< first->critical_counter + second->critical_counter  << endl;
            cout << "-Super Effective Hits: "<< first->type_counter + second->type_counter << endl;
        }

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

Bender x;
cout << "\n";
cout << "Choose your Characters: \n";
cout << "Kael (Fire) \n";
cout << "Mira (Water) \n";
cout << "Terra (Earth) \n";
cout << "Zephyr (Air) \n";
cout << "\n";
cout<< "Player 1: " ; 
string h;
cin>> h;
if (h == "Kael") {x = Kael;}
else if (h == "Mira") {x = Mira;}
else if (h == "Terra") {x = Terra;}
else if (h == "Zephyr") {x = Zephyr;}
else if (h == "Nadia") {x = Nadia;}
else if (h == "Talon") {x = Talon;}
else {return 0;}
cout<< "\n";

Bender y;
cout<< "Player 2: ";
string g;
cin>> g;
if (g == "Kael") {y = Kael;}
else if (g == "Mira") {y = Mira;}
else if (g == "Terra") {y = Terra;}
else if (g == "Zephyr") {y = Zephyr;}
else if (h == "Nadia") {y = Nadia;}
else if (h == "Talon") {y = Talon;}
else {return 0;}


Duel duel(x,y);
duel.start_duel();


}

