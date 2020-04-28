// Fighting

# include "fight.h"

int Fencounter() {
    struct HUMANOID enemy;
    struct HUMANOID player;
    enemy.maxHP   = enemy.health = 100;
    enemy.ATK[0]  = 1; // Minimal attack
    enemy.ATK[1]  = 4; // Maximal attack
    enemy.class   = 'k'; // r = Rogue, k = Knight, m = Mage
    player.maxHP  = player.health = 100;
    player.ATK[0] = 1;
    player.ATK[1] = 6;
    player.class  = 'm';

    printf("A goblin appeared!\n");

    Fround = 0;

    printf("Waiting for command...\n");
    for(;;) {
        Fround++;
        printf("\nIt's round %d\n\n", Fround);
        printf("FIGHT> ");
        fgets(Finput, 32, stdin);
        Finput[strcspn(Finput, "\n")] = 0;
        fflush(stdin);
        printf("You entered: %s\n", Finput);

        if(!strcmp(Finput, "flee"))
            {
                if(Fround<=3)
                    {
                        printf("You sheepishly fled.\n");
                        return 0;
                    }
                else
                    {
                        printf("It is too late to flee now!\n");
                        continue;
                    }
            }
    }
    
}
