//--TRANSLATED 100%--\\

#include<stdio.h>
#include<stdlib.h>
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
