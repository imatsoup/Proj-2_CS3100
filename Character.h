#include <string>
#include <time.h>
#include <iostream>
using namespace std;
//class file for the Character class
class Character
{
    //Instantiate private variables for character class
    private:
        string name;
        string role;
        int hitPoints;
        int attackBonus;
        int damageBonus;
        int armorClass;

    public:
    //Constructor for character class
        Character(string name, string role, int hitPoints, int attackBonus, int damageBonus, int armorClass);
    //Getter/Setter functions
        int getHealth()
        {
            return hitPoints;
        }
        //Used in the attack function to modify the hitpoints of characters based on the attack result
        void setHP(int hp, int dmg)
        {
            hitPoints = (hp - dmg);
            //Keeps the hitpoints from being negative
            if(hitPoints < 0){
                hitPoints = 0;
            }
        }
        int getAtkBonus(){
            return attackBonus;
        }
        int getDmgBonus(){
            return damageBonus;
        }
        int getAC()
        {
            return armorClass;
        }
        string getName()
        {
            return name;
        }
        string getRole()
        {
            return role;
        }
        //Has to call &defender to modify the values properly  
        void attack(Character& defender)
        {  
            cout << name << " attacks!" << endl;
            int attack = ((rand() % 20) + 1) + attackBonus;
            if(attack >= defender.getAC())
            {
                cout << "Attack roll: " << attack - getAtkBonus() << " + " << getAtkBonus() << " = " << attack << " --> HIT!" << endl;
                int dmgCalc = damage(damageBonus);
                defender.setHP(defender.getHealth(), dmgCalc);
                cout << name << " strikes " << defender.getName() << " for " << dmgCalc << " damage!" << " Damage roll: " << (dmgCalc - getDmgBonus()) << " + " << getDmgBonus() << "."<< endl;
                cout << defender.getName() << " has " << defender.getHealth() << " hit points remaining!" << endl;
                cout << endl;
            }
            else{
                cout << "Attack roll: " << attack - getAtkBonus() << " + " << getAtkBonus() << " = " << attack << " --> MISS!" << endl;
                cout << endl;
            }

        }
        int damage(int dmgBonus)
        {
            return ((rand() % 10) + 1) + dmgBonus;
        }
        //Prints the entire character and their relevant stats to the console
        void print (ostream& os)
        {
           os << "Character Summary" << endl;
           os << "-----------------" << endl;
           os  << name << " the " << role << endl;
           os  << "HP: " << hitPoints << endl;
           os  << "AB: " << attackBonus << endl;
           os << "DB: " << damageBonus << endl;
           os << "ACL: " << armorClass << endl;
           os << endl;
        }

};
