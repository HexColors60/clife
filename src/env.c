//--TRANSLATED 100%--//

// Environment

#include "env.h"

int inspect(char b[], char *location, char *country, char *buildings[], char key[]) { // b[] = inspectDialog -> build
  char *ptr = b;
  int found = 0;
  int rKey = 0;
  for(int i=0; i<12; ++i) {
    if(buildings[i]==0) break;
    if(!strcmp(buildings[i],ptr)) { rKey = i; found = 1; break; }
    else continue;
  }
  if(found==0) { printf("The building does not exist!\n"); return 0; }
  printf("The Building %s is of type %c\n", buildings[rKey], key[rKey]);
  return 0;

  ///
  /* envpath = (char*)malloc(128*sizeof(char)); */
  /* strcpy(envpath, "arch/locs/"); */
  /* strcat(envpath, country); */
  /* if(exists(envpath)==false) { */
  /*   printf("ERROR: \"%s\" is not an acceptable path!\n", envpath); */
  /*   free(envpath); */
  /*   return 0; */
  /* } */
  /* strcat(envpath, "/"); */
  /* strcat(envpath, location); */
  /* if(exists(envpath)==false) { */
  /*   printf("ERROR: \"%s\" is not an acceptable path!\n", envpath); */
  /*   free(envpath); */
  /*   return 0; */
  /* } */
  /* bupath = (char*)malloc(128*sizeof(char)); */
  /* strcpy(bupath, envpath); */
  /* strcat(bupath, "/buildings.rtf"); */
  /* if(exists(bupath)==false) strcpy(bupath, envpath); */
  /* else builds = cL_read(bupath); // Print all buildings in Country/City */
  /* free(bupath); */

  /* if(strstr(builds, build)) { */
  /*   printf("%s exists.\n", build); */
  /* } else { */
  /*   printf("%s doesn't exist.\n", build); */
  /* } */

  /* free(envpath); */
  /* return 0; */
}

void lookAround(char *location, char *country, char *b[]) { // Len of b is always 12
  printf("You are in %s\nAround you is:\n", location);
  for(int i=0; i<12; ++i) {
    if(b[i]!=0) printf("'%s'\n", b[i]);
    else if(b[i]==0) break;
  }
  /* envpath = (char*)malloc(128*sizeof(char)); */
  /* strcpy(envpath, "arch/locs/"); */
  /* strcat(envpath, country); */
  /* if(exists(envpath)==false) { */
  /*   printf("ERROR: \"%s\" is not an acceptable path!\n", envpath); */
  /*   free(envpath); */
  /*   return; */
  /* } */
  /* strcat(envpath, "/"); */
  /* strcat(envpath, location); */
  /* if(exists(envpath)==false) { */
  /*   printf("ERROR: \"%s\" is not an acceptable path!\n", envpath); */
  /*   free(envpath); */
  /*   return; */
  /* } */

  /* bupath = (char*)malloc(128*sizeof(char)); */
  /* strcpy(bupath, envpath); */
  /* strcat(bupath, "/buildings.rtf"); */
  /* if(exists(bupath)==false) strcpy(bupath, envpath); */
  /* else cL_pread(bupath); // Print all buildings in Country/City */
  /* free(bupath); */
  /* free(envpath); */
  /* return; */
}

void inspectDialog(char *location, char *country, char *buildings[], char key[]) {
  printf(";> ");
  fgets(build, 32, stdin);
  build[strlen(build)-1] = '\0'; // Remove \n
  fflush(stdin);
  inspect(build, location, country, buildings, key);
  return;
}

char checkForReaction(char action) {
  /* printf("Checking for reaction.\n"); */
  if(action==0) return 0;
  if(action=='l') printf("A passerby is giving you a weird stare as you stop laughing.\n");
  return 0;
}

char emotion(char input[], char action) {
  if(strstr(input," laugh")!=NULL) { // ;e laugh
    printf("You begin laughing maniacally.\n");
    action = 'l'; // Keymap may be changed in the future
  }
  return action;
}

/**
 * KEYMAP
 *
 * 'l' = laughing action
 **/
