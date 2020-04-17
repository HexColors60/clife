# ifndef __CLIFE_MAP_H__
# define __CLIFE_MAP_H__
//--TRANSLATED 100%--//

# include <stdio.h>
# include <stdlib.h>
# include <string.h>

char *minput;
char *tmpNorth, *tmpSouth;
char *getNorth(char *p); // I have a problem with structs, so I save North and South data for every city manually. Tedious, but it works.

char *getSouth(char *p);

void createMap(char *p, char *l);

void printMap(char *p, char *l);

char *isAWay(char *start, char *richtung); // Bis ich eine elegantere Lösung gefunden habe, muss das hier funktionieren.

char *geheZu(char *p, char *l);

char *getCountry(char *p);

# endif
