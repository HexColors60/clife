#include<stdio.h>
#include<string.h>
#define PRD "arch/locs/shop/shops.rtf"
int ngeldx;
char *products = "b[w];b[t];b[k]";
char *xd;
char *buf;
char *prodName;

void produktListe() {
  printf("Produktliste:\n");
  pread(PRD);
  printf("\n-------------\n");
}
int kaufen(char *inventar, char *produkt, int geldbeutel) {
  char *ppath = (char*)malloc(33 * sizeof(char));
  strcat(ppath, "arch/locs/shop/");
  strcat(ppath, produkt);
  strcat(ppath, ".rtf");
  int preis;
  char *buf2 = (char*)malloc(128 * sizeof(char));
  if(exists(ppath)==true) buf2 = read(ppath);
  else { printf("Das Produkt existiert nicht!\nKauf abgebrochen.");
    return 51; }
  free(ppath);
  preis = atoi(buf2);
  free(buf2);
  buf2 = (char*)malloc(16 * sizeof(char));
  printf("Kaufe %s für %d?\n(Ja/Nein) $> ", produkt, preis);
  scanf("%s", buf2);
  strtok("\n", buf2);
  if(strstr(inventar, produkt)) { printf("Du besitzt dieses Produkt schon!\n");
    return 51; }
  if(!strcmp(buf2, "Ja") | !strcmp(buf2, "ja") | !strcmp(buf2,"j")) {
    if(geldbeutel<=preis) {
      printf("Du hast nicht genug Geld um %s zu kaufen!\n", produkt);
      return 51; // 51 = Kauf nicht erfolgreich
    }
    ngeldx = geldbeutel - preis;
    printf("Neuer Geldbetrag: %d\n", ngeldx);
    wrinte2(GELD, ngeldx);
    return 50; // 50 = Kauf erfolgreich
  }
  if(!strcmp(buf2, "Nein") | !strcmp(buf2, "nein") | !strcmp(buf2,"n")) {
    printf("Kauf abgebrochen!\n");
    return 0;
  }
  else printf("Kauf abgebrochen!\n");
  free(buf2);
}
int Einkaufen(char *inventar, int geldbeutel) {
  // while(amShoppen) {
  produktListe();
  printf("Was möchtest du einkaufen?\n$> ");
  buf = (char*)malloc(16 * sizeof(char));
  scanf("%s", buf);
  strtok(buf, "\n");
  printf("%s\n", buf);
  xd = (char*)malloc(32 * sizeof(char));
  strcat(xd, "b[");
  strcat(xd, buf);
  strcat(xd, "]");
  if(strstr(products, xd)) {
    printf("In den Regalen des Ladens siehst du das Produkt.\nIn riesigen Lettern ist %s darauf gedruckt.\n", buf);
    if(kaufen(inventar, buf, geldbeutel)==50) {
      if(!strstr(inventar, buf)) {
        prodName = (char*)malloc(16 * sizeof(char));
        strcpy(prodName,"[");
        strcat(prodName,buf);
        strcat(prodName,"];");
        cat2(INV, prodName);
        free(prodName);
        free(buf);
      }
      else printf("Du hast dieses Objekt schon!\n");
    }
    geldbeutel = atoi(read(GELD));
    free(buf);
    free(xd);
    return geldbeutel;
  }
  free(buf);
  free(xd);
  // }
  // if(!amShoppen) {
  //   printf("Kauf abgebrochen.\n");
  //   return geldbeutel;
  // }
}
