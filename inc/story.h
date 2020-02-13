//--TRANSLATED 100%--\\

#include<stdio.h>

char *sent;

char *formulateSentence(char suffix) {
  if(suffix=='e') return "r";
  else return "";
}

char getSuffix(char rolle[]) {
  return rolle[strlen(rolle)-1];
}

void setName() {
  char nom[100];
  printf("How are you called?\nI am ");
  scanf("%s", &nom);
  printf("%s\n\nA fitting name for a personality like yours.\n", nom);
  write2(NAME, nom);
}
void setRole() {
  char *nom = (char*)malloc(101*sizeof(char));
  char role[50];
  strcpy(nom,read(NAME));
  printf("Of what race are you?\n\nI am %s, the ", nom);
  free(nom);
  scanf("%s", &role);
  printf("So you are a %s... I see.\n", role);
  printf("┌");
  for(int i=0;i<71;i++) {
    printf("─");
  }
  printf("┐\n");
  printf("│                                                                       │░\r Well, %s%s... I can see a glorious Fufute for you.      \r│\n", role, formulateSentence(getSuffix(role)));
  printf("│                                                                       │░\r  You will go a long road, and experience certain pain.                \r│\n");
  printf("│                                                                       │░\n");
  printf("│                                                                       │░\r But it is important that you give me the secret of Ko'hdor.        \r│\n");
  printf("│                                                                       │░\r  Nobody may ever receive it.           \r│\n");
  printf("│                                                                       │░\n");
  printf("│                                                                       │░\r You ask what it is? Well...                     \r│\n");
  printf("│                                                                       │░\r  Some secrets are best kept so.                              \r│\n");
  printf("└");
  for(int i=0;i<71;i++) {
    printf("─");
  }
  printf("┘░\n ");
  for(int i=0; i<73;i++) {
    printf("░");
  }
  printf("\n\n");
  write2(ROLE, role);
}
void setGold() {
  int sgold = 0; // Player starts with 0 gold coins
  wrinte2(GOLD, sgold);
}
void setPos() {
  write2(POSI, "Majkius"); // Majkius is the starting city.
}
void setMot() {
  wrinte2(MOTI, 100);
}
const char *title1 = " #####  #       ###               \n\
#     # #        #  ###### ###### \n\
#       #        #  #      #      \n\
#       #        #  #####  #####  \n\
#     # #        #  #      #      \n\
 #####  ####### ### #      ######\n";

const char *title2 = "+--------+--------+--------+--------+--------+\n\
|01000011|01001100|01001001|01100110|01100101|\n\
+--------+--------+--------+--------+--------+\n";

const char *title3 = "+--+--+--+--+--+\n\
|43|4c|49|66|65|\n\
+--+--+--+--+--+\n";

const char *title4 = "+-+-+-+-+-+\n\
|C|L|I|f|e|\n\
+-+-+-+-+-+\n";

const char *title5 = "+---+---+---+---+---+\n\
|067|076|073|102|101|\n\
+---+---+---+---+---+\n";

const char *title6 = "/siː laɪf/\n";

void begSequence() {
  srand(time(NULL));
  int ranint = rand() % 6 + 1;
  switch(ranint) {
  case 1:
    printf("%s\n", title1);
    break;
  case 2:
    printf("%s\n", title2);
    break;
  case 3:
    printf("%s\n", title3);
    break;
  case 4:
    printf("%s\n", title4);
    break;
  case 5:
    printf("%s\n", title5);
    break;
  case 6:
    printf("%s\n", title6);
    break;
  }
  if(exists(NAME)==false) setName();
  if(exists(ROLE)==false) setRole();
  if(exists(GOLD)==false) setGold();
  if(exists(POSI)==false) setPos();
  if(exists(MOTI)==false) setMot();
}
