//--TRANSLATED 100%--\\

#include<stdio.h>
#include<stdlib.h>
char *cL_read(const char *fpath);
char *cL_pread(const char *fpath);
char *cL_readWholeFile(const char *fpath, char *buf);

/* int readConfig(const char *fpath, int g, char *l, int m, char *n, char *r) { // config path file, gold, location, motivation, name, role */
/*   char confFile[128]; */
/*   /\* char *confFile = malloc(300*sizeof(char)); *\/ */
/*   confFile = cL_readWholeFile(fpath, confFile); */
/*   printf("%s", confFile); */

/*   printf("Checking for Gold...\n"); */
/*   if(strstr(confFile,"[GOLD]=")!=NULL) { */
/*     printf("Gold found!\n"); */
/*     confFile+=7; */
/*     char gC[4]; */
/*     strcpy(gC,confFile[0]); */
/*     printf("%s\n", gC); */
/*     printf("%s\n", confFile); */
/*   } */
/*   printf("Going out of check.\n"); */
  
/*   return 0; */


/*   /\* char *line = malloc(300*sizeof(char)); *\/ */
/*   /\* while(getline(confFile, line)) { *\/ */
/*   /\*   if(strstr(line,"[GOLD]=")!=NULL) { *\/ */
/*   /\*     line+=7; *\/ */
/*   /\*     printf("%s\n", line); *\/ */
/*   /\*   } *\/ */
/*   /\* } *\/ */

/*   /\* free(line); *\/ */
/*   /\* free(confFile); *\/ */
/*   /\* return ""; *\/ */
/* } */

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
