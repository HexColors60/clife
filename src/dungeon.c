// Dungeon Crawler Mode

# include "dungeon.h"

const char *dHelp = "                           Dungeon Commands                           \n\
┌────────────────────────────┬───────────────────────────────────────┐\n\
│ help                       │ Display this help.                    │\n\
│ coords                     │ Show where you are.                   │\n\
│ n, e, s, w                 │ Go in a direction.                    │\n\
│ ;spawn                     │ Spawn a monster (debug).              │\n\
│ seek                       │ Take the risk and seek for treasures. │\n\
│ map                        │ Display a map of the dungeon.         │\n\
│ quit                       │ Leave the dungeon.                    │\n\
└────────────────────────────┴───────────────────────────────────────┘";

int dungeonMain(struct DUNGEON *dungeon, struct DATA *plr) {

    // int dMap_ncurses(WINDOW *mapwindow, int x, int y, int Xmax[], int Ymax[]) {
    int debug = 1;

    if(debug==1) {
        initscr();
        noecho();
        cbreak();

        clear();

        int yMax, xMax;
        getmaxyx(stdscr, yMax, xMax);

        box(stdscr, 0, 0);

        WINDOW *mapwin = newwin((dungeon->Ymax[1]+2), (dungeon->Xmax[1]+2), 1, 2);
        refresh();
        box(mapwin, 0, 0);
        wrefresh(mapwin);

        dMap_ncurses(mapwin, dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
    
        /* WINDOW *deWin = newwin((yMax), (xMax-1), 0, 1); */
        /* refresh(); */
        /* box(deWin, 0, 0); */
        /* wrefresh(deWin); */

        char i = getch();

        if(i=='k')
            {
                dungeon->y++;
                dMap_ncurses(mapwin, dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
            }

        getch();

        endwin();

        return 0;
    }

    printf("Xmax0: %d\nXmax1: %d\n\nYmax0: %d\nYmax1: %d", dungeon->Xmax[0], dungeon->Xmax[1], dungeon->Ymax[0], dungeon->Ymax[1]);
    
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

        
        if(!strcmp(dinput, "n") | !strcmp(dinput, "north") | !strcmp(dinput, "k"))
            {
                if(((dungeon->y)+1) > (dungeon->Ymax[1])+1)
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the north.\n");
                dungeon->y++;
                dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
            }
        if(!strcmp(dinput, "e") | !strcmp(dinput, "east") | !strcmp(dinput, "l"))
            {
                if(((dungeon->x)+1) > (dungeon->Xmax[1])+1)
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the east.\n");
                dungeon->x++;
                dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
            }
        if(!strcmp(dinput, "s") | !strcmp(dinput, "south") | !strcmp(dinput, "j"))
            {
                if(((dungeon->y)-1) < (dungeon->Ymax[0])+1)
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the south.\n");
                dungeon->y--;
                dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
            }
        if(!strcmp(dinput, "w") | !strcmp(dinput, "west") | !strcmp(dinput, "h"))
            {
                if(((dungeon->x)-1) < (dungeon->Xmax[0])+1)
                    {
                        printf("You walked against a wall.\n");
                        continue;
                    }
                printf("You walk towards the south.\n");
                dungeon->x--;
                dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax);
            }


        if(!strcmp(dinput, ";spawn")) // Debug command; an enemy appearing should be random
            {
                int oldgold = dungeon->gold;
                dungeon->gold += dSpawn(plr->levl);
                if(dungeon->gold>=oldgold)
                    plr->xp += 10;
            }

        if(!strcmp(dinput, "seek")) dungeon->gold += dSeek(plr->levl);

        if(!strcmp(dinput, "map")) /* dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax); */ printf("%d\n",dMap(dungeon->x, dungeon->y, dungeon->Xmax, dungeon->Ymax));
        
        if(!strcmp(dinput, "quit")) break;
        continue;
    }
    return 0;
}

int checkForDungeon(struct city *city) {
    printf("Looking for dungeon in '%s'.\n", city->name);
    return 1;
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
    dungeon.y       = 1;
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

int dMap(int x, int y, int Xmax[], int Ymax[]) {
    /**
      * x and y are the coordinates of the
      * player. Xmax and Ymax are the max-
      * imum coordinates which are used to
      * draw the box.
      **/
    
    int curX = 0;
    int curY = Ymax[1];

    int i = 0;
    
    printf("+");
    for(i; i<Xmax[1]; ++i)
        {
            printf("-");
            ++curX;
        }
    i = 0;
    printf("+\n");
    
    for(curY; curY>0; --curY)
        {
            printf("|");
            for(i; i<Xmax[1]; ++i)
                {
                    if(curY==y && i==x)
                        {
                            printf("@");
                        } else
                        printf(".");
                }
            i = 0;
            printf("|\n");
            
        }
    
    printf("+");
    for(i; i<Xmax[1]; ++i)
        {
            printf("-");
            ++curX;
        }
    i = 0;
    printf("+\n");
    return 0;
}

int dMap_ncurses(WINDOW *mapwindow, int x, int y, int Xmax[], int Ymax[]) {
    /**
      * x and y are the coordinates of the
      * player. Xmax and Ymax are the max-
      * imum coordinates which are used to
      * draw the box.
      **/

    int curX = 0;
    int curY = Ymax[1];
    
    int i = 0;
    
    wprintw(mapwindow, "+");
    for(i; i<Xmax[1]; ++i)
        {
            wprintw(mapwindow, "-");
            ++curX;
        }
    i = 1;
    wprintw(mapwindow, "+");
    wrefresh(mapwindow);
    refresh();

    for(int j=0; j<curY; j++)
    /* for(i; i<curY; ++i) */
        /* for(curY; curY>0; --curY) */
        {
            /* move(14,14); */
            /* printw("%d %d", i, curY); */
            /* wrefresh(stdscr); */
            /* refresh(); */
            
            wprintw(mapwindow, "|");
            wrefresh(mapwindow);
            refresh();
            //            return 0;
            for(int k = 0; k<Xmax[1]; ++k)
                {
                    if(/*curY*/j==y && k==x)
                        {
                            wprintw(mapwindow, "@");
                        }
                    else
                        {
                            wprintw(mapwindow, ".");
                        }
                }
            i = 0;
            wprintw(mapwindow, "|");
            
            wrefresh(mapwindow);
            refresh();

            /* getch(); */
            
            /* if(exists("/tmp/CLIFEDEBUG")==false) */
            /*     wrinte2("/tmp/CLIFEDEBUG", i); */
            /* else */
            /*     appende2("/tmp/CLIFEDEBUG", i); */
            move(curY+2, 2);
        }
    wrefresh(mapwindow);
    refresh();
    
    printf("+");
    for(i; i<Xmax[1]; ++i)
        {
            printf("-");
            ++curX;
        }
    i = 0;
    printf("+\n");
    return 0;

}
