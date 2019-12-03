// UNBENUTZT // UNUSED

/*
#include<stdio.h>
char *bencp;
char *neuinv;
int omot;

void neuesInventar(char *inventar, char *benutztesObjekt) {
  neuinv = (char*)malloc(65*sizeof(char));
  if(!strcmp(benutztesObjekt,"w")) { // Falls Wasser getrunken wurde
    if(strstr(inventar,"[t];")) strcpy(neuinv,"[t];"); // Falls Tee im Inventar ist, dieses auch schreiben.
    else if(strstr(inventar,"[k];")) strcat(neuinv,"[k];"); // Falls Kaffee im Inventar ist, dieses auch schreiben.
    // Da diese Funktion nur ausgeführt wird, falls Wasser getrunken wurde, und man Objekte nicht zwei mal besitzen kann, muss dieses nicht erneut geschrieben werden.
    else {
      free(neuinv);
      write2(INV, neuinv);
      return;
    }
    printf("Neues Inventar:\n---%s\n---\n", neuinv);
    write2(INV, neuinv);
    free(neuinv);
    return;
  }

  if(!strcmp(benutztesObjekt,"t")) { // Für Tee
    if(strstr(inventar,"[w];")) strcpy(neuinv,"[w];");
    if(strstr(inventar,"[k];")) strcat(neuinv,"[k];");
    else {
      free(neuinv);
      write2(INV, neuinv);
      return;
    }
    printf("Neues Inventar:\n---%s\n---\n", neuinv);
    write2(INV, neuinv);
    free(neuinv);
    return;
  }
}

void benutzen(char *inventar, char *objekt, int moti) {
  /* neuinv = (char*)malloc(65 * sizeof(char)); */
  /* strcpy(neuinv, inventar); */
  if(!strcmp(objekt,"w")) {
    printf("Du trinkst Wasser!\n");
    moti = moti + 15; // Motivation wird um 15% geheilt
    if(moti>100) moti = 100;
    wrinte2(MOTI, moti);
    /* strtok(neuinv,"[w];"); */
    /* printf("Inventar: \n---%s\n---", neuinv); */
    neuesInventar(inventar, objekt);
    return;
  }
  if(!strcmp(objekt,"t")) {
    printf("Du trinkst Tee!\n");
    moti = moti + 20; // Motivation wird zu 20% geheilt
    if(moti>100) moti = 100;
    wrinte2(MOTI, moti);
    neuesInventar(inventar, objekt);
    return;
  }
  if(!strcmp(objekt,"k")) {
    printf("Du trinkst Kaffee!\n");
    moti = 100;
    wrinte2(MOTI, moti);
    /* strtok(neuinv,"[k];"); */
    return;
  }
}
void benAuswahl(char *inventar) {
  printf("Was möchtest du haben?\nInventar:\n");
  if(strstr(inventar,"[w];")) printf("w - Wasser\n");
  if(strstr(inventar,"[t];")) printf("t - Tee\n");
  if(strstr(inventar,"[k];")) printf("k - Kaffee\n");
  bencp = (char*)malloc(16 * sizeof(char));
  fgets(bencp, 15, stdin);
  strtok(bencp,"\n");
  if(!strstr(inventar,bencp)) { printf("Du besitzt das Objekt nicht!\n");
    return; }
  omot = atoi(read(MOTI));
  free(bencp);
  benutzen(inventar, bencp, omot);
  // free(neuinv);
  return;
}
*/
