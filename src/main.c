// Copyright (C) 2018-2019 cheeesy

/* CLIfe is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or (at
your option) any later version.

CLIfe is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with CLIfe. If not, see <https://www.gnu.org/licenses/>.  */

#define NAME "arch/svf/nom.rtf" // Spielername
#define ROLE "arch/svf/dab.rtf" // Rolle des Spielers
#define GELD "arch/svf/gel.rtf" // Geld
#define POSI "arch/svf/loc.rtf" // Position des Spielers auf der Karte.
#define MOTI "arch/svf/mot.rtf" // Motivation
#define MANU "arch/man/" // Die Hilfsdateien
//#define INV "arch/svf/inv.rtf" // Inventar
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<signal.h>
#include<time.h>
#include "../inc/read.h" // Funktionen zum Lesen von Dateien.
#include "../inc/file.h" // Funktionen zur Dateibenutzung
#include "../inc/story.h" // Funktionen zum Storytelling und Spielbeginn.
#include "../inc/map.h" // Funktionen zum Benutzen der Spielkarte.
#include "../inc/reisen.h" // In Ländern reisen
#include "../inc/arb.h" // Funktionen zum Geld verdienen
#include "../inc/o.h" // Andere Funktionen
#include "../inc/amp.h" // ASCII Spielkarte
//#include "../inc/gvw.h" // Geldverwertung
//#include "../inc/ben.h" // Objekte benutzen
bool file_;
int geld;
int motivation;
double zeit;
char input[10];
char *name;
char *rolle;
char *loc;
char *land;
char *hilfspfad;
const char *ver = "clife 2019.11.23";
const char *help = "clife\n\
\n\
-v, --version\n\
              Version\n\
-h, --help\n\
              Hilfe\n\
-c, --commands\n\
              Befehle\n\
\n\
clife auf GitHub: [ https://github.com/cheeesy/clife ]";
const char *comms = "                            CLIfe Befehle:\n\
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\
| h, hilfe:                        | Alle Befehle auflisten.           |\n\
| geld:                            | Geld ansehen.                     |\n\
| a, arbeit:                       | Geld verdienen.                   |\n\
| wbi:                             | Wo bin ich?                       |\n\
| land:                            | In welchem Land bin ich?          |\n\
| map:                             | ASCII-Karte anzeigen.             |\n\
| goto:                            | Innerhalb des Landes bewegen.     |\n\
| r, reisen:                       | Reise von einem Land zum anderen. |\n\
| e, einkaufen:                    | Etwas kaufen.                     |\n\
| b, benutzen:                     | Benutzen.                         |\n\
| m, motivation:                   | Deine Motivation sehen.           |\n\
| schlafen:                        | Schlafen.                         |\n\
| q, quit, tschüs, tschüß, servus: | Das Spiel verlassen.              |\n\
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
const char *nichtMotiviert = "+-+-ACHTUNG+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+\n\
Du bist unmotiviert!\n\
Du kannst die meisten Aktionen nicht mehr tun,\n\
bis du etwas isst oder schlafen gehst.\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";
void geldbeutel() {
  if(geld==0) printf("Du hast kein Geld bei dir.\n");
  else printf("Du hast %d Goldstücke bei dir.\n", geld);
}
int cexit() {
  printf("Tschüß, %s der %s!\n", name, rolle);
  if(exists(NAME)==false) write2(NAME, name); // Name und Rolle verändern sich nicht
  if(exists(ROLE)==false) write2(ROLE, rolle); // Daher wird sie nur geschrieben, falls sie, wie auch immer, gelöscht wurde.
  wrinte2(GELD, geld); // Der neue Geldstand wird immer gespeichert.
  write2(POSI, loc); // Die Position wird immer gespeichert.
  wrinte2(MOTI, motivation); // Die Motivation wird immer gespeichert.
  return 0;
}

