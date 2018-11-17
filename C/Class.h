#ifndef CLASS_H_INCLUDED
#define CLASS_H_INCLUDED

#define MAX_NAME 21                 //REQUIREMENT 5

struct Character
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

int createCharacter(struct Character *Player)
{
    printf("Please Enter the Name of your Adventurer (%d characters or less): ", MAX_NAME-1);
    fgets(Player->Name, MAX_NAME, stdin);   //REQUIREMENT 6
    strtok(Player->Name, "\n");//THIS GETS RID OF THE \n IN THE NAME AS TO MAKE IT STREAMLINED WITH THE OTHER NAMES
    printf("\nAre You A? \n1. Warrior \n2. Ranger \n3. Wizard\n\n");
    int status, temp;
    int Selection;
    printf("Choice: ");
    status = scanf("%d", &Selection);   //REQUIREMENT 6
    while(status!=1)
    {
        while((temp=getchar()) != EOF && temp != '\n')
        {
            printf("Error! Character Code Not Valid!\nChoice: ");
            status = scanf("%d", &Selection);   //REQUIREMENT 6
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
        Player->Health = 40;
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

void DisplayStats(struct Character Target)
{
    printf("\nName: %s\nHealth: %d\nMana: %d\nAttack: %d\nDefense: %d\n", Target.Name, Target.Health, Target.Mana, Target.Attack, Target.Defense);
}

void createGoblin(struct Character *Goblin)
{
    strcpy(Goblin->Name, "Goblin");
    Goblin->Health = 25;
    Goblin->Mana = 5;
    Goblin->Attack = 10;
    Goblin->Defense = 10;
}

void createGhost(struct Character *Ghost)
{
    strcpy(Ghost->Name, "Ghost");
    Ghost->Health = 5;
    Ghost->Mana = 10;
    Ghost->Attack = 30;
    Ghost->Defense = 30;
}

void createWitch(struct Character *Witch)
{
    strcpy(Witch->Name, "Witch");
    Witch->Health = 30;
    Witch->Mana = 25;
    Witch->Attack = 15;
    Witch->Defense = 15;
}

createOgre(struct Character *Ogre)
{
    strcpy(Ogre->Name, "Ogre");
    Ogre->Health = 50;
    Ogre->Mana = 5;
    Ogre->Attack = 30;
    Ogre->Defense = 30;
}

createDragon(struct Character *Dragon)
{
    strcpy(Dragon->Name, "Dragon");
    Dragon->Health = 100;
    Dragon->Mana = 30;
    Dragon->Attack = 70;
    Dragon->Defense = 50;
}
#endif // CLASS_H_INCLUDED
