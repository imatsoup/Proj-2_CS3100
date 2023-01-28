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
    int getHP()
    {
        return hitPoints;
    }
    void setHP(int dmg)
    {
        hitPoints = (hitPoints - dmg);
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
    void attack(Character defender)
    {  
        int attack = ((rand() % 19) + 1) + attackBonus;
        if(attack >= defender.getAC())
        {
            int damage = ((rand() % 9) + 1) + damageBonus;
            defender.setHP(damage);
            // cout << name << " strikes " << defender.getName() << " for " << damage << "damage!" << endl;
        }
        else{
            // cout << name << " misses " << defender.getName() << "!" << endl;
        }

    }

};
