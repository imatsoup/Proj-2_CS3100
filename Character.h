#include <string>

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
};