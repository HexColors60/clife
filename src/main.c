//--TRANSLATED 15%--//

// Copyright (C) 2018-2020 cheeesy

/**
  * MIT License
  *
  * Copyright (c) 2020 cheeesy
  *
  * Permission is hereby granted, free of charge, to any person obtaining a copy
  * of this software and associated documentation files (the "Software"), to deal
  * in the Software without restriction, including without limitation the rights
  * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  * copies of the Software, and to permit persons to whom the Software is
  * furnished to do so, subject to the following conditions:
  * 
  * The above copyright notice and this permission notice shall be included in all
  * copies or substantial portions of the Software.
  * 
  * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  * SOFTWARE. 
  **/

# include "main.h"

void print_DATA(struct DATA *data)
{
    printf("gold: %d\n", data->gold);
    printf("moti: %d\n", data->moti);
    printf("loca: %s\n", data->loca);
    printf("name: %s\n", data->name);
    printf("role: %s\n", data->role);
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
                else cL_pread(helpath);
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
    /* readConfig("arch/svf/svf.rtf", gold, loc, motivation, name, role); */
    /* return 0; */
    /* name = "default"; */
    /* role = "default"; */
    /* loc = "Majkius"; */
    /* /\* strcpy(name, "default"); *\/ */
    /* /\* strcpy(role, "default"); *\/ */
    /* gold = 0; */
    /* strcpy(loc, "Majkius"); */
    /* motivation = 100; */
    // In case something goes wrong with reading the savefile, this is the backup data.
    plr.levl = 0;

    
    struct DATA data;
    /* struct DATA plr; */
    /* struct DATA *dptr = &data; */
    if(exists(SVF)==true) if(readConfig(SVF, &data)==2) return 0;

    begSequence(&data);

    print_DATA(&data);
  
    /* return 0; */
    /* readConfig("arch/svf/svf.rtf", gold, loc, motivation, name, role); */
    /* return 0; */

    strcpy(plr.name, data.name);
    strcpy(plr.role, data.role);
    /* plr.role = data.role; */
    plr.gold = data.gold;
    strcpy(plr.loca, data.loca);
    /* plr.loca = data.loca; */
    plr.moti = data.moti;
    plr.levl = data.levl;
    plr.xp = 0; // XP is only valid for one session.
    
    /* name = data.name; */
    /* role = data.role; */
    /* gold = data.gold; */
    /* loc = data.loca; */
    /* motivation = data.moti; */
    /* level = data.levl; */


    
    /* name = cL_read(NAME); */
    /* role = cL_read(ROLE); */
    /* gold = atoi(cL_read(GOLD)); */
    /* loc = cL_read(POSI); */
    /* motivation = atoi(cL_read(MOTI)); */
    old.gold = data.gold;
    old.loc = data.loca;
    old.mot = data.moti;
    /* name[strcspn(name, "\n")] = 0;   // remove \n */
    /* role[strcspn(role, "\n")] = 0; // remove \n */
    printf("You are %s, the %s.\n", plr.name, plr.role);
    moneyc(plr.gold);
    country = getCountry(plr.loca);
    printMap(plr.loca, country);
    printf("\n");
    setAll(); // set all structs
    for(;;) { // Loop until cexit()==0
        
        if(plr.moti<=0) { printf("%s", unMotivated);
            plr.moti = 0; }
        if(plr.moti>=101) plr.moti = 100;
        
        normalInput(input);
        
        action = checkForReaction(action);

        if(checkLevel(level, xp)==1) {
            printf("You just leveled up!\n%d => ", level);
            ++level;
            printf("%d!\n", level);
        }

        if(!strcmp(input,";help") | !strcmp(input,";h")) printf("%s\n", comms);

        if(!strcmp(input,";gold") | !strcmp(input,";g") | !strcmp(input,";money")) moneyc(plr.gold);

        if(!strcmp(input,";w") | !strcmp(input,";work") | !strcmp(input,";a")) { if(plr.moti<=0) printf("You aren't motivated enough to work.\n");
            else { plr.gold = work(plr.gold, plr.loca);
                printf("Your motivation has been lowered.\n");
                plr.moti-=10; }
        }

        if(!strcmp(input,";beg") | !strcmp(input,";b")) { if(plr.moti<=0) printf("You are not motivated enough to beg.\n");
            else { plr.gold = beg(plr.gold);
                printf("Your motivation has been lowered.\n");
                plr.moti-=10; }
        }

        if(!strcmp(input,";wai")) printMap(plr.loca, country);

        if(!strcmp(input,";ch")) printf("%s\n", country);

        if(!strcmp(input,";map")) printASCIImap(loc);

        if(!strcmp(input,";goto")) { if(plr.moti<=0) printf("You are not motivated enough!\n");
            else strcpy(plr.loca, geheZu(plr.loca, country));
            /* else plr.loca = geheZu(plr.loca, country); } */
        }

        if(strstr(input,";e ")!=NULL) { action = emotion(input, action); }

        if(!strcmp(input,";r") | !strcmp(input,";travel")) {
            char *oldloc;
            oldloc = (char*)malloc(32*sizeof(char));
            strcpy(oldloc, plr.loca);
            strcpy(plr.loca, ganz_reisen(plr.loca, country, plr.moti, plr.gold)); // Travel from gateway city to capital of country.
            /* loc = ganz_reisen(plr.loca, country, plr.moti, plr.gold); // Travel from gateway city to capital of country. */
            if(strcmp(oldloc, plr.loca)) // If player does have the money to pay the toll.
                {
                    plr.moti = elaMotivatio(101); // The argument 101 reads the motivation, anything else writes it.
                    if(strcmp(country,getCountry(plr.loca))) { printf("You had to pay 30 gold coins as a toll!\n");
                        plr.gold = removeMoney(plr.gold, 30); }
                    country = getCountry(plr.loca); // Also we have to get the country using the city we now have.
                }

            free(oldloc);
        }

        if(!strcmp(input,";motivation") | !strcmp(input,";m")) seeMotivation(plr.moti);

        if(!strcmp(input,";sleep") | !strcmp(input,";s")) { if(goSleep(plr.moti)!=3) plr.moti = 80;
            else plr.moti-=10; }
        /* else motivation = motivation - 10; } */

        if(!strcmp(input,";version")) printf("You're running %s.\n", ver);

        if(!strcmp(input,";servus") | !strcmp(input,";tschüß") | !strcmp(input,";tschüs") | !strcmp(input,";quit") | !strcmp(input,";q")) if(cexit()==0) return 0;

        // DEBUG TOOLS; WILL BE REMOVED OR BUILT IN SOON
        /* if(!strcmp(input, ";dungeon")) { detStruct(plr.loca, country, 2, &data, &plr); plr.gold = data.gold; } */
        if(!strcmp(input, ";dungeon"))
            detStruct_plr(&plr, 0);
        if(!strcmp(input, ";umsehen")) { detStruct(plr.loca, country, 0, &data, &plr); plr.gold = data.gold; } 
        if(!strcmp(input, ";de")) { detStruct(plr.loca, country, 1, &data, &plr); plr.gold = data.gold; }
        if(!strcmp(input, ";printf")) EchoThing();

        
    }
}

