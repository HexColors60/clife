// Dungeon Crawler Mode

# include "dungeon.h"

const char *dHelp = "                           Dungeon Commands                           \n\
┌────────────────────────────┬───────────────────────────────────────┐\n\
│ help                       │ Display this help.                    │\n\
│ coords                     │ Show where you are.                   │\n\
│ n, e, s, w                 │ Go in a direction.                    │\n\
│ ;spawn                     │ Spawn a monster (debug).              │\n\
│ seek                       │ Take the risk and seek for treasures. │\n\
│ quit                       │ Leave the dungeon.                    │\n\
└────────────────────────────┴───────────────────────────────────────┘";

int dungeonMain(struct DUNGEON *dungeon, struct DATA *plr) {
    printf("Waiting for command...\n");
    for(;;) {
        printf("DUNGEON> ");
        fgets(dinput, 32, stdin);
        dinput[strcspn(dinput, "\n")] = 0;
        fflush(stdin);
        printf("You entered: %s\n", dinput);

        if(!strcmp(dinput, "xp")) printf("XP: %d\n", plr->xp);
        if(!strcmp(dinput, "gold")) printf("GOLD: %d\n", dungeon->gold);
        
        if(!strcmp(dinput, "help")) printf("%s\n", dHelp);
        if(!strcmp(dinput, "coords")) printf("x: %d\ny: %d\n", dungeon->x, dungeon->y);

        
        if(!strcmp(dinput, "n") | !strcmp(dinput, "north"))
            {
                if(((dungeon->y)+1) > dungeon->Ymax[1])
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the north.\n");
                dungeon->y++;
            }
        if(!strcmp(dinput, "e") | !strcmp(dinput, "east"))
            {
                if(((dungeon->x)+1) > dungeon->Xmax[1])
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the east.\n");
                dungeon->x++;
            }
        if(!strcmp(dinput, "s") | !strcmp(dinput, "south"))
            {
                if(((dungeon->y)-1) < dungeon->Ymax[0])
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the south.\n");
                dungeon->y--;
            }
        if(!strcmp(dinput, "w") | !strcmp(dinput, "west"))
            {
                if(((dungeon->x)-1) < dungeon->Xmax[0])
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the south.\n");
                dungeon->x--;
            }


        if(!strcmp(dinput, ";spawn")) // Debug command; an enemy appearing should be random
            {
                int oldgold = dungeon->gold;
                dungeon->gold += dSpawn(plr->levl);
                if(dungeon->gold>=oldgold)
                    plr->xp += 10;
            }
        if(!strcmp(dinput, "seek")) dungeon->gold += dSeek(plr->levl);
        if(!strcmp(dinput, "quit")) break;
        continue;
    }
    return 0;
}

int checkForDungeon(struct city *city) {
    printf("Looking for dungeon in '%s'.\n", city->name);
    srand(time(NULL));
    if((rand() % 5 + 1)!=3)
        {
            printf("You felt the presence of a dungeon, but you found no entrance.\n");
            return 0;
        }
    printf("There it is! The entrance!\n");
    return 1;
}

int dungeonHead(struct city *city, struct DATA *plr) {
    if(checkForDungeon(city)!=1) return 0;
    printf("NAME: %s\n", plr->name);
    struct DUNGEON dungeon;
    dungeon.gold    = 0;
    dungeon.x       = 5;
    dungeon.y       = 0;
    dungeon.Xmax[0] = 0; // Xmax[0] = west corner
    dungeon.Xmax[1] = 7; // Xmax[1] = east corner
    dungeon.Ymax[0] = 0; // Ymax[0] = south corner
    dungeon.Ymax[1] = 8; // Ymax[1] = north corner
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
            dungeonMain(&dungeon, plr);
            printf("You got %d gold!\n", dungeon.gold);
            plr->gold += dungeon.gold;
            return 0;
        }
    printf("Scared, huh?\n");
    return 0;
}

int dSpawn(int level) {
    printf("You heard something...\n");
    return Fencounter(level);
}

int dSeek(int level) {
    int ranint = rand() % 5 + 1;
    if(ranint!=2)
        {
            printf("You found 10 Gold!\n");
            return 10;
        }
    else if(ranint==2)
        {
            printf("You heard a voice...\n");
            return Fencounter(level);
        }
    else
        {
            printf("You found nothing.\n");
            return 0;
        }
    return 0;
}
