#include<stdio.h>

struct city {
  char *name;
  char *buildings[12];
  char key[12];
} Majkius, NovaA, Metron, Orar;
void setAll() {
  Majkius.name = "Majkius";
  Majkius.buildings[0] = "Church";
  Majkius.key[0] = 'r';
}


// Keymap
/* a - Center of a city
   r - Religious Building
*/
