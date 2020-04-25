# ifndef __CLIFE_BEN_H__
# define __CLIFE_BEN_H__

# include <stdio.h>
# include <string.h>

# include "defs.h"
# include "file.h"

// UNBENUTZT // UNUSED

char *bencp;
char *neuinv;
int omot;

void neuesInventar(char *inventar, char *benutztesObjekt);

void benutzen(char *inventar, char *objekt, int moti);

void benAuswahl(char *inventar);

# endif
