struct DATA {
  int data1;
  int blah;
};

struct o {
  int gold;
  char *loc;
  int mot;
} old;

struct city {
  char *name;
  char *buildings[12];
  char key[12];
} Majkius, NovaA, Metron, Orar;
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

void detStruct(char *location, char *country, int la) { // la = lookAround? <- determines if the command is lookAround or inspectDialog
  if(!strcmp(country,"Aritrea")) {
    if(!strcmp(location,"Majkius")) if(la==1) lookAround(location, country, Majkius.buildings); else inspectDialog(location, country, Majkius.buildings, Majkius.key);
    if(!strcmp(location,"Nova A")) if(la==1) lookAround(location, country, NovaA.buildings); else inspectDialog(location, country, NovaA.buildings, NovaA.key);
    if(!strcmp(location,"Metron")) if(la==1) lookAround(location, country, Metron.buildings); else inspectDialog(location, country, Metron.buildings, Metron.key);
  }
  if(!strcmp(country,"Liberium")) {
    if(!strcmp(location,"Orar")) if(la==1) lookAround(location, country, Orar.buildings); else inspectDialog(location, country, Orar.buildings, Orar.key);
  }
  return;
}


// Keymap
/* a - Center of a city
   r - Religious Building
*/
