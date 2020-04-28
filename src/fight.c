// Fighting

# include "fight.h"

const char *Fcomms = "Fighting commands\n\
┌─────────────────────────────────┐\n\
│ atk, attack   : attack          │\n\
│ flee          : flee the battle │\n\
└─────────────────────────────────┘\n"; // This will make compilation impossible if it stands in fight.h

int Fattack(struct HUMANOID *enemy, struct HUMANOID *player) {
    printf("ATTACKING!\n\n");
    int ranint = 0;
    ranint = rand() % 2 + 1;
    if(ranint==1) // Player begins
        {
            printf("The goblin seems to be distracted. You use your chance and curse him!\n");
            int dmg = rand() % player->ATK[1] + player->ATK[0];
            enemy->health -= dmg;
        }
    if(ranint==2) // Enemy begins
        {
            printf("You were incautious and got hit!\n");
            int dmg = rand() % enemy->ATK[1] + enemy->ATK[0];
            player->health -= dmg;
        }

    /* printf("ENEMY: %d/%d\nPLAYER: %d/%d\n", enemy->health, enemy->maxHP, player->health, player->maxHP); */
    return 0;
}

int Fencounter() {
    srand(time(NULL));
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
        printf("\nIt's round %d\n\nSTATS:\nENEMY HP: %d/%d\nYOUR HP: %d/%d\n\n", Fround, enemy.health, enemy.maxHP, player.health, player.maxHP);
        printf("FIGHT> ");
        fgets(Finput, 32, stdin);
        Finput[strcspn(Finput, "\n")] = 0;
        fflush(stdin);
        printf("You entered: %s\n", Finput);

        if(!strcmp(Finput, "help")) printf("%s\n", Fcomms);
        /* if(!strcmp(Finput, "help")) printf("%s\n", "Fighting commands\natk, attack   : attack\nflee          : flee the battle\n"); */
        if(!strcmp(Finput, "a") | !strcmp(Finput, "atk") | !strcmp(Finput, "attack")) { Fattack(&enemy, &player); }
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
        printf("-----------------------------------\n");
    }
    
}
