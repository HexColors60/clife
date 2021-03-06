

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

# ifndef __CLIFE_DUNGEON_H__
# define __CLIFE_DUNGEON_H__

char decision[8];
char dinput[32];

extern int dungeonMain(struct DUNGEON *dungeon, struct DATA *plr);

extern int checkForDungeon(struct city *city);

extern int dungeonHead(struct city *city, struct DATA *plr);

extern int dSpawn();

extern int dSeek();

extern int dMap(int x, int y, int Xmax[], int Ymax[]);

extern int dMap_ncurses(WINDOW *mapwindow, int x, int y, int Xmax[], int Ymax[]);

# endif
