//--TRANSLATED 100%--\\

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char *workt;
char *arbst;
int ranint;
int ngold;

int generate(int start, int end) {
  ranint = rand() % end + start;
  return ranint;
}

bool arbeitMinigame(char *typ) {
  if(!strcmp(typ,"newspaper")) {
    ranint = generate(1,2);

    switch(ranint) {

    case 1:
      arbst = (char*)malloc(129 * sizeof(char));
      printf("\nOh no! A worker hasn't done his job right and left numbers and weird characters into the sentence!\nCan you correct this Aritrean sentence?\n\n");
      printf("ju Majkius, 'ra käpit'lon, 5traga präzidento üff'as\n\n");
      printf("Of course. The sentence is: ");
      fgets(arbst,128, stdin);
      strtok(arbst, "\n");
      fflush(stdin);
      if(strcmp(arbst,"ju Majkius, ra kapitlon, traga prazidento uffas")) {
        printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (You have to improve your Aritrean!\n");
        free(arbst);
        return false; // No money earned.
      } else {
	printf("You get a small salary of 50 gold coins for your work.\n");
        free(arbst);
        return true; // Money earned.
      }
    break;
  case 2:
    arbst = (char*)malloc(129 * sizeof(char));
    printf("All vowels are moved by one, so a=e, e=i, i=o, o=u, and u=a!\nCan you bring the sentence in correct order again?\n\n");
    printf("ghrut tosmal prezodintun erhotriun hjatels\n\n");
    printf("Of course. The sentence is: ");
    fgets(arbst, 128, stdin);
    strtok(arbst, "\n");
    fflush(stdin);
    if(strcmp(arbst,"ghrat tismul prazidenton arhitreon hjutals")) {
      printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (Dein Aritreanisch muss besser werden!\n");
      free(arbst);
      return false; // Kein Gold verdient
    } else {
      printf("You get a small salary of 50 gold coins for your work.\n");
      free(arbst);
      return true;
    }
    }
  }
  if(!strcmp(typ,"calculator")) {
    printf("The computing agency of Aritrea wants you to solve this calculation:\n");
    int num1 = generate(1,6);
    int num2 = generate(1,6);
    num1 = num1 * 1000;
    num1 = generate(num1,(num1+999));
    printf("%d + ", num1);
    num2 = num2 * 100;
    num2 = generate(num2,(num2+999));
    printf("%d\n\n", num2);
    int decinp;
    scanf("%d", &decinp);
    if(decinp==(num1+num2)) { printf("You get a small salary of 50 gold coins for your work.\n"); return true; }
    return false;
  }
}
int arb_addMoney(int algel, int lohn) { // New Gold = Old Gold + Salary
  ngold = algel + lohn;
  return ngold;
}
bool arbeitWaehlen(char *loca) {
  srand(time(NULL));
  ranint = generate(1, 4);
  if(ranint==1) {
    if(!strcmp(loca,"Majkius")) {
      printf("You get a job offer for the regional newspaper of Majkius.\n");
      return arbeitMinigame("newspaper"); }
  } else {
    if(strcmp(loca,"Orar")) { // This will get very bigger
      printf("You get a job offer for the computing agency of Aritrea.\n");
      return arbeitMinigame("calculator");
    }
  }
  return false;
    
}
int work(int algold, char *loca) {
  if(arbeitWaehlen(loca)==true) {
    return arb_addMoney(algold, 50);
  } else {
    printf("There are no Jobs in this city.\n");
  }
  return ngold;
}

int beg(int algold) {
  int begSuccess = generate(1,4);
  if(begSuccess==2) {
    printf("You were given 10 Gold coins!\n");
    return arb_addMoney(algold, 10);
  }
  else {
    printf("The people ignored you.\n");
    return algold;
  }
}