int cexit() {
    printf("Arheto, %s, the %s!\n", plr.name, plr.role); // "Arheto" means "Goodbye" in Aritrean.
    /* wrtSvf(SVF, data); */
    if(exists(SVF)==false || old.gold!=plr.gold || strcmp(old.loc,plr.loca) || old.mot!=plr.moti) wrtSvf(SVF);
    /* // Name and Role don't change, and are therefore only written if the file is lost - for whatever reason. */
    /* if(exists(NAME)==false) write2(NAME, name); */
    /* if(exists(ROLE)==false) write2(ROLE, role); */
    /* if(old.gold!=gold) wrinte2(GOLD, gold); // The amount of gold, the location and the motivation is always saved, unless it did not change. */
    /* if(strcmp(old.loc,loc)) write2(POSI, loc); */
    /* if(old.mot!=motivation) wrinte2(MOTI, motivation); */
    return 0;
}

void EchoThing() {
    char echo[128];
    while(1) {
        putchar('P');
        printf("> ");
        fgets(echo, 128, stdin);
        echo[strlen(echo)-1] = '\0';
        fflush(stdin);
        printf("'%s'\n", echo);
        if(echo[0]=='q' && echo[1]=='u' && echo[2]=='i' && echo[3]=='t'&& echo[4]=='\0') { printf("Quitting.\n"); return; }
        if(echo[0]=='g') printf("Gold: %d\n", plr.gold);
        if(echo[0]=='l') printf("Location: %s\n", plr.loca);
        if(echo[0]=='c') printf("Country: %s\n", getCountry(plr.loca));
        if(echo[0]=='m') printf("Motivation: %d\n", plr.moti);
        if(echo[0]=='l' && echo[1]=='e') printf("Level: %d\n", plr.levl);
        if(echo[0]=='x') printf("XP: %d\n", plr.xp);
        else continue;
    }
}

int wrtSvf(const char *fpath)
{
    char buf[300];
    char *compl;
    compl = (char*)malloc(512*sizeof(char));
    for(int i=0; i<6; ++i)
        {
            if(i==0) // Gold
                {
                    char tmp[16];
                    sprintf(tmp, "%d", plr.gold);
                    strcpy(buf, "GOLD=");
                    strcat(buf, tmp);
                    strcat(buf, "\n");
                    printf("'%s' '%s'\n", tmp, buf);
                    strcpy(compl, buf);
                }
            if(i==1) // Location
                {
                    strcpy(buf, "LOCA=");
                    strcat(buf, plr.loca);
                    strcat(buf, "\n");
                    printf("'%s'\n", buf);
                    strcat(compl, buf);
                }
            if(i==2) // Motivation
                {
                    char tmp[4];
                    sprintf(tmp, "%d", plr.moti);
                    strcpy(buf, "MOTI=");
                    strcat(buf, tmp);
                    strcat(buf, "\n");
                    printf("'%s' '%s'\n", tmp, buf);
                    strcat(compl, buf);
                }
            if(i==3) // Name
                {
                    strcpy(buf, "NAME=");
                    int offset = strlen(buf);
                    for(int i=0; i<300; ++i)
                        {
                            buf[offset]=plr.name[i];
                            if(plr.name[i]=='\0') break;
                            ++offset;
                        } // plr.name didn't work so.... time for a dirty hack!
                    strcat(buf, "\n");
                    printf("'%s'\n", buf);
                    strcat(compl, buf);
                }
            if(i==4) // Role
                {
                    strcpy(buf, "ROLE=");
                    strcat(buf, plr.role);
                    strcat(buf, "\n");
                    printf("'%s'", buf);
                    strcat(compl, buf);
                }
            if(i==5) // Level
                {
                    char tmp[8];
                    sprintf(tmp, "%d", plr.levl);
                    strcpy(buf, "LEVL=");
                    strcat(buf, tmp);
                    printf("'%s' '%s'\n", tmp, buf);
                    strcat(compl, buf);
                }
            else if(i>5)
                {
                    printf("Oopsie!\n");
                }
        }
    printf("\n\nCOMPL: \"%s\"\n\n", compl); // <-- On WSL Debian 10.4 there seemd to be a bug in LEVL where it spits out 5 million something. pls fix.
    write2(SVF, compl);
    free(compl);
    return 0;
}
