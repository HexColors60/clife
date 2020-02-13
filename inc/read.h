//--TRANSLATED 100%--\\

#include<stdio.h>
#include<stdlib.h>
char *read(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f) != NULL) {}
  return line;
}
char *pread(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f)!=NULL) { printf("%s", line);
  }
  free(line);
  return "";
}
