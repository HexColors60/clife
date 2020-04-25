//--TRANSLATED 100%--//

#include "travel.h"

int elaMotivatio(int mot) {
    static int elaMoti;
    if(mot!=101) { /* printf("Set Motivation to %d!\n", mot); */ elaMoti = mot; } // Calling with mot = 101, writing with anything else
    return elaMoti;
}

char *travelCountry(char *l, char *p) {
    printf("What country do you want to travel to?\n");
    printf("From %s you can go to:\n", p);
    if(!strcmp(p, "Aritrea")) printf("Liberium\n");
    if(!strcmp(p, "Liberium")) printf("Aritrea\n");
    char *buf = (char*)malloc(128 * sizeof(char));
    fgets(buf, 127, stdin);
    strtok(buf, "\n");
    if(!strcmp(p, "Aritrea")) {
        if(!strcmp(buf, "Liberium")) {
            if(!strcmp(l,"Metron")) {
                printf("You travel to %s.\n", buf);
                p = buf;
                return buf;
            } else {
                printf("Metron is the only way to Liberium.\n");
                free(buf);
                return "nowhere";
            }
        } else {
            if(!strcmp(buf, p)) {
                printf("You don't move an inch.\n");
                free(buf);
                return "nowhere";
            }
        }
    }
    if(!strcmp(p, "Liberium")) {
        if(!strcmp(buf, "Aritrea")) {
            if(!strcmp(l, "Orar")) {
                printf("You travel to %s.\n", buf);
                p = buf;
                return buf;
            } else {
                printf("Orar is the only way to Aritrea.\n");
                free(buf);
                return "nowhere";
            }
        } else {
            if(!strcmp(buf, p)) {
                printf("You don't move an inch.\n");
                free(buf);
                return "nowhere";
            }
        }
    }
    else { printf("This is No Man's Land!\n");
        free(buf);
        return "nowhere"; }
    free(buf);
}

char *ganz_reisen(char *l, char *p, int Motivation, int Gold) {
    if(Gold<30) {
        printf("You can't pay the toll, so you can't travel!\n");
        return l;
    }
    p = travelCountry(l, p);
    if(!strcmp(p, "Liberium")) l = "Orar"; // Player always travels to capital.
    if(!strcmp(p, "Aritrea")) l = "Majkius";
    if(!strcmp(p, "nowhere")) l = l; // Player stays where he is.
    if(strcmp(p,"nowhere")) {
        printf("You are extremely unmotivated from travelling. You should sleep.\n");
        Motivation = 0;
        /* if(Motivation>=35) Motivation = 35; */
        /* printf("Trying to set Motivation..\n"); */
        elaMotivatio(Motivation);
        /* wrinte2(MOTI, Motivation); */
    }
    return l;
}
