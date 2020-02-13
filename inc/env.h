//--TRANSLATED 100%--\\

// Environment

#include<stdio.h>

char *envpath;
char *bupath;
char build[32];
char *builds;

int inspect(char b[], char *location, char *country) {
  char *ptr = b;
  envpath = (char*)malloc(128*sizeof(char));
  strcpy(envpath, "arch/locs/");
  strcat(envpath, country);
  if(exists(envpath)==false) {
    printf("ERROR: \"%s\" is not an acceptable path!\n", envpath);
    free(envpath);
    return 0;
  }
  strcat(envpath, "/");
  strcat(envpath, location);
  if(exists(envpath)==false) {
    printf("ERROR: \"%s\" is not an acceptable path!\n", envpath);
    free(envpath);
    return 0;
  }
  bupath = (char*)malloc(128*sizeof(char));
  strcpy(bupath, envpath);
  strcat(bupath, "/buildings.rtf");
  if(exists(bupath)==false) strcpy(bupath, envpath);
  else builds = read(bupath); // Print all buildings in Country/City
  free(bupath);
  
  if(strstr(builds, build)) {
    printf("%s exists.\n", build);
  } else {
    printf("%s doesn't exist.\n", build);
  }
     
  free(envpath);
  return 0;
}
            
void lookAround(char *location, char *country) {
  envpath = (char*)malloc(128*sizeof(char));
  strcpy(envpath, "arch/locs/");
  strcat(envpath, country);
  if(exists(envpath)==false) {
    printf("ERROR: \"%s\" is not an acceptable path!\n", envpath);
    free(envpath);
    return;
  }
  strcat(envpath, "/");
  strcat(envpath, location);
  if(exists(envpath)==false) {
    printf("ERROR: \"%s\" is not an acceptable path!\n", envpath);
    free(envpath);
    return;
  }

  bupath = (char*)malloc(128*sizeof(char));
  strcpy(bupath, envpath);
  strcat(bupath, "/buildings.rtf");
  if(exists(bupath)==false) strcpy(bupath, envpath);
  else pread(bupath); // Print all buildings in Country/City
  free(bupath);
  free(envpath);
  return;
}

void inspectDialog(char *location, char *country) {
  printf(";> ");
  fgets(build, 32, stdin);
  build[strlen(build)-1] = '\0'; // Remove \n
  fflush(stdin);
  inspect(build, location, country);
  return;
}
