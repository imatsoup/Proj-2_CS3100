#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Character.h"
using namespace std;

int combat(Character player, Character enemy)
    {
        while(player.getHP() > 1 && enemy.getHP() > 1)
        {
            int turnOrder = rand() % 1;
            if(turnOrder < 1)
            {
                player.attack(enemy);
                enemy.attack(player);
            }
            else
            {
                enemy.attack(player); 
                player.attack(enemy);
            }
            cout << player.getHP() << endl;
            cout << enemy.getHP() << endl;
        }
        if(player.getHP() < 1)
        {
            cout << player.getName() << " has perished!" << endl;
        }
        else
        {
            cout << enemy.getName() << " has been vanquished!" << endl;
        }
    return 0;
    }

int main()
{
    //getting that random seed going
    srand(time(nullptr));
    //Test fighters
    Character garretT = Character("Garret Thornsberry", "rogue", 20, 4, 2, 7);
    Character eVorlan = Character("Ekrin Vorlan", "wizard", 20, 6, 5, 3);
    // Character sirRB = Character("Reginald Bearington", "warrior", 15, 2, 1, 6);
    // Character emilaS = Character("Emila Stuthengard", "paladin", 25, 1, 1, 0);
    return combat(garretT, eVorlan);

}

