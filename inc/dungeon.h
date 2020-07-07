# ifndef __CLIFE_DUNGEON_H__
# define __CLIFE_DUNGEON_H__

# include <time.h>
# include <stdio.h>
# include <ctype.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <ncurses.h>
# include <termios.h>

# include "structs.h"
# include "fight.h"

/* const char *dcommands = "seek: seek for treasures.\nquit: sheepishly leave the dungeon. \n"; */

char decision[8];
char dinput[32];

int dungeonMain();

int checkForDungeon(struct city *city);

int dungeonHead(struct city *city, struct DATA *plr);

int dSpawn();

int dSeek();

int dMap(int x, int y, int Xmax[], int Ymax[]);

int dMap_ncurses(WINDOW *mapwindow, int x, int y, int Xmax[], int Ymax[]);

# endif
