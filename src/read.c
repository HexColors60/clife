//--TRANSLATED 100%--//

#include "read.h"

int proto_readConfig(const char *fpath, struct DATA *data) {
  printf("Hey, you loaded!\n");
  //TODO: code
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!CODE: 1\n", fpath);
    return 1; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(sizeof(char)*line_size);
  if(line==NULL) { printf("ERROR: Pointer 'line' not allocated!\n");
    return 1;
  }
  char *ptr = line;
  while(fgets(line, line_size, f) != NULL) {
    char *KEY = malloc(line_size/2);
    char *VALUE = malloc(line_size/2);
    for (int i = 0; i<line_size/2; ++i)
    {
        KEY[i] = '\0';
        VALUE[i] = '\0';
    }
    int counter = 0;
    int found = 0;
    int result = 0;
    for(int i=0; i<line_size; ++i) {
      if(line[i]=='=') { result = i; found = 1; break; }
      else counter++;
    }
    if(found==0)
    {
        printf("Didn't locate '=' sign!\n");
        free(ptr);
        free(KEY);
        free(VALUE);
        return 1;
    }

    printf("Got counter %d.\n", counter);

    int whitespace = 0;
    for(int i=0; i<(result); ++i) {
      if(line[i]==' ') { printf("Found a whitespace!\n"); whitespace = 1; break; }
      KEY[i] = line[i]; // Don't add whitespaces into the key
    }
    if(whitespace==1) {
      fputs("Found a whitespace in the configuration file!\n", stdout);
      fputs("Please check arch/svf/svf.rtf and remove any whitespaces!\n", stdout);
        free(ptr);
        free(KEY);
        free(VALUE);
      return 2;
    }
    printf("%s\n", KEY);
    /* if(!strcmp(KEY,"GOLD")) { */


    if(!strcmp(KEY,"GOLD")) {
      printf("Okay, we are in the Gold currently.\n");
      printf("Before: '%s'\n", ptr);
      /* int linecounter = 0; */
      while(line[0]!='=') {
        line++; // Remove the first character until the first character is =
      }
      line++; // Remove =

      char gChar[line_size];
      memset(&gChar, '\0', sizeof(char)*line_size);
      for(int i=0; i<line_size; ++i) {
        if(line[i]!='\n') {
          gChar[i] = line[i];
        }
      }
      printf("gChar: %s\n", gChar);
      int goldInt = atoi(gChar);
      if(goldInt<=-1) { printf("Re-setting Gold!\n"); goldInt = 0; // If gold is below 0, set it to 0
      }
      printf("Gold, as an int: %d\n", goldInt);
      printf("After: '%s'\n", ptr);
      data->gold = goldInt; // <-- halp
    } else if(!strcmp(KEY,"LOCA")) {
      printf("Okay, we are in the Location currently.\n");
      printf("Before: %s\n", ptr);

      while(line[0]!='=') {
        line++;
      }
      line++;

      char lChar[line_size];
      for(int i=0; i<line_size; ++i) {
        if(line[i]!='\n' && line[i]>=65) {
          lChar[i] = line[i];
        }
      }
      printf("lChar: %s\n", lChar);
      data->loca = lChar;
      printf("After: %s\n", ptr);
    } else if(!strcmp(KEY,"MOTI")) {
      printf("Okay, we are in the Motivation currently.\n");
    } else if(!strcmp(KEY,"NAME")) {
      printf("Okay, we are in the Name currently.\n");
    } else if(!strcmp(KEY,"ROLE")) {
      printf("Okay, we are in the Role currently.\n");
    } else { // Big error :(
      printf("OH NO! OH GOD NO! RUN IN CIRCLES! RUN IN CIRCLES! WE HAVE AN ERROR!\n");
    }

    free(KEY);
    free(VALUE);
  }
  free(ptr);
}

int readConfig(const char *fpath, int g, char *l, int m, char *n, char *r) { // config path file, gold, location, motivation, name, role
  char confFile[128];
  char *pconfFile = confFile;
  /* strcpy(confFile, cL_readWholeFile(fpath, confFile)); */
  pconfFile = cL_readWholeFile(fpath, confFile);
  printf("UNFIXED: %s\n", confFile);

  // Fix read string (weird characters are in the string sometimes)
  while(confFile[0]!='[') { // Save files start with [, so we can remove anything that isn't [ until we hit it
    printf("Removing something!\n");
    memmove(confFile, confFile+1, strlen(confFile+1) + 1);
  }

  printf("FIXED: %s\n", confFile);

  printf("Checking for Gold...\n");
  if(strstr(confFile,"[GOLD]=")!=NULL) {
    printf("Gold found!\n");
    memmove(confFile, confFile+7, strlen(confFile+7) + 7); // Remove [GOLD]=
    int len = strlen(confFile);
    int counter = 0;
    printf("confFile: %s\nLength: %d\n", confFile, len);
    for(int i=0; i<len; ++i) {
      if(confFile[i]!='[') { printf("Counter +! (%d) \n", counter); counter+=1; }
      if(confFile[i]=='[') break;
    }
    printf("Counter: %d\n", counter);
    printf("Gold string is %d long!\n", counter);
    /* pconfFile+=7; */
    char gC[counter+1];
    for(int i=0; i<counter; ++i) {
      gC[i] = confFile[i]; // Put gold into gC
    }
    gC[strlen(gC)+1] = '\0'; // Terminate string correctly.
    memmove(confFile, confFile+counter, strlen(confFile+counter) + counter); // Remove the gold amount
    printf("gC: %s\n", gC);
    printf("Rest of confFile: %s\n", confFile);
  }

  printf("~~~~~\n");

  if(strstr(confFile,"[LOCA]=")!=NULL) {
    printf("Location found!\n");
    memmove(confFile, confFile+7, strlen(confFile+7) + 7); // Remove [LOCA]=
    int counter = 0;
    for(int i=0; i<strlen(confFile); ++i) {
      if(confFile[i]!='[') counter++;
      else break;
    }
    printf("Location string is %d long!\n", counter);
    char lC[counter+1];
    for(int i=0; i<counter; ++i) {
      lC[i] = confFile[i]; // Put location into lC
    }
    lC[counter+1] = '\0'; // Terminate string correctly
    memmove(confFile, confFile+counter, strlen(confFile+counter) + counter); // Remove the Location value
    printf("lC: %s\n", lC);
    printf("Rest of confFile: %s\n", confFile);
  }
  printf("Going out of check.\n");

  return 0;


  /* char *line = malloc(300*sizeof(char)); */
  /* while(getline(confFile, line)) { */
  /*   if(strstr(line,"[GOLD]=")!=NULL) { */
  /*     line+=7; */
  /*     printf("%s\n", line); */
  /*   } */
  /* } */

  /* free(line); */
  /* free(confFile); */
  /* return ""; */
}



char *cL_readWholeFile(const char *fpath, char *buf) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) {
    printf("ERROR: File %s doesn't exist!CODE: 0\n", fpath);
    return "";
  }
  const size_t line_size = 300;
  char *line = malloc(line_size);
  int counter = 0;
  while(fgets(line, line_size, f) != NULL) { strcat(buf, line); }
  free(line);
  return buf;
}

char *cL_read(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!CODE: 1\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f) != NULL) {}
  return line;
}
char *cL_pread(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!CODE 2\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f)!=NULL) { printf("%s", line);
  }
  free(line);
  return "";
}
