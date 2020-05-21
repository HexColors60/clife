# ifndef __CLIFE_STRUCTS_H__
# define __CLIFE_STRUCTS_H__

# include <string.h>

# include "env.h"
# include "map.h"

struct DATA { // for the data read from the save file
    int  gold;
    int  moti;
    int  levl;
    int  xp; // XP isn't saved
    char loca[300];
    char name[300];
    char role[300];
} plr;

struct DUNGEON {
    char input[32];
    int  gold;
    int  x;
    int  y;
    int  Xmax[2];
    int  Ymax[2];
};

struct HUMANOID {
    int  health;
    int  maxHP;
    int  ATK[2];
    char class;
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

void detStruct(char *location, char *country, int la, struct DATA *data, struct DATA *plr); // la = lookAround? <- determines if the command is lookAround or inspectDialog

void detStruct_plr(struct DATA *plr, int Sswitch);

int checkLevel(int level, int xp);

// Keymap
/* a - Center of a city
   r - Religious Building
*/
# endif
