//--TRANSLATED 15%--//

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
    struct DATA data;
    /* struct DATA *dptr = &data; */
    if(exists(SVF)==true) if(readConfig(SVF, &data)==2) return 0;

    begSequence(&data);

    print_DATA(&data);
  
    /* return 0; */
    /* readConfig("arch/svf/svf.rtf", gold, loc, motivation, name, role); */
    /* return 0; */
    name = data.name;
    role = data.role;
    gold = data.gold;
    loc = data.loca;
    motivation = data.moti;
    /* name = cL_read(NAME); */
    /* role = cL_read(ROLE); */
    /* gold = atoi(cL_read(GOLD)); */
    /* loc = cL_read(POSI); */
    /* motivation = atoi(cL_read(MOTI)); */
    old.gold = gold;
    old.loc = loc;
    old.mot = motivation;
    /* name[strcspn(name, "\n")] = 0;   // remove \n */
    /* role[strcspn(role, "\n")] = 0; // remove \n */
    printf("You are %s, the %s.\n", name, role);
    moneyc(gold);
    country = getCountry(loc);
    printMap(loc, country);
    printf("\n");
    setAll(); // set all structs
    for(;;) { // Loop until cexit()==0
        
        if(motivation<=0) { printf("%s", unMotivated);
            motivation = 0; }
        if(motivation>=101) motivation = 100;
        
        normalInput(input);
        
        action = checkForReaction(action);

        if(!strcmp(input,";help") | !strcmp(input,";h")) printf("%s\n", comms);

        if(!strcmp(input,";gold") | !strcmp(input,";g") | !strcmp(input,";money")) moneyc(gold);

        if(!strcmp(input,";w") | !strcmp(input,";work") | !strcmp(input,";a")) { if(motivation<=0) printf("You aren't motivated enough to work.\n");
            else { gold = work(gold, loc);
                printf("Your motivation has been lowered.\n");
                motivation-=10; }
        }

        if(!strcmp(input,";beg") | !strcmp(input,";b")) { if(motivation<=0) printf("You are not motivated enough to beg.\n");
            else { gold = beg(gold);
                printf("Your motivation has been lowered.\n");
                motivation-=10; }
        }

        if(!strcmp(input,";wai")) printMap(loc, country);

        if(!strcmp(input,";ch")) printf("%s\n", country);

        if(!strcmp(input,";map")) printASCIImap(loc);

        if(!strcmp(input,";goto")) { if(motivation<=0) printf("You are not motivated enough!\n");
            else loc = geheZu(loc, country); }

        if(strstr(input,";e ")!=NULL) { action = emotion(input, action); }

        if(!strcmp(input,";r") | !strcmp(input,";travel")) {
            char *oldloc;
            oldloc = (char*)malloc(32*sizeof(char));
            strcpy(oldloc, loc);
            loc = ganz_reisen(loc, country, motivation, gold); // Travel from gateway city to capital of country.
            if(strcmp(oldloc, loc)) // If player does have the money to pay the toll.
                {
                    motivation = elaMotivatio(101); // The argument 101 reads the motivation, anything else writes it.
                    if(strcmp(country,getCountry(loc))) { printf("You had to pay 30 gold coins as a toll!\n");
                        gold = removeMoney(gold, 30); }
                    country = getCountry(loc); // Also we have to get the country using the city we now have.
                }

            free(oldloc);
        }

        if(!strcmp(input,";motivation") | !strcmp(input,";m")) seeMotivation(motivation);

        if(!strcmp(input,";sleep") | !strcmp(input,";s")) { if(sleep(motivation)!=3) motivation = 80;
            else motivation-=10; }
        /* else motivation = motivation - 10; } */

        if(!strcmp(input,";servus") | !strcmp(input,";tschüß") | !strcmp(input,";tschüs") | !strcmp(input,";quit") | !strcmp(input,";q")) if(cexit()==0) return 0;

        // DEBUG TOOLS; WILL BE REMOVED OR BUILT IN SOON
        if(!strcmp(input, ";dungeon")) detStruct(loc, country, 2);
        if(!strcmp(input, ";umsehen")) detStruct(loc, country, 0);
        if(!strcmp(input, ";de")) detStruct(loc, country, 1);
        if(!strcmp(input, ";printf")) EchoThing();
    }
}

int cexit() {
    printf("Arheto, %s, the %s!\n", name, role); // "Arheto" means "Goodbye" in Aritrean.
    /* wrtSvf(SVF, data); */
    if(exists(SVF)==false || old.gold!=gold || strcmp(old.loc,loc) || old.mot!=motivation) wrtSvf(SVF);
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
        printf("%s\n", echo);
        if(echo[0]=='q' && echo[1]=='u' && echo[2]=='i' && echo[3]=='t'&& echo[4]=='\0') { printf("Quitting.\n"); return; }
        if(echo[0]=='g') printf("%d\n", gold);
        if(echo[0]=='l') printf("%s\n", loc);
        if(echo[0]=='c') printf("%s\n", getCountry(loc));
        if(echo[0]=='m') printf("%d\n", motivation);
        else continue;
    }
}

int wrtSvf(const char *fpath)
{
    char buf[300];
    char *compl;
    compl = (char*)malloc(512*sizeof(char));
    for(int i=0; i<5; ++i)
        {
            if(i==0) // Gold
                {
                    char tmp[16];
                    sprintf(tmp, "%d", gold);
                    strcpy(buf, "GOLD=");
                    strcat(buf, tmp);
                    strcat(buf, "\n");
                    printf("'%s' '%s'\n", tmp, buf);
                    strcpy(compl, buf);
                }
            if(i==1) // Location
                {
                    strcpy(buf, "LOCA=");
                    strcat(buf, loc);
                    strcat(buf, "\n");
                    printf("'%s'\n", buf);
                    strcat(compl, buf);
                }
            if(i==2) // Motivation
                {
                    char tmp[4];
                    sprintf(tmp, "%d", motivation);
                    strcpy(buf, "MOTI=");
                    strcat(buf, tmp);
                    strcat(buf, "\n");
                    printf("'%s' '%s'\n", tmp, buf);
                    strcat(compl, buf);
                }
            if(i==3) // Name
                {
                    strcpy(buf, "NAME=");
                    strcat(buf, name);
                    strcat(buf, "\n");
                    printf("'%s'\n", buf);
                    strcat(compl, buf);
                }
            if(i==4) // Role
                {
                    strcpy(buf, "ROLE=");
                    strcat(buf, role);
                    printf("'%s'", buf);
                    strcat(compl, buf);
                }
            else if(i>4)
                {
                    printf("Oopsie!\n");
                }
        }
    printf("\n\nCOMPL: \"%s\"\n\n", compl);
    write2(SVF, compl);
    free(compl);
    return 0;
}
