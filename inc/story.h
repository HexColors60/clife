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
  printf("Wie nennt man dich?\nIch bin ");
  scanf("%s", &nom);
  printf("%s\n\nEin guter Name für eine gute Persönlichkeit.\n", nom);
  write2(NAME, nom);
}
void setRole() {
  char *nom = (char*)malloc(101*sizeof(char));
  char role[50];
  strcpy(nom,read(NAME));
  printf("Von welcher Rasse bist du?\n\nIch bin %s der ", nom);
  free(nom);
  scanf("%s", &role);
  printf("Ein %s also... Aha.\n", role);
  printf("┌");
  for(int i=0;i<71;i++) {
    printf("─");
  }
  printf("┐\n");
  printf("│                                                                       │░\r  Nun, %s%s... Ich sehe eine glorreiche Zukunft für dich.\r│\n", role, formulateSentence(getSuffix(role)));
  printf("│                                                                       │░\r  Du wirst eine lange Reise gehen, und viele Schmerzen ertragen müssen.\r│\n");
  printf("│                                                                       │░\r  Aber es ist wichtig, dass du mir das Geheimnis von Ko'hdor bringst.\r│\n");
  printf("│                                                                       │░\n");
  printf("│                                                                       │░\r  Niemand darf es in die Hände bekommen.\r│\n");
  printf("│                                                                       │░\n");
  printf("│                                                                       │░\r  Du fragst dich, was das Geheimnis ist? Nun ja...\r│\n");
  printf("│                                                                       │░\r  Am besten wäre es, wenn du es nicht weißt, bis es nötig ist.\r│\n");
  printf("└");
  for(int i=0;i<71;i++) {
    printf("─");
  }
  printf("┘░\n ");
  for(int i=0; i<73;i++) {
    printf("░");
  }
  printf("\n");
  write2(ROLE, role);
}
void setGeld() {
  int sgeld = 0; // Startgeld
  wrinte2(GELD, sgeld);
}
void setPos() {
  write2(POSI, "Majkius"); // Man startet in Majkius
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

const char *title5 = "/siː laɪf/\n";

void begSequence() {
  srand(time(NULL));
  int ranint = rand() % 5 + 1;
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
  }
  if(exists(NAME)==false) setName();
  if(exists(ROLE)==false) setRole();
  if(exists(GELD)==false) setGeld();
  if(exists(POSI)==false) setPos();
  if(exists(MOTI)==false) setMot();
}
