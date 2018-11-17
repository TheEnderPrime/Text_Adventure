#ifndef MONSTERS_H_INCLUDED
#define MONSTERS_H_INCLUDED

#define MAX_NAME 21  
#include <iostream>
#include <string.h>

struct Monster
{
    char Name[MAX_NAME];                //REQUIREMENT 7
    int Health;
    int Mana;
    int Attack;
    int Defense;
    int Gold;
    int Exp;
//  int Armor;  FOR LATER
//
};

void DisplayMonsterStats(struct Monster Target)
{
    printf("\nName: %s\nHealth: %d\nMana: %d\nAttack: %d\nDefense: %d\n", Target.Name, Target.Health, Target.Mana, Target.Attack, Target.Defense);
}

void createGoblin(struct Monster *Goblin)
{
    strcpy(Goblin->Name, "Goblin");
    Goblin->Health = 25;
    Goblin->Mana = 5;
    Goblin->Attack = 10;
    Goblin->Defense = 10;
}

void createGhost(struct Monster *Ghost)
{
    strcpy(Ghost->Name, "Ghost");
    Ghost->Health = 5;
    Ghost->Mana = 10;
    Ghost->Attack = 30;
    Ghost->Defense = 30;
}

void createWitch(struct Monster *Witch)
{
    strcpy(Witch->Name, "Witch");
    Witch->Health = 30;
    Witch->Mana = 25;
    Witch->Attack = 15;
    Witch->Defense = 15;
}

void createOgre(struct Monster *Ogre)
{
    strcpy(Ogre->Name, "Ogre");
    Ogre->Health = 50;
    Ogre->Mana = 5;
    Ogre->Attack = 30;
    Ogre->Defense = 30;
}

void createDragon(struct Monster *Dragon)
{
    strcpy(Dragon->Name, "Dragon");
    Dragon->Health = 100;
    Dragon->Mana = 30;
    Dragon->Attack = 70;
    Dragon->Defense = 50;
}
#endif // CLASS_H_INCLUDED
