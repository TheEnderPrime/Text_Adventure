#include "Player.h"
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int MAX_NAME = 20;

Player::Player()
{ 
    cout << "Hello Player! Create Your Character!" << endl; 
    createCharacter();
}

void Player::displayPlayerStats()
{
    cout << "\nName: " << Name << "\nHealth: " << Health << "\nMana: " << Mana << "\nAttack: " << Attack << "\nDefense: " << Defense << endl;
}

int Player::createCharacter() //gets name and class
{
    cout << "What is your Name Adventurer! (" << MAX_NAME-1 << " characters or less): " << endl;
    cin >> Name;
    //strtok(Player->Name, "\n"); //THIS GETS RID OF THE \n IN THE NAME AS TO MAKE IT STREAMLINED WITH THE OTHER NAMES
    
    cout << "\nAre You A? \n1. Warrior \n2. Ranger \n3. Wizard\n\n";

    int Selection;
    cout << "Choice: ";
    cin >> Selection;

    if(Selection == 1)
    {
        Class = "Warrior";
        Health = 50;
        Mana = 10;
        Attack = 20;
        Defense = 20;
        Gold = 0;
        Exp = 0;
        return 50;
    }
    else if(Selection == 2)
    {
        Class = "Ranger";
        Health = 40;
        Mana = 25;
        Attack = 15;
        Defense = 15;
        Gold = 0;
        Exp = 0;
        return 40;
    }
    else if(Selection == 3)
    {
        Class = "Wizard";
        Health = 25;
        Mana = 50;
        Attack = 25;
        Defense = 5;
        Gold = 0;
        Exp = 0;
        return 25;
    }
    else if(cin.fail()) // error checking for non integer entries
    {
        cin.clear();
        cin.ignore();
        cout << "\nError! Character Choice Not Valid!\n";
        createCharacter();
    }
    else // error checking for outside of range entries (not 1-3)
    {
        cout << "\nError! Character Choice Not Valid!\n";
        createCharacter();
    }
}

void Player::setName(string x)
{
    Name = x;
}

string Player::getName()
{
    return Name;
}

string Player::getClass()
{
    return Class;
}

void Player::setHealth(int x)
{
    Health = x;
}

int Player::getHealth()
{
    return Health;
}

void Player::setMana(int x)
{
    Mana = x;
}

int Player::getMana()
{
    return Mana;
}

void Player::setAttack(int x)
{
    Attack = x;
}

int Player::getAttack()
{
    return Attack;
}

void Player::setDefense(int x)
{
    Defense = x;
}

int Player::getDefense()
{
    return Defense;
}

void Player::setGold(int x)
{
    Gold = x;
}

int Player::getGold()
{
    return Gold;
}

void Player::setExp(int x)
{
    Exp = x;
}

int Player::getExp()
{
    return Exp;
}