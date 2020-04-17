# ifndef __CLIFE_ENV_H__
# define __CLIFE_ENV_H__
//--TRANSLATED 100%--//

// Environment

#include <string.h>
#include <stdio.h>

char *envpath;
char *bupath;
char build[32];
char *builds;

int inspect(char b[], char *location, char *country, char *buildings[], char key[]); // b[] = inspectDialog -> build

void lookAround(char *location, char *country, char *b[]); // Len of b is always 12

void inspectDialog(char *location, char *country, char *buildings[], char key[]);

char checkForReaction(char action);

char emotion(char input[], char action);

/**
 * KEYMAP
 *
 * 'l' = laughing action
 **/
# endif
