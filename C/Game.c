#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Class.h"
#include "Systems.h"
#include "Locations.h"
//#include "Quest.h"

int main()
{
    srand(time(NULL));

//FUNCTION DECLARATIONS
void createMonster(struct Character *Monster);
int Fight(struct Character *Player, struct Character *Monster, int HealthAmount);
struct Character *Loot(struct Character *Player);
int getAction(struct Character *Player, struct Character *Monster, int HealthAmount);
void checkforCamp(struct Locations *CurrentArea, struct Locations *Areas, struct Character *Hero, int HealthAmount);
int LevelUp(struct Character *Hero, int HealthAmount);
int Magic(struct Character *Hero, struct Character *Monster, int HealthAmount);
int DragonQuest(struct Character *Hero, struct Character *Monster, int HealthAmount, int VictoryEnding, int count);

//VARIABLES AND CHARACTERS

struct Character Hero; //Character to Play and Change Stats
struct Character Monster;
struct Locations Areas; //Original Collection of All Locations
struct Locations CurrentArea; //Current Area Chosen By getLocation
int FightResult = 2;
int *ptrResult = &FightResult;
int VictoryEnding = 0;
int HealthAmount;

//START UP AND SET UP
    Welcome();
    HealthAmount = createCharacter(&Hero);
    DisplayStats(Hero);
    pageBreak(); //spacer
    getQuest();
    int count = 4;//how many monsters you have defeated -- COUNT
    do
    {
//GET LOCATION
        createLocations(&Areas);
        CurrentArea = *getLocation(&Areas);
        checkforCamp(&CurrentArea, &Areas, &Hero, HealthAmount);
//GET ACTION - FIGHT OR LOOT
        createMonster(&Monster);
//CHECKS FOR CAMP
        if(strcmp(CurrentArea.Title, Areas.Camps->Title) != 0)
        {
            *ptrResult = getAction(&Hero, &Monster, HealthAmount);
//IF KILL IS SUCCESSFUL THEN ADD KILL TO THE COUNT
            if(*ptrResult == 2)
            {
                ++count;
                printf("You have killed %d Monsters", count);
            }
        }
//AFTER 5 KILLS THEN DRAGON WILL APPEAR AND IF SUCCESSFUL KILL THEN VICTORY
        int QuestReturn;
        QuestReturn = DragonQuest(&Hero, &Monster, HealthAmount, VictoryEnding, count);
        if(QuestReturn == 0)
            count = 0;
        else if(QuestReturn == 1)
        {
            *ptrResult = 1;
            Defeat();
        }
        else if(QuestReturn == 2)
            VictoryEnding = 2;
    }while(*ptrResult != 1 && VictoryEnding != 2);

    return 0;
}

//*************FUNCTIONS****************

//CREATES MONSTER
void createMonster(struct Character *Monster)
{
    int Chance;
    Chance = rand()%10;
    if(Chance == 5 || Chance == 6)
        createGhost(Monster);
    else if(Chance == 7 || Chance == 8)
        createWitch(Monster);
    else if(Chance == 9 || Chance == 10)
        createOgre(Monster);
    else createGoblin(Monster);
}

