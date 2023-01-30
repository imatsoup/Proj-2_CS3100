#include <string>
#include <time.h>
#include <iostream>
using namespace std;

class Character
{
    private:
        string name;
        string role;
        int hitPoints;
        int attackBonus;
        int damageBonus;
        int armorClass;

    public:
        Character(string name, string role, int hitPoints, int attackBonus, int damageBonus, int armorClass);
    //need Print() overloaded function (returns Character variables)
        
        int getHealth()
        {
            return hitPoints;
        }
        void setHP(int hp, int dmg)
        {
            hitPoints = (hp - dmg);
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
        void attack(Character& defender)
        {  
            int attack = ((rand() % 19) + 1) + attackBonus;
            if(attack >= defender.getAC())
            {
                int dmgCalc = damage(damageBonus);
                defender.setHP(defender.getHealth(), dmgCalc);
                cout << name << " strikes " << defender.getName() << " for " << dmgCalc << " damage!" << " Attack roll= " <<  (attack - getAtkBonus()) << " + " << getAtkBonus() 
                << ". Damage roll= " << (dmgCalc - getDmgBonus()) << " + " << getDmgBonus() << "."<< endl;
                cout << defender.getName() << " has " << defender.getHealth() << " hit points remaining!" << endl;
            }
            else{
                cout << name << " misses " << defender.getName() << "!" << endl;
            }

        }
        int damage(int dmgBonus)
        {
            return ((rand() % 9) + 1) + dmgBonus;
        }

};
