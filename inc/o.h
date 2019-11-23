#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int schlafenGen() {
  int ranlol = rand() % 7 + 1;
  if(ranlol==3) return 3;
  else return 1;
}
int schlafen(int m) {
  if(m>=50) { printf("Du bist zu motiviert zum Schlafen!\n");
    return 3; }
  if(schlafenGen()==3) { printf("Du hattest einen Albtraum!\n Du bist unmotiviert!\n");
    return 3; } 
  else { printf("Du bist motivierter aufgrund eines wundervollen Schlafes:)\n");
    return 1; }
}
void motivationSehen(int m) {
  if(m<=0) printf("Du hast keine Motivation.\nSchlafe oder konsumiere Lebensmittel.\n");
  else printf("Du bist zu %d%\% motiviert!\n", m);
  return;
}
int motivationNiedriger(int m, int mm) {
  return m - mm; // Motivation - MotivationMinus
}
void normalInput(char *i) {
  printf("> ");
  fgets(i, 16, stdin);
  i[strcspn(i, "\n")] = 0; // \n löschen
  fflush(stdin);
}
