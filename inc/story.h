# ifndef __CLIFE_STORY_H__
# define __CLIFE_STORY_H__
//--TRANSLATED 100%--//

# include <ncurses.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <time.h>

//# include "ben.h"
# include "defs.h"
# include "file.h"
# include "read.h"

char *sent;
char *getName(struct DATA *data);
char *getRole(struct DATA *data);
void printStory(char *role);

void begSequence(struct DATA *d);

void setGold();

void setPos();

void setMot();

void printStory();

# endif
