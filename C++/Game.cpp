#include <iostream>
#include <string>
#include <time.h>

#include "Player.h"
#include "ASCII.h"

using namespace std;

//COMPILE LINE -> g++ -o Game Game.cpp -static-libstdc++ -static-libgcc
//The statics fix something wrong with GCC, I should reinstall it from sourceforge to fix the problem

int main ()
{
    //srand(time(NULL));

    ASCII ascii;
    Player player; // creates the player

    ascii.Welcome();    
    player.displayPlayerStats();
    
    return 0;
}