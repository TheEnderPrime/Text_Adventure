#ifndef QUEST_H_INCLUDED
#define QUEST_H_INCLUDED
#include "Class.h"
#include "Systems.h"
#include "Locations.h"

#define MAX_NAME 21

/*

THIS FILE IS USED TO CREATE THE FUNCTIONALITY OF QUESTS 
INSTEAD OF CREATING THEM WITHIN GAME.C 

*/


struct Quest
{
    char Name[MAX_NAME];                
    int Health;
    int Mana;
    int Attack;
    int Defense;
    int Gold;
    int Exp;
//  int Armor;  FOR LATER
//
};


#endif // CLASS_H_INCLUDED