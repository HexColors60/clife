// Environment

#include<stdio.h>

char *envpath;
char *bupath;

void lookAround(char *location, char *country) {
  envpath = (char*)malloc(128*sizeof(char));
  strcpy(envpath, "arch/locs/");
  strcat(envpath, country);
  if(exists(envpath)==false) {
    printf("Es gibt einen Fehler mit dem Spiel. \"%s\" ist kein akzeptabler Pfad!\n", envpath);
    free(envpath);
    return;
  }
  strcat(envpath, "/");
  strcat(envpath, location);
  if(exists(envpath)==false) {
    printf("Es gibt einen Fehler mit dem Spiel. \"%s\" ist kein akzeptabler Pfad!\n", envpath);
  }

  bupath = (char*)malloc(128*sizeof(char));
  strcpy(bupath, envpath);
  strcat(bupath, "/buildings.rtf");
  if(exists(bupath)==false) strcpy(bupath, envpath);
  else pread(bupath); // Print all buildings in Country/City
  free(bupath);
  free(envpath);
}
