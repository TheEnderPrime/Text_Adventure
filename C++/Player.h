#ifndef PLAYER_H
#define PLAYER_H

class Player 
{
    private:
        //string Name;
        int Health;
        int Mana;
        int Attack;
        int Defense;
        int Gold;
        int Exp;
    
    public:
        Player();

        void DisplayPlayerStats();

        int createCharacter();
        
        
};

#endif // CLASS_H_INCLUDED
