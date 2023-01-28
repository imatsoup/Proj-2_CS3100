#include "Character.h"

Character::Character(string newName, string newRole, int hp, int atkBons, int dmgBons, int ac)
{
    name = newName;
    role = newRole;
    hitPoints = hp;
    attackBonus = atkBons;
    damageBonus = dmgBons;
    armorClass = ac;

}
