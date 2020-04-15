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


// Keymap
/* a - Center of a city
   r - Religious Building
*/
