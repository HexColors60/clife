# ifndef __CLIFE_FIGHT_H__
# define __CLIFE_FIGHT_H__

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

# include "structs.h"

char Finput[32];
int Fround;

int FdetMatch(struct HUMANOID *enemy, struct HUMANOID *player, int level);

int Fattack();

int Fencounter(int level);

# endif
