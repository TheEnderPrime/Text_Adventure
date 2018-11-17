#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

Player::Player()
{ 
    cout << "Hello Player!" << endl; 
}

Player::DisplayPlayerStats()
{
    cout << "\nName: " << getName() << "\nHealth: " << getHealth() << "\nMana: " << getMana() << "\nAttack: " << getAttack() << "\nDefense: " << getDefense();
}

Player::createCharacter()
{
    printf("What is your Name Adventurer! (%d characters or less): ", MAX_NAME-1);
    fgets(Player->Name, MAX_NAME, stdin);
    strtok(Player->Name, "\n"); //THIS GETS RID OF THE \n IN THE NAME AS TO MAKE IT STREAMLINED WITH THE OTHER NAMES
    
    printf("\nAre You A? \n1. Warrior \n2. Ranger \n3. Wizard\n\n");
    int status, temp;
    int Selection;
    printf("Choice: ");
    status = scanf("%d", &Selection);   
    
    while(status!=1)
    {
        while((temp=getchar()) != EOF && temp != '\n')
        {
            printf("Error! Character Code Not Valid!\nChoice: ");
            status = scanf("%d", &Selection);   
        }
    }
    if(Selection == 1)
    {
        Player->Health = 50;
        Player->Mana = 10;
        Player->Attack = 20;
        Player->Defense = 20;
        Player->Gold = 0;
        Player->Exp = 0;
        return 50;
    }
    else if(Selection == 2)
    {
        Player.setHealth = 40;
        Player->Mana = 25;
        Player->Attack = 15;
        Player->Defense = 15;
        Player->Gold = 0;
        Player->Exp = 0;
        return 40;
    }
    else if(Selection == 3)
    {
        Player->Health = 25;
        Player->Mana = 50;
        Player->Attack = 25;
        Player->Defense = 5;
        Player->Gold = 0;
        Player->Exp = 0;
        return 25;
    }
    else
    {
        printf("\nError! Character Choice Not Valid!\n");
        createCharacter(Player);
    }
}

// Player::setName(string x)
// {
//     Name = x;
// }

// Player::getName()
// {
//     return Name;
// }

// Player::setHealth(int x)
// {
//     Health = x;
// }

// Player::getHealth()
// {
//     return Health;
// }

// Player::setMana(int x)
// {
//     Mana = x;
// }

// Player::getMana()
// {
//     return Mana;
// }

// Player::setAttack(int x)
// {
//     Attack = x;
// }

// Player::getAttack()
// {
//     return Attack;
// }

// Player::setDefense(int x)
// {
//     Defense = x;
// }

// Player::getDefense()
// {
//     return Defense;
// }

// Player::setGold(int x)
// {
//     Gold = x;
// }

// Player::getGold()
// {
//     return Gold;
// }

// Player::setExp(int x)
// {
//     Exp = x;
// }

// Player::getExp()
// {
//     return Exp;
// }