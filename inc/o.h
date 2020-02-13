//--TRANSLATED 100%--\\

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int sleepGen() {
  int ranlol = rand() % 7 + 1;
  if(ranlol==3) return 3;
  else return 1;
}
int sleep(int m) {
  if(m>=50) { printf("You are too motivated to sleep!\n");
    return 3; }
  if(sleepGen()==3) { printf("You had a terrible nightmare!\n You did not regenerate motivation!\n");
    return 3; }
  else { printf("You are more motivated due to a wonderful rest!:)\n");
    return 1; }
}
void motivationSehen(int m) {
  if(m<=0) printf("You don't have any motivation.\nYou should sleep.\n");
  else printf("You are motivated to %d%\% percent!\n", m);
  return;
}
int motivationNiedriger(int m, int mm) {
  return m - mm; // Motivation - MotivationMinus
}
void normalInput(char *i) {
  printf("> ");
  fgets(i, 16, stdin);
  i[strcspn(i, "\n")] = 0; // Removing \n
  fflush(stdin);
}
