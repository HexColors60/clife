# ifndef __CLIFE_DUNGEON_H__
# define __CLIFE_DUNGEON_H__

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>
# include <ctype.h>

# include "structs.h"

char decision[8];

int dungeonMain();

int checkForDungeon(struct city *city);

int dungeonHead(struct city *city);

# endif
