//--TRANSLATED 100%--//

#include "misc.h"

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
void seeMotivation(int m) {
    if(m<=0) printf("You don't have any motivation.\nYou should sleep.\n");
    else printf("You are motivated to %d%\% percent!\n", m);
    return;
}
void moneyc(int gold) {
    if(gold==0) printf("You don't have any money with you.\n");
    else printf("You have %d gold coins.\n", gold);
}
void normalInput(char *i) {
    printf("> ");
    char tmps[10];
    char *tmpsem = ";";
    fgets(tmps, 32, stdin);
    tmps[strcspn(tmps, "\n")] = 0;
    strcpy(i, tmpsem);
    strcat(i, tmps);
    /* i = strcat(i, &tmps); */
    /* i[strcspn(i, "\n")] = 0; // Removing \n */
    fflush(stdin);
}