//FIGHT
int Fight(struct Character *Player, struct Character *Monster, int HealthAmount)
{//returns 0 is successful flee, return 1 if hero dead, return 2 if monster dead
    DisplayStats(*Player);
    DisplayStats(*Monster);

    printf("-------------------------------");
    printf("\n\n1. Stand and Fight!\n2. Magic!\n3. Try to Flee!\n");
    int status, temp;
    int Selection;
    printf("Choice: ");
    status = scanf("%d", &Selection);
    while(status!=1)
    {
        while((temp=getchar()) != EOF && temp != '\n')
        {
            printf("Error! Fight Choice Not Valid\nChoice: ");
            status = scanf("%d", &Selection);
        }
    }
    printf("\n-------------------------------");
    if(Selection == 1)
    {
//Player Hits First
        printf("\nHero Attacks!\n");
        int Damage, realDamage;
        Damage = Player->Attack - Monster->Defense;
        if(Damage < 0)
            realDamage = rand()%5;
        else if(Damage == 0)
            realDamage = rand()%5;
        else realDamage = rand()%Damage;

        Monster->Health = Monster->Health - realDamage;
        printf("Hero Does %d Damage to the %s!", realDamage, Monster->Name);
        if(Monster->Health <= 0)
        {
            printf("\n\nVictory! Death to the Monster!");
            pageBreak();//spacer
            return 2;
        }
//Monster Hits Second
        printf("\n\nMonster Attacks!");
        Damage = Monster->Attack - Player->Defense;
        if(Damage <= 0)
        {
            Damage = 5;
        }
        realDamage = rand()%Damage;
        Player->Health = Player->Health - realDamage;
        printf("\n\nMonster Does %d Damage to %s!\n", realDamage, Player->Name);
//Check Health and Recursive Fighting
        if(Player->Health <= 0)
        {
            printf("\n\nYou died!\nGame Over!\n\n");
            Defeat();
            return 1;
        }
        else return Fight(Player, Monster, HealthAmount);
    }
    else if(Selection == 2)
    {
        Magic(Player, Monster, HealthAmount);
        if(Monster->Health <= 0)
        {
            printf("\n\nVictory! Death to the Monster!");
            pageBreak();//spacer
            return 2;
        }
        else return Fight(Player, Monster, HealthAmount);
    }
    else if(Selection == 3)
    {
        int Chance;
        Chance = rand()%11;
        if(Chance < 8)
        {
            printf("\nSuccess! You Tuck Your Tail and Run!");
            return 0;
        }
        else if(Chance > 7)
        {
            printf("\nFailed Attempt to Flee!\n");
            int Damage, realDamage;
            printf("\nMonster Attacks!");
            Damage = Monster->Attack - Player->Defense;
            realDamage = rand()%Damage;
            Player->Health = Player->Health - realDamage;
            printf("\n\nMonster Does %d Damage to %s!\n", realDamage, Player->Name);
            if(Player->Health <= 0)
            {
                printf("\n\nYou died!\nGame Over!\n\n");
                Defeat();
                return 1;
            }
            return Fight(Player, Monster, HealthAmount);
        }
    }
    else
    {
        printf("\n\nError! Fight Choice Not Valid!");
        Fight(Player, Monster, HealthAmount);
    }
}

//GET LOOT
struct Character *Loot(struct Character *Player)
{
    int Money;
    Money = rand()%50;
    Player->Gold += Money;
    printf("\nGained %d Gold!\n", Money);
    printf("You have a total of %d Gold!\n", Player->Gold);
    return Player;
}

//LOOT OR FIGHT?
int getAction(struct Character *Player, struct Character *Monster, int HealthAmount)
{
    int Chance;
    Chance = rand()%11;
    //printf("\nAction Chance is: %d\n", Chance);
    if(Chance >= 3)
    {
        printf("\nBattle!\n");
        printf("A %s Has Appeared!\n", Monster->Name);
        int FightResult;
        FightResult = Fight(Player, Monster, HealthAmount);
        return FightResult;
    }
    else
    {
        printf("\nTreasure!");
        printf("\nYou wander by a loot chest. What could be in it?\n");
        Loot(Player);
        return 0;
    }
}

//CHECK FOR CAMP
void checkforCamp(struct Locations *CurrentArea, struct Locations *Areas, struct Character *Hero, int HealthAmount)
{
    if(strcmp(CurrentArea->Title, Areas->Camps->Title) == 0)
        {
            if(Hero->Health < HealthAmount)
            {
                Hero->Health += 5;
                printf("You now have %d health!", Hero->Health);
            }
            else printf("\nHealth @ MAX...\nHealth @ MAX...\nHealth @ MAX...\n");
        }
}

//LEVEL UP
int LevelUp(struct Character *Hero, int HealthAmount)
{
    printf("LEVEL UP! LEVEL UP! LEVEL UP! LEVEL UP! LEVEL UP!\n");
    Hero->Health = HealthAmount + 20;
    Hero->Attack += 10;
    Hero->Defense += 10;
    DisplayStats(*Hero);
    return Hero->Health;
}

