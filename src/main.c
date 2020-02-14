//--TRANSLATED 15%--\\

// Copyright (C) 2018-2020 cheeesy

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

#define NAME "arch/svf/nom.rtf" // Name
#define ROLE "arch/svf/rol.rtf" // Role
#define GOLD "arch/svf/gol.rtf" // Money
#define POSI "arch/svf/loc.rtf" // Player's position
#define MOTI "arch/svf/mot.rtf" // Motivation
#define MANU "arch/man/" // Help files
//#define INV "arch/svf/inv.rtf" // Inventory // defunct
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#include<signal.h>
#include<time.h>
#include "../inc/money.h" // Money Management
#include "../inc/read.h" // File reading
#include "../inc/file.h" // exists(), File writing
#include "../inc/story.h" // Storytelling on first Startup and splash screen
#include "../inc/map.h" // In-Game Map
#include "../inc/reisen.h" // Travelling inbetween Countries
#include "../inc/arb.h" // Working / earning Money
#include "../inc/env.h" // Enviroment
#include "../inc/o.h" // Other functions
#include "../inc/amp.h" // ASCII (Semigraphical) Map
//#include "../inc/gvw.h" // Shopping // defunct
//#include "../inc/ben.h" // Using items // defunct
bool file_;
int gold;
int motivation;
char input[10];
char *name;
char *role;
char *loc;
char *ch;
char *helpath;
const char *ver = "clife 2020.02";
const char *help = "clife\n\
\n\
-v, --version\n\
              Version\n\
-h, --help\n\
              Help\n\
-c, --commands\n\
              Commands\n\
\n\
clife on GitHub: [ https://github.com/cheeesy/clife ]";
const char *comms = "                             CLIfe commands\n\
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+\n\
| h, help:                         | List all commandsisten.             |\n\
| g, gold, money:                  | View your current money.            |\n\
| a, work:                         | Earn money.                         |\n\
| b, beg:                          | Beg for money.                      |\n\
| wai:                             | Where am I?                         |\n\
| ch:                              | In which country am I?              |\n\
| map:                             | Show ASCII-Map.                     |\n\
| goto:                            | Travel in a country.                |\n\
| r, travel:                       | Traven from one country to another. |\n\
| m, motivation:                   | View your current motivation.       |\n\
| s, sleep:                        | Sleep.                              |\n\
| q, quit, tschüs, tschüß, servus: | Quit the game.                      |\n\
+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~+";
const char *unMotivated = "+-+-ATTENTION-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n\
You are unmovitvated!\n\
If you are unmotivated you will not be able\n\
to do most things until you sleep!\n\
+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-\n";

void moneyc() {
  if(gold==0) printf("You don't have any money with you.\n");
  else printf("You have %d gold coins.\n", gold);
}
int cexit() {
  printf("Arheto, %s, the %s!\n", name, role); // "Arheto" means "Goodbye" in Aritrean.
  // Name and Role don't change, and are therefore only written if the file is lost - for whatever reason.
  if(exists(NAME)==false) write2(NAME, name); 
  if(exists(ROLE)==false) write2(ROLE, role);
  wrinte2(GOLD, gold); // The amount of gold is always saved.
  write2(POSI, loc); // The location is always saved.
  wrinte2(MOTI, motivation); // The motivation is always saved.
  return 0;
}

void EchoThing() {
  char echo[128];
  for(;;) {
    putchar('P');
    printf("> ");
    fgets(echo, 128, stdin);
    echo[strlen(echo)-1] = '\0';
    fflush(stdin);
    printf("%s\n", echo);
    if(echo[0]=='q') if(echo[1]=='u') if(echo[2]=='i') if(echo[3]=='t') if(echo[4]=='\0') return;
    else continue;
  }
}

int main(int argc, char *argv[]) { 
  if(argv[1]!=NULL) {
    if(!strcmp(argv[1], "-v") | !strcmp(argv[1], "--version")) { printf("%s\n", ver);
      return 0; }
    if(!strcmp(argv[1], "-h") | !strcmp(argv[1], "--help")) {
      if(argv[2]!=NULL) { helpath = (char*)malloc(65 * sizeof(char));
        strcat(helpath, MANU);
        strcat(helpath, argv[2]);
        strcat(helpath, ".rtf");
        if(exists(helpath)==0) return 0;
        else pread(helpath);
        free(helpath);
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
  role = read(ROLE);
  gold = atoi(read(GOLD));
  loc = read(POSI);
  motivation = atoi(read(MOTI));
  name[strcspn(name, "\n")] = 0;   // remove \n
  role[strcspn(role, "\n")] = 0; // remove \n
  printf("You are %s, the %s.\n", name, role);
  moneyc();
  printf("\n");
  ch = getCountry(loc);
  printMap(loc, ch);
  printf("\n");
  for(;;) { // Loop until cexit()==0
    normalInput(input);
    if(motivation<=0) { printf("%s", unMotivated);
      motivation = 0; }
    if(motivation>=101) motivation = 100;
    // If motivation is too high or too low, change it to the maximum/minimum.
    if(!strcmp(input,"help") | !strcmp(input,"h")) printf("%s\n", comms);
    if(!strcmp(input,"gold") | !strcmp(input,"g") | !strcmp(input,"money")) moneyc();
    if(!strcmp(input,"work") | !strcmp(input,"a")) { if(motivation<=0) printf("You aren't motivated enough to work.\n");
      else { gold = work(gold, loc);
	printf("Your motivation has been lowered.\n");
        motivation = motivation - 10; }
    }
    if(!strcmp(input,"beg") | !strcmp(input,"b")) { if(motivation<=0) printf("You are not motivated enough to beg.\n");
      else { gold = beg(gold);
	printf("Your motivation has been lowered.\n");
	motivation = motivation - 10; }
    }
    if(!strcmp(input,"wai")) printMap(loc, ch);
    if(!strcmp(input,"ch")) printf("%s\n", ch);
    if(!strcmp(input,"map")) printASCIImap(loc);
    if(!strcmp(input,"goto")) { if(motivation<=0) printf("You are not motivated enough!\n");
      else loc = geheZu(loc, ch); }
    
    if(!strcmp(input,"r") | !strcmp(input,"travel")) {
      loc = ganz_reisen(loc, ch, motivation, gold); // Travel from gateway city to capital of country.
      motivation = atoi(read(MOTI)); // Read motivation after travel
      if(strcmp(ch,getCountry(loc))) { printf("You had to pay 30 gold coins as a toll!\n");
        gold = removeMoney(gold, 30); }
      ch = getCountry(loc); // Also we have to get the country using the city we now have.
    }
    if(!strcmp(input,"motivation") | !strcmp(input,"m")) motivationSehen(motivation);
    if(!strcmp(input,"sleep") | !strcmp(input,"s")) { if(sleep(motivation)!=3) motivation = motivation + 30;
      else motivation = motivation - 10; }
    if(!strcmp(input,"servus") | !strcmp(input,"tschüß") | !strcmp(input,"tschüs") | !strcmp(input, "quit") | !strcmp(input,"q")) if(cexit()==0) return 0;

    // DEBUG TOOLS
    if(!strcmp(input, "umsehen")) lookAround(loc, ch);
    if(!strcmp(input, "de")) inspectDialog(loc, ch);
    if(!strcmp(input, "printf")) EchoThing();
  }
}
