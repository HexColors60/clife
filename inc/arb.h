#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
char *arbeit;
char *arbst;
int ranint;
int ngeld;

int generieren(int start, int ende) {
  ranint = rand() % ende + start;
  return ranint;
}

bool arbeitMinigame(char *typ) {
  if(!strcmp(typ,"zeitung")) {
    ranint = generieren(1,2);

    switch(ranint) {

    case 1:
      arbst = (char*)malloc(129 * sizeof(char));
      printf("\nOh nein! Der Praktikant hat seine Arbeit nicht richtig gemacht und Zahlen, Sonderzeichen und Apostrophe eingefügt!\nKannst du diesen aritreanischen Satz korrigieren?\n\n");
      printf("ju Majkius, 'ra käpit'lon, 5traga präzidento üff'as\n\n");
      printf("Na klar. Der Satz ist: ");
      fgets(arbst,128, stdin);
      strtok(arbst, "\n");
      fflush(stdin);
      if(strcmp(arbst,"ju Majkius, ra kapitlon, traga prazidento uffas")) {
        printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (Dein Aritreanisch muss besser werden!\n");
        free(arbst);
        return false; // Kein Geld verdient
      } else {
        printf("Du bekommst für deine Mühen eine kleine Entlohnung von 50 Goldstücken.\n");
        free(arbst);
        return true; // Geld verdient
      }
    break;
  case 2:
    arbst = (char*)malloc(129 * sizeof(char));
    printf("Alle Vokale wurden um eins verschoben, also a=e, e=i, i=o, o=u, u=a!\nKannst du den Satz wieder in Ordnung bringen?\n\n");
    printf("ghrut tosmal prezodintun erhotriun hjatels\n\n");
    printf("Na klar. Der Satz ist: ");
    fgets(arbst, 128, stdin);
    strtok(arbst, "\n");
    fflush(stdin);
    if(strcmp(arbst,"ghrat tismul prazidenton arhitreon hjutals")) {
      printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (Dein Aritreanisch muss besser werden!\n");
      free(arbst);
      return false; // Kein Geld verdient
    } else {
      printf("Du bekommst für diene Mühen eine kleine Entlohnung von 50 Goldstücken.\n");
      free(arbst);
      return true;
    }
    }
  }
}
int geldHinzufuegen(int algel, int lohn) { // Altes Geld + Lohn = neues Geld
  ngeld = algel + lohn;
  return ngeld;
}
bool arbeitWaehlen() {
  /* srand(time(NULL)); */
  /* ranint = generieren(4, 1); */
  /* if(ranint==1) { */
    printf("Du arbeitest als Redakteur bei der Regionalzeitung Majkius.\n");
    return arbeitMinigame("zeitung");
  /* } */

    
  /*   if(strcmp(p, "Nova A")) { printf("Du reist für deinen Job nach Nova A.\n"); */
  /*     p = "Nova A"; */
  /*     remove(POSI); */
  /*     write2(POSI, "Nova A"); } */
  /*   if(!strcmp(p, "Nova A")) { printf("Du nimmst einen Job als Marktschreier auf Nova A an.\n"); */
  /*     return "novaa"; } */
  /* } */
  /* if(ranint==2) { */
  /*   if(strcmp(p, "Majkius")) { printf("Du reist für deinen Job nach Majkius.\n"); */
  /*     p = "Majkius"; */
  /*     remove(POSI); */
  /*     write2(POSI, "Majkius"); } */
  /*   if(!strcmp(p, "Majkius")) { printf("Du nimmst einen Job als Postbote für das Rumborviertel in Majkius an.\n"); */
  /*     return "prumbo"; } */
  /* } */
  /* if(ranint==3) { */
  /*   if(strcmp(p, "Nova A")) { printf("Du reist für deinen Job zum Nova A Plateau.\n"); */
  /*     p = "Nova A"; */
  /*     remove(POSI); */
  /*     write2(POSI, "Nova A"); } */
  /*   if(!strcmp(p, "Nova A")) { printf("Du nimmst einen Job als Gartendekorierer auf dem Nova A Plateau an.\n"); */
  /*     return "gnova"; } */
  /* } */
  /* if(ranint==4) { */
  /*   if(strcmp(p, "Metron")) { printf("Du reist für deinen Job nach Metron.\n"); */
  /*     p = "Metron"; */
  /*     remove(POSI); */
  /*     write2(POSI, p); } */
  /*   if(!strcmp(p, "Metron")) { printf("Du nimmst einen Job als Chipmanufakteur in Metron an.\n"); */
  /*     return "cputron"; } */
  /* } */
}
int arbeiten(int algeld) {
  if(arbeitWaehlen()==true) {
    geldHinzufuegen(algeld, 50);
  }

  
  /* if(!strcmp(arbeit,"novaa")) { printf("Du bekommst für deine Tapferkeit 50 Goldstücke.\nAllerdings bist du mit Tomaten beschmissen worden.\n"); */
  /*   geldHinzufuegen(algeld, 50); } */
  /* if(!strcmp(arbeit,"prumbo")) { */
  /*   ranint = generieren(2, 1); */
  /*   if(ranint==1) { printf("Postboten sind gerade gefragt und du bekommst 75 Goldstücke.\n"); */
  /*     geldHinzufuegen(algeld, 75); } */
  /*   if(ranint==2) { printf("Du bekommst für deine Mühe 50 Goldstücke.\n"); */
  /*     geldHinzufuegen(algeld, 50); } */
  /* } */
  /* if(!strcmp(arbeit, "gnova")) { printf("Du bekommst für die Schönheit, die du erschufst, 50 Goldstücke.\n"); */
  /*   geldHinzufuegen(algeld, 50); } */
  /* if(!strcmp(arbeit,"cputron")) { printf("Du bekommst Minimallohn.\n35 Goldstücke.\n"); */
  /*   geldHinzufuegen(algeld, 35); } */
  return ngeld;
}
