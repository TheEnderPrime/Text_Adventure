#ifndef LOCATIONS_H_INCLUDED
#define LOCATIONS_H_INCLUDED

#define MAX_TITLE 1000                  //REQUIREMENT #5
#define DESCRIPTION 1000                //REQUIREMENT #5

struct Locations
{
    char Title[MAX_TITLE];
    char Description[DESCRIPTION];
    struct Locations *Swamps;           //REQUIREMENT #13
    struct Locations *Meadows;          //REQUIREMENT #13
    struct Locations *Plains;           //REQUIREMENT #13
    struct Locations *Forests;
    struct Locations *Mountains;
    struct Locations *Camps;
};

void createLocations(struct Locations *Road)
{
    struct Locations Swamp =    {"Swamp", "A smelly lake filled with snakes"};
    struct Locations Meadow =   {"Meadow", "A slice of low ground near a river"};
    struct Locations Plain =    {"Plain", "A wide open area filled with tall stalks of grass"};
    struct Locations Forest =   {"Forest", "A densely wooded area"};
    struct Locations Mountain = {"Mountain", "A large steep hill"};
    struct Locations Camp =     {"Camp", "A safe area where you can heal and rest"};

    Road->Swamps = &Swamp;
    Road->Meadows = &Meadow;
    Road->Plains = &Plain;
    Road->Forests = &Forest;
    Road->Mountains = &Mountain;
    Road->Camps = &Camp;
}

//REQUIREMENT #12
struct Locations *getLocation(struct Locations *Road)
{
    struct Locations *Places[6]; //REQUIREMENT #12
    int Area1 = rand()%5;
    int Area2 = rand()%5;
    //printf("\n\nThe first number is %d\n", Area1); printf("The second number is %d\n", Area2);
    printf("\n\nFierce Adventurer! Where would you like to explore?\n\n");

    Places[0] = Road->Swamps;
    Places[1] = Road->Meadows;
    Places[2] = Road->Plains;
    Places[3] = Road->Forests;
    Places[4] = Road->Mountains;
    Places[5] = Road->Camps;
    //printf("%s\n", Places[0]->Title);
    printf("1. %s\n", Places[Area1]->Title);
    printf("2. %s\n", Places[Area2]->Title);
    printf("3. %s\n", Places[5]->Title);
    printf("\nChoice: ");

    int status, temp;
    int Selection;
    status = scanf("%d", &Selection);
    while(status!=1)
    {
        while((temp=getchar()) != EOF && temp != '\n')
        {
            printf("Error! Location Choice Not Valid!\nChoice: ");
            status = scanf("%d", &Selection);
        }
    }

    if(Selection == 1)
        Selection = Area1;
    else if(Selection == 2)
        Selection = Area2;
    else if(Selection == 3)
        Selection = 5;
    else
    {
        printf("\nError! Location Code Not Valid!");
        printf("\nYou Get Lost and Decide To Camp For The Night...");
        Selection = 5;
    }

    pageBreak();
    printf("\nArea Chosen: %s", Places[Selection]->Title);
    printf("\n%s\n", Places[Selection]->Description);

    return Places[Selection];
}
#endif // LOCATIONS_H_INCLUDED
