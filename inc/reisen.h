#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *landWechseln(char *l, char *p) {
  printf("In welches Land möchtest du?\n");
  printf("Du kannst von %s nach:\n", p);
  if(!strcmp(p, "Aritrea")) printf("Liberium\n");
  if(!strcmp(p, "Liberium")) printf("Aritrea\n");
  char *buf = (char*)malloc(128 * sizeof(char));
  fgets(buf, 127, stdin);
  strtok(buf, "\n");
  if(!strcmp(p, "Aritrea")) {
    if(!strcmp(buf, "Liberium")) {
      if(!strcmp(l,"Metron")) {
        printf("Du reist nach %s.\n", buf);
        p = buf;
        return buf;
      } else {
        printf("Metron ist der einzige Weg nach Liberium.\n");
        free(buf);
        return "nowhere";
      }
    }
  }
  if(!strcmp(p, "Liberium")) {
    if(!strcmp(buf, "Aritrea")) {
      if(!strcmp(l, "Orar")) {
        printf("Du reist nach %s.\n", buf);
        p = buf;
        return buf;
      } else {
        printf("Orar ist der einzige Weg nach Aritrea.\n");
        free(buf);
        return "nowhere";
      }
    }
  }
  else { printf("Das Land ist nicht bekannt oder betretbar!\n");
  free(buf);
  return "nowhere"; }
free(buf);
}
char *ganz_reisen(char *l, char *p, int Motivation) {
  p = landWechseln(l, p);
  if(!strcmp(p, "Liberium")) l = "Orar"; // Es wird immer in die Hauptstadt gereist.
  if(!strcmp(p, "Aritrea")) l = "Majkius";
  if(!strcmp(p, "nowhere")) l = l; // Man geht quasi nirgendswo hin, sondern bleibt, wo man ist.
  if(strcmp(p,"nowhere")) {
    printf("Du bist vom Reisen ganz unmotiviert. Am besten gönnst du dir erstmal eine Pause.\n");
    if(Motivation>=35) Motivation = 35;
    wrinte2(MOTI, Motivation);
  }
  return l;
}