//MAGIC -- FINALLY!!! ;)
int Magic(struct Character *Hero, struct Character *Monster, int HealthAmount)
{
    printf("\n1. Heal\n2. Fireball\n3. Ice\n4. SpellBook\nChoice: ");
    int Selection, status, temp;
    status = scanf("%d", &Selection);
    printf("\n-------------------------------");
    while(status!=1 && Selection > 4 && Selection < 1)
    {
        while((temp=getchar()) != EOF && temp != '\n')
        {
            printf("Error! Spell Choice Not Valid\nChoice: ");
            status = scanf("%d", &Selection);
            printf("\n-------------------------------");
        }
    }
    if(Selection == 1)//HEAL - HEALTH
    {
        if(Hero->Health < HealthAmount)
            {
                Hero->Health += 20;
                Hero->Mana -= 5;
            }
        else printf("Health @ MAX");
    }
    else if(Selection == 2)//FIREBALL - BIG DAMAGE
    {
        Monster->Health -= 25;
        Hero->Mana -= 10;
    }
    else if(Selection == 3)//ICE - BONUS STANDARD ATTACK
    {
        printf("\nIce Freezes The %s! You Strike!\n", Monster->Name);
        int realDamage;
        realDamage = rand()%(Hero->Attack);
        Monster->Health = Monster->Health - realDamage;
        printf("Hero Does %d Damage to the %s!", realDamage, Monster->Name);
        if(Monster->Health <= 0)
        {
            printf("\n\nVictory! Death to the Monster!");
            pageBreak();//spacer
            return 2;
        }
    }
    else printf("\nHeal Returns a Portion of Your Health Back.\nFireball attacks with set amount of damage.\nIce stuns your enemy so that you can have one extra standard attack.\n");
}

//Dragon Quest Battle
int DragonQuest(struct Character *Hero, struct Character *Monster, int HealthAmount, int VictoryEnding, int count)
{
    if(count == 5)
        {
            printf("\n\nYou Have Angered THE MIGHTY DRAGON!!! You should probably heal before he shows up...");
            printf("\nDo you wish to Heal?\n1. Yes\n2. No\nChoice: ");
            int Selection, status, temp;
            status = scanf("%d", &Selection);
            while(status!=1)
            {
                while((temp=getchar()) != EOF && temp != '\n')
                {
                    printf("Error! Heal Choice Not Valid\nChoice: ");
                    status = scanf("%d", &Selection);
                }
            }
//IF YOU GO TO CAMP BEFORE DRAGON YOU LEVEL UP
            if(Selection == 1)
            {
                pageBreak();
                HealthAmount = LevelUp(Hero, HealthAmount);
                //HOLDS AT LEVEL UP UNTIL READY
                int Choice;
                do{
                    int i;
                    for(i=0;i<200000000;i++);
                    printf("\n\nAre you ready to continue?\n1. Yes\n2. No\nChoice: ");
                    status = scanf("%d", &Choice);
                    while(status!=1)
                    {
                        while((temp=getchar()) != EOF && temp != '\n')
                        {
                            printf("Error! Continue Choice Not Valid\nChoice: ");
                            status = scanf("%d", &Choice);
                        }
                    }
                }while(Choice != 1);

            }
            else printf("Good Luck...\n\n");
//DRAGON HATCH AND FIGHT
            createDragon(Monster);
            DragonHatch();
            printf("\n---------------------");
            printf("\n\nBOSS BATTLE!\n");
            int Result = Fight(Hero, Monster, HealthAmount);
            if(Result == 2)
            {
                Victory();
                VictoryEnding = 2;
                return VictoryEnding; //checks for this in main
            }
            else if(Result == 0)
            {
                printf("\n\nAs you flee, the Dragon bellows that you are not worth of his time...");
                count = 0;
                return 0; //checks for this in main
            }
        }
}

//{//HELP LIST

// printf("%s\n", Areas.Swamps->Title); // Access the member variable of the object then uses that to access through the pointer to the title
// printf("%s\n", Areas.Meadows->Description);
// printf("\nIn main you choose: %s\n", CurrentArea.Title);

//   *ptr ==> Variable pointed to
//    ptr ==> Address pointed to
// * moves the pointer past the address and onto the variable in the ptr
// & gets the address

//STANDARD INTEGER INPUT AND CHECK -- SAVE FOR LATER --- IGNORE THIS JOSEPH :)
//int num, status, temp;
//    printf("Please enter how many students you have: ");
//    status = scanf("%d", &num);
//    while(status!=1)
//    {
//        while((temp=getchar()) != EOF && temp != '\n')
//        {
//            printf("Error! Please enter how many students you have: ");
//            status = scanf("%d", &num);
//        }
//    }
//    return num;
//}
