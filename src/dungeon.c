// Dungeon Crawler Mode

# include "dungeon.h"

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
            return 0;
        }
    printf("Scared, huh?\n");
    return 0;
}
