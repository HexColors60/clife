# ifndef __CLIFE_STRUCTS_H__
# define __CLIFE_STRUCTS_H__

# include <string.h>

# include "env.h"

struct DATA { // for the data read from the save file
    int  gold;
    int  moti;
    char loca[300];
    char name[300];
    char role[300];
};

struct o {    // a copy of what was read from the save file, to compare to the changed variables.
    int  gold;
    char *loc;
    int  mot;
} old;

struct city {
    char *name;
    char *buildings[12];
    char key[12];
} Majkius, NovaA, Metron, Orar;

void setAll(); // Get rid of reading dozens of files and replace it with a nice struct

void detStruct(char *location, char *country, int la); // la = lookAround? <- determines if the command is lookAround or inspectDialog

// Keymap
/* a - Center of a city
   r - Religious Building
*/
# endif
