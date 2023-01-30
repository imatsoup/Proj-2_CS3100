#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Character.h"
using namespace std;

void combat(Character player, Character enemy)
    {
        while(player.getHealth() > 1 && enemy.getHealth() > 1)
        {
            int turnOrder = rand() % 1;
            if(turnOrder < 1)
            {
                player.attack(enemy);
                
                if(enemy.getHealth() != 0)
                {
                    enemy.attack(player);
                }
            }
            else
            {
                enemy.attack(player);

                if(player.getHealth() != 0)
                { 
                    player.attack(enemy);
                }
            }
        }
        if(player.getHealth() < 1)
        {
            cout << player.getName() << " has perished!" << endl;
        }
        else
        {
            cout << enemy.getName() << " has been vanquished!" << endl;
        }
    }

int main()
{
    string plyrName = "";
    string plyrRole = "";
    int plyrHealth = 0;
    int plyrAtkBonus = 0;
    int plyrDmgBonus = 0;
    int plyrAC = 0;
    cout << "What is your character's name?" << endl;
    cin >> plyrName;
    cout << "What is your character's role?" << endl;
    cin >> plyrRole;
    cout << "What is your character's Health Total?" << endl;
    cin >> plyrHealth;
    cout << "What is your character's Attack Bonus?" << endl;
    cin >> plyrAtkBonus;
    cout << "What is your character's Damage Bonus?" << endl;
    cin >> plyrDmgBonus;
    cout << "What is your character's Armor Class?" << endl;
    cin >> plyrAC;
    Character playerChar = Character(plyrName, plyrRole, plyrHealth, plyrAtkBonus, plyrDmgBonus, plyrAC);
    //getting that random seed going
    srand(time(nullptr));
    //Test fighters
    Character garretT = Character("Garret Thornsberry", "rogue", 20, 4, 2, 7);
    Character eVorlan = Character("Ekrin Vorlan", "wizard", 20, 6, 5, 3);
    Character sirRB = Character("Reginald Bearington", "warrior", 15, 2, 1, 6);
    Character emilaS = Character("Emila Stuthengard", "paladin", 25, 1, 1, 0);
    Character opponentList[] = {garretT, eVorlan, sirRB, emilaS};
    int opponentSelect = rand() % 3;
    switch(opponentSelect){
        case 0:
            combat(playerChar, eVorlan);
            break;
        case 1:
            combat(playerChar, eVorlan);
            break;
        case 2:
            combat(playerChar, sirRB);
            break;
        case 3:
            combat(playerChar, emilaS);
            break;
    }

    
    return 0;
}

