#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
bool exists(const char *fpath) {
  FILE *file;
  if((file = fopen(fpath, "r"))) {
    fclose(file);
    return true;
  }
  return false;
}
void write2(const char *fpath, const char *message) {
  FILE *f = fopen(fpath, "w");
  if(f==NULL) {
    printf("Datei konnte nicht gelesen werden!\nDateiname: %s", fpath);
    exit(1);
  }
  fprintf(f, message);
  fclose(f);
}
void wrinte2(const char *fpath, int inte) {
  FILE *f = fopen(fpath, "w");
  if(f==NULL) {
    printf("Datei konnte nicht gelesen werden!\nDateiname: %s", fpath);
    exit(1);
  }
  fprintf(f, "%d", inte);
  fclose(f);
}
void cat2(const char *fpath, const char *message) {
  FILE *f = fopen(fpath, "a");
  if(f==NULL) {
    printf("Datei konnte nicht gelesen werden!\nDateiname: %s", fpath);
    exit(1);
  }
  fprintf(f, message);
  fclose(f);
}
