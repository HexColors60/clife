#include "structs.h"
# include "dungeon.h"

void setAll() { // Get rid of reading dozens of files and replace it with a nice struct
    Majkius.name = "Majkius";
    Majkius.buildings[0] = "Church";
    Majkius.key[0] = 'r';

    NovaA.name = "NovaA";
    NovaA.buildings[0] = "Plateau";
    NovaA.key[0] = 'a';

    Metron.name = "Metron";

    Orar.name = "Orar";
}

void detStruct(char *location, char *country, int Sswitch, struct DATA *data, struct DATA *plr) {
    /* Sswitch map
     * 0 = lookAround
     * 1 = inspectDialog
     * 2 = dungeonHead
     */
    printf("Calling detStruct\n");
    printf("Sswitch: %d\n", Sswitch);
    if(!strcmp(country,"Aritrea")) {
        if(!strcmp(location,"Majkius")) if(Sswitch==0) lookAround(location, country, Majkius.buildings); else if(Sswitch==1) inspectDialog(location, country, Majkius.buildings, Majkius.key); else if(Sswitch==2) data->gold += dungeonHead(&Majkius, plr);
        if(!strcmp(location,"Nova A")) if(Sswitch==0) lookAround(location, country, NovaA.buildings); else if(Sswitch==1) inspectDialog(location, country, NovaA.buildings, NovaA.key); else if(Sswitch==2) data->gold += dungeonHead(&NovaA, plr);
        if(!strcmp(location,"Metron")) if(Sswitch==0) lookAround(location, country, Metron.buildings); else if(Sswitch==1) inspectDialog(location, country, Metron.buildings, Metron.key); else if(Sswitch==2) data->gold += dungeonHead(&Metron, plr);
    }
    if(!strcmp(country,"Liberium")) {
        if(!strcmp(location,"Orar")) if(Sswitch==0) lookAround(location, country, Orar.buildings); else if(Sswitch==1) inspectDialog(location, country, Orar.buildings, Orar.key); else if(Sswitch==2) data->gold += dungeonHead(&Orar, plr);
    }
    return;
}
void detStruct_plr(struct DATA *plr, int Sswitch) {
    printf("Calling detStruct\n");
    char *ch = getCountry(plr->loca);
    if(!strcmp(ch,"Aritrea"))
        {
            if(!strcmp(plr->loca,"Majkius"))
                {
                    dungeonHead(&Majkius, plr);
                }
        }
}

int checkLevel(int level, int xp) {
    if(level<=10)
        {
            if(xp>=25)
                return 1;
        }
    
    else
        {
            if(xp>=(level*10))
                return 1;
        }

    return 0;
}

// Keymap
/* a - Center of a city
   r - Religious Building
*/
