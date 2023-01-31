#include <stdio.h>
#include <time.h>
#include <iostream>
#include "Character.h"
using namespace std;

//CS-3100-02, John McGuff, Project-2 
//This is a program that simulates an rpg battle between two characters created by the user.

//Function that creates the character
Character characterCreate(){
//instantiate necessary variables to avoid making the computer upset
    string plyrName = "";
    string plyrRole = "";
    int plyrHealth = 0;
    int plyrAtkBonus = 0;
    int plyrDmgBonus = 0;
    int plyrAC = 0;
    cout << "What is your character's name?" << endl;
    //Prompt for, and store the input for all the character information
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
    //Return the character that was made
    return Character(plyrName, plyrRole, plyrHealth, plyrAtkBonus, plyrDmgBonus, plyrAC);
}
void combat(Character player, Character enemy)
    {
        while(player.getHealth() != 0 && enemy.getHealth() != 0)
        {
            int turnOrder = rand() % 2;
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
    //Instatiate, then print both characters to the console
    Character playerChar = characterCreate();
    playerChar.print(cout);
    Character enemyChar = characterCreate();
    enemyChar.print(cout);
    //getting that random seed going
    srand(time(nullptr));
    //Commence the battle
    cout << "Simulated combat:" << endl;
    combat(playerChar, enemyChar);
    return 0;
}

