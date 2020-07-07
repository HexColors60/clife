# ifndef __CLIFE_MAIN_H__
# define __CLIFE_MAIN_H__
//--TRANSLATED 15%--//

#include <ncurses.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "amp.h" // ASCII (Semigraphical) Map
#include "arb.h" // Working / earning Money
#include "defs.h"
#include "dungeon.h" // Dungeon Crawler Mode
#include "env.h" // Enviroment
#include "file.h" // exists(), File writing
#include "fight.h" // Fighting
#include "map.h" // In-Game Map
#include "misc.h" // Other functions
#include "money.h" // Money Management
#include "read.h" // File reading
#include "story.h" // Storytelling on first Startup, and splash screen
#include "structs.h" // Building structure
#include "travel.h" // Travelling inbetween Countries

int gold;
int motivation;
int level;         // Levels will play a role in minimal and maximal attack in fighting.
int xp = 0;        // XP is only valid for one session.
char action = 0;   // See inc/env.h:emotion() for more details.
char input[32];    // Command input
char *name;        // User name
char *role;        // User Role <-- May be removed or altered in the future.
char *loc;         // Location
char *country;     // Country
char *helpath;     // The path of the help pages <-- May be removed or altered in the future.
const char *ver = "clife 2020.07";
const char *help = "clife\n\
\n\
-v, --version\n\
              Version\n\
-h, --help\n\
              Help\n\
-c, --commands\n\
              Commands\n\
\n\
clife on GitHub: [ https://github.com/cheeesy/clife ]";
const char *comms = "                             CLIfe commands\n\
┌──────────────────────────────────┬─────────────────────────────────────┐\n\
│ h, help:                         │ List all commands.                  │\n\
│ g, gold, money:                  │ View your current money.            │\n\
│ w, work, a:                      │ Earn money.                         │\n\
│ b, beg:                          │ Beg for money.                      │\n\
│ wai:                             │ Where am I?                         │\n\
│ ch:                              │ In which country am I?              │\n\
│ map:                             │ Show ASCII-Map.                     │\n\
│ goto:                            │ Travel in a country.                │\n\
│ e:                               │ Use an emotion.                     │\n\
│ r, travel:                       │ Travel from one country to another. │\n\
│ m, motivation:                   │ View your current motivation.       │\n\
│ s, sleep:                        │ Sleep.                              │\n\
│ q, quit, tschüs, tschüß, servus: │ Quit the game.                      │\n\
└──────────────────────────────────┴─────────────────────────────────────┘";

const char *unMotivated = "┌─ATTENTION!───────────────────────────────┐\n\
│ You are unmotivated!                     │\n\
│ If you are unmotivated you will not be   │\n\
│ able to do most things until you sleep!  │\n\
└──────────────────────────────────────────┘\n";

int cexit();

void EchoThing();

int wrtSvf(const char *fpath);
/* void detStruct(char *location, char *country, int la); */

int main(int argc, char *argv[]);

# endif
