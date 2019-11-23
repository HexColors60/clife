#include<stdio.h>
#include<stdlib.h>
char *minput;
char *tmpNorth, *tmpSouth;
char *getNorth(char *p) { // Da Structs nicht funktioniert haben (Ich muss mich da noch mal einlesen), speichere ich Nord- und Süddaten manuell für jeden Ort ab.
  if(!strcmp(p,"Majkius")) return "Nova A";
  else if(!strcmp(p,"Nova A")) return "0";
  else if(!strcmp(p,"Metron")) return "Majkius";
  else return "0";
}
char *getSouth(char *p) {
  if(!strcmp(p,"Majkius")) return "Metron";
  else if(!strcmp(p,"Nova A")) return "Majkius";
  else if(!strcmp(p,"Metron")) return "0";
  else return "0";
}
void createMap(char *p, char *l) {
  printf("\n┌──────────────────────────────────────────┐\n");
  printf("│                                          │\r│ Du bist in %s.\n", p);

  tmpNorth = (char*)malloc(33 * sizeof(char));
  strcpy(tmpNorth,getNorth(p));
  if(strcmp(tmpNorth,"0")) {
    printf("│                                          │\r│ Nördlich von dir ist %s.\n", tmpNorth);
    free(tmpNorth);
  } else free(tmpNorth);

  tmpSouth = (char*)malloc(33 * sizeof(char));
  strcpy(tmpSouth,getSouth(p));
  if(strcmp(tmpSouth,"0")) {
    printf("│                                          │\r│ Südlich von dir ist %s.\n",tmpSouth);
    free(tmpSouth);
  } else free(tmpSouth);
  printf("└──────────────────────────────────────────┘\n\n");
  return;
}

void printMap(char *p, char *l) {
  createMap(p,l);
  /* if(!strcmp(p,"Majkius")) printf("Du bist in %s.\nNördlich von dir ist Nova A.\nSüdlich von dir ist Metron.\n", p); */
  /* else if(!strcmp(p,"Nova A")) printf("Du bist in %s.\nSüdlich von dir ist Majkius.\n", p); */
  /* else if(!strcmp(p,"Metron")) printf("Du bist in %s.\nNördlich von dir ist Majkius.\n", p); */
  /* else if(!strcmp(p,"Orar")) printf("Du bist in %s.\n", p); */
  /* else printf("Du hast dich verlaufen.\n"); */
  return;
}

char *wegVorhanden(char *start, char *richtung) { // Bis ich eine elegantere Lösung gefunden habe, muss das hier funktionieren.
  if(!strcmp(start,"Majkius")) {
    if(!strcmp(richtung, "norden")) { printf("Du gehst nach Norden zu Nova A.\n");
      return "Nova A"; }
    else if(!strcmp(richtung, "sueden")) { printf("Du gehst nach Süden zu Metron.\n");
      return "Metron"; }
    else { printf("Dort führt kein Weg entlang.\n");
      return start; }
  }

  if(!strcmp(start, "Nova A")) {
    if(!strcmp(richtung, "sueden")) { printf("Du gehst nach Süden zu Majkius.\n");
      return "Majkius"; }
    else { printf("Dort führt kein Weg entlang.\n");
      return start; }
  }

  if(!strcmp(start, "Metron")) {
    if(!strcmp(richtung, "norden")) { printf("Du gehst nach Norden zu Majkius.\n");
      return "Majkius"; }
    else { printf("Dort führt kein Weg entlang.\n");
      return start; }
  }

  if(!strcmp(start, "Orar")) {
    printf("Dort führt kein Weg entlang.\n");
    return start;
  }
}

char *geheZu(char *p, char *l) {
  printMap(p, l);
  printf("In welche Richtung willst du gehen?\nSchreibweise für Richtungen:\nnorden\nosten\nsueden\nwesten\n\n");
  minput = (char*)malloc(129 * sizeof(char));
  fgets(minput, 128, stdin);
  strtok(minput, "\n");
  fflush(stdin);
  if(!strcmp(p, "Majkius") | !strcmp(p, "Nova A") | !strcmp(p, "Metron") | !strcmp(p, "Orar")) p = wegVorhanden(p, minput);
  free(minput);
  return p;
}
char *landErmitteln(char *p) {
  if(!strcmp(p, "Nova A")) return "Aritrea";
  if(!strcmp(p, "Majkius")) return "Aritrea";
  if(!strcmp(p, "Metron")) return "Aritrea";
  if(!strcmp(p, "Orar")) return "Liberium";
}
