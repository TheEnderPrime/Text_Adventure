#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player 
{
    private:
        std::string Name;
        std::string Class;
        int Health;
        int Mana;
        int Attack;
        int Defense;
        int Gold;
        int Exp;
    
    public:
        Player();

        void displayPlayerStats();

        int createCharacter();
        
        void setName(std::string x);

        std::string getName();

        std::string getClass();

        void setHealth(int x);

        int getHealth();

        void setMana(int x);

        int getMana();

        void setAttack(int x);

        int getAttack();

        void setDefense(int x);

        int getDefense();

        void setGold(int x);

        int getGold();

        void setExp(int x);

        int getExp();
};

#endif // CLASS_H_INCLUDED
