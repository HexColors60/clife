# ifndef __CLIFE_DUNGEON_H__
# define __CLIFE_DUNGEON_H__

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

# include "structs.h"

/* const char *dcommands = "seek: seek for treasures.\nquit: sheepishly leave the dungeon. \n"; */

char decision[8];
char dinput[32];

int dungeonMain();

int checkForDungeon(struct city *city);

int dungeonHead(struct city *city);

int dSeek();

# endif
