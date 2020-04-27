// Dungeon Crawler Mode

# include "dungeon.h"

int dungeonMain(struct DUNGEON *dungeon) {
    printf("Waiting for command...\n");
    for(;;) {
        fgets(dinput, 32, stdin);
        dinput[strcspn(dinput, "\n")] = 0;
        fflush(stdin);
        printf("You entered: %s\n", dinput);

        if(!strcmp(dinput, "help")) printf("No help.");
        if(!strcmp(dinput, "seek")) dungeon->gold += dSeek();
        if(!strcmp(dinput, "quit")) return 0;
    }
    return 0;
}

int checkForDungeon(struct city *city) {
    printf("Looking for dungeon in '%s'.\n", city->name);
    /* srand(time(NULL)); */
    /* if((rand() % 5 + 1)!=3) */
    /*     { */
    /*         printf("You felt the presence of a dungeon, but you found no entrance.\n"); */
    /*         return 0; */
    /*     } */
    printf("There it is! The entrance!\n");
    return 1;
}

int dungeonHead(struct city *city) {
    if(checkForDungeon(city)!=1) return 0;
    struct DUNGEON dungeon;
    dungeon.gold = 0;
    printf("Do you want to enter?\n");
    fgets(decision, 8, stdin);
    fflush(stdin);
    for(int i=0; i<8; ++i)
        {
            decision[i] = tolower(decision[i]); // turn 'yEs' or 'yeS' into 'yes'
        }
    if(strstr(decision, "yes") || strstr(decision, "i do")!=NULL) // I believe that those are the most common affirmatives.
        {
            printf("You descend the stairs into the dungeon.\n");
            dungeonMain(&dungeon);
            printf("You got %d gold!\n", dungeon.gold);
            return dungeon.gold;
        }
    printf("Scared, huh?\n");
    return 0;
}

int dSeek() {
    int ranint = rand() % 5 + 1;
    if(ranint!=2) {
        printf("You found 10 Gold!\n");
        return 10;
    }
    else
        {
            printf("You found nothing.\n");
            return 0;
        }
}
