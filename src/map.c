//--TRANSLATED 100%--//

#include "map.h"


char *getNorth(char *p) { // I have a problem with structs, so I save North and South data for every city manually. Tedious, but it works.
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
    printf("│                                          │\r│ You are in %s.\n", p);

    tmpNorth = (char*)malloc(33 * sizeof(char));
    strcpy(tmpNorth,getNorth(p));
    if(strcmp(tmpNorth,"0")) {
        printf("│                                          │\r│ North from you is %s.\n", tmpNorth);
        free(tmpNorth);
    } else free(tmpNorth);

    tmpSouth = (char*)malloc(33 * sizeof(char));
    strcpy(tmpSouth,getSouth(p));
    if(strcmp(tmpSouth,"0")) {
        printf("│                                          │\r│ South from you is %s.\n",tmpSouth);
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

char *isAWay(char *start, char *richtung) { // Bis ich eine elegantere Lösung gefunden habe, muss das hier funktionieren.
    if(!strcmp(start,"Majkius")) {
        if(!strcmp(richtung, "north")) { printf("You go north to Nova A.\n");
            return "Nova A"; }
        else if(!strcmp(richtung, "south")) { printf("You go south to Metron.\n");
            return "Metron"; }
        else { printf("We don't go there anymore.\n");
            return start; }
    }

    if(!strcmp(start, "Nova A")) {
        if(!strcmp(richtung, "south")) { printf("You go south to Majkius.\n");
            return "Majkius"; }
        else { printf("We don't go there anymore.\n");
            return start; }
    }

    if(!strcmp(start, "Metron")) {
        if(!strcmp(richtung, "north")) { printf("You go north to Majkius.\n");
            return "Majkius"; }
        else { printf("We don't go there anymore.\n");
            return start; }
    }

    if(!strcmp(start, "Orar")) {
        printf("We don't go there anymore.\n");
        return start;
    }
}

char *geheZu(char *p, char *l) {
    printMap(p, l);
    printf("In what direction do you want to go?\nThey are written like so:\nnorth\neast\nsouth\nwest\n\n");
    minput = (char*)malloc(129 * sizeof(char));
    fgets(minput, 128, stdin);
    strtok(minput, "\n");
    fflush(stdin);
    if(!strcmp(p, "Majkius") | !strcmp(p, "Nova A") | !strcmp(p, "Metron") | !strcmp(p, "Orar")) p = isAWay(p, minput);
    free(minput);
    return p;
}
char *getCountry(char *p) {
    if(!strcmp(p, "Nova A")) return "Aritrea";
    if(!strcmp(p, "Majkius")) return "Aritrea";
    if(!strcmp(p, "Metron")) return "Aritrea";
    if(!strcmp(p, "Orar")) return "Liberium";
}