void EchoThing() {
  for(;;) {
    putchar('P');
    normalInput(input);
    input[strcspn(input, "\n")] = 0;   // \n löschen
    printf("%s\n", input);
    if(!strcmp(input,"quit")) return;
    else continue;
  }
}
int main(int argc, char *argv[]) {
  if(argv[1]!=NULL) {
    if(!strcmp(argv[1], "-v") | !strcmp(argv[1], "--version")) { printf("%s\n", ver);
      return 0; }
    if(!strcmp(argv[1], "-h") | !strcmp(argv[1], "--help")) {
      if(argv[2]!=NULL) { hilfspfad = (char*)malloc(65 * sizeof(char));
        strcat(hilfspfad, MANU);
        strcat(hilfspfad, argv[2]);
        strcat(hilfspfad, ".rtf");
        if(exists(hilfspfad)==0) return 0;
        else pread(hilfspfad);
        free(hilfspfad);
        printf("\n");
        return 0; }
      printf("%s\n", help);
      return 0; }
    if(!strcmp(argv[1], "-c") | !strcmp(argv[1], "--commands")) { printf("%s\n", comms);
      return 0; }
    else { printf("%s\n", help);
      return 0; }
  }
  begSequence();
  name = read(NAME);
  rolle = read(ROLE);
  geld = atoi(read(GELD));
  loc = read(POSI);
  motivation = atoi(read(MOTI));
  name[strcspn(name, "\n")] = 0;   // \n löschen
  rolle[strcspn(rolle, "\n")] = 0; //     ^^
  printf("Du bist %s der %s.\n", name, rolle);
  geldbeutel();
  printf("\n");
  land = landErmitteln(loc);
  printMap(loc, land);
  printf("\n");
  for(;;) {
    normalInput(input);
    if(motivation<=0) { printf("%s", nichtMotiviert);
      motivation = 0; }
    if(motivation>=101) motivation = 100;
    if(!strcmp(input,"hilfe") | !strcmp(input,"h")) printf("%s\n", comms);
    if(!strcmp(input,"geld")) geldbeutel();
    if(!strcmp(input,"arbeit") | !strcmp(input,"a")) { if(motivation<=0) printf("Du bist zu unmotiviert!\n");
      else { geld = arbeiten(geld);
        loc = read(POSI); // Falls gereist wird, wird es wieder gelesen.
        printf("Das Arbeiten hat deine Motivation gesenkt.\n");
        motivation = motivation - 10; }
    }
    if(!strcmp(input,"wbi")) printMap(loc, land);
    if(!strcmp(input,"land")) printf("%s\n", land);
    if(!strcmp(input,"map")) printASCIImap(loc);
    if(!strcmp(input,"goto")) { if(motivation<=0) printf("Du bist zu unmotiviert!\n");
      else loc = geheZu(loc, land); }
    
    /* if(!strcmp(input,"einkaufen") | !strcmp(input,"e")) { if(motivation<=0) printf("Du bist zu unmotiviert!\n");
      else { Einkaufen(inv, geld);
        geld = atoi(read(GELD));
        inv = read(INV);
        printf("Durch das Einkaufen hast du Motivation verloren.\n");
        motivation = motivation - 5; } } */
    
    /* if(!strcmp(input,"benutzen") | !strcmp(input,"b")) { benAuswahl(inv); */
    /*   // inv = benAuswahl(inv); sorgt für unvorhersehbares Verhalten. */
    /*   inv = read(INV); */
    /*   motivation = atoi(read(MOTI)); } */
    
    if(!strcmp(input,"r") | !strcmp(input,"reisen")) {
      loc = ganz_reisen(loc, land, motivation); // Diese Funktion ist gedacht, um z.B. von Aritrea nach Liberium zu reisen, aber
      // tatsächlich wird von Metron (Gateway-Stadt) in die Hauptstadt Orar gereist.
      motivation = atoi(read(MOTI)); // Da nur ein Zustand zurückgebracht werden kann, muss der Rest auf die Platte geschrieben werden.
      land = landErmitteln(loc); // Wir müssen ebenfalls noch im Nachhinein, mit Hilfe der Stadt, das Land ermitteln.
    }
    if(!strcmp(input,"motivation") | !strcmp(input,"m")) motivationSehen(motivation);
    if(!strcmp(input,"schlafen")) { if(schlafen(motivation)!=3) motivation = motivation + 15;
      else motivation = motivation - 10; }
    if(!strcmp(input,"servus") | !strcmp(input,"tschüß") | !strcmp(input,"tschüs") | !strcmp(input, "quit") | !strcmp(input,"q")) if(cexit()==0) return 0;
    if(!strcmp(input, "printf")) EchoThing();
  }
}
