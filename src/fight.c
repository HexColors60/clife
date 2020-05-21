// Fighting

# include "fight.h"

const char *Fcomms = "Fighting commands\n\
┌───────────────┬─────────────────┐\n\
│ atk, attack   │ attack          │\n\
│ flee          │ flee the battle │\n\
└───────────────┴─────────────────┘\n";

int FdetMatch(struct HUMANOID *enemy, struct HUMANOID *player, int level) {
    if(level<=5)
        {
            enemy->maxHP    = enemy->health  = 25;
            enemy->ATK[0]   = 1;
            enemy->ATK[1]   = 4;
            enemy->class    = 'k';

            player->maxHP   = player->health = 30;
            player->ATK[0]  = 2;
            player->ATK[1]  = 6;
            player->class   = 'm'; // This should be changed soon!
        }
    else
        {
            printf("Error!\n");
            enemy->maxHP    = enemy->health  = 0;
            enemy->ATK[0]   = 0;
            enemy->ATK[1]   = 0;
            enemy->class    = 'k';

            player->maxHP   = player->health = 0;
            player->ATK[0]  = 0;
            player->ATK[1]  = 0;
            player->class   = 'm'; // This should be changed soon!
        }
}

int Fattack(struct HUMANOID *enemy, struct HUMANOID *player) {
    /*
     * This is a very quick and incomplete attack function,
     * it definitely needs attention, for example adding of
     * the classes a player chooses, et cetera.
     */
    printf("ATTACKING!\n\n");
    int ranint = 0;
    ranint = rand() % 2 + 1;
    if(ranint==1) // Player taking initiative.
        {
            printf("The goblin seems to be distracted. You use your chance and curse him!\n");
            int crit = rand() % 5 + 1;
            if(crit==3)
                {
                    printf("You did a critical hit!\nYou dealt %d damage.\n", (player->ATK[1]+5));
                    enemy->health -= (player->ATK[1]+5);
                }
            else
                {
                    int dmg = rand() % player->ATK[1] + player->ATK[0];
                    enemy->health -= dmg;
                }
        }
    if(ranint==2) // Enemy taking initiative.
        {
            printf("You were incautious and got hit!\n");
            int dmg = rand() % enemy->ATK[1] + enemy->ATK[0];
            player->health -= dmg;
        }
    
    return 0;
}

int Fencounter(int level) {
    srand(time(NULL));
    struct HUMANOID enemy;
    struct HUMANOID player;
    FdetMatch(&enemy, &player, level);

    printf("A goblin appeared!\n");

    Fround = 0;

    printf("Waiting for command...\n");
    for(;;) {

        if(player.health<=0)
            {
                player.health = 0;
                printf("You manage to run away in the last moment.\n");
                return 0;
            }

        if(enemy.health<=0)
            {
                enemy.health = 0;
                printf("The goblin drops dead.\nGood job.\n");
                return 10;
            }
        
        Fround++;
    getInp:printf("\nIt's round %d\n\nSTATS:\nENEMY HP: %d/%d\nYOUR HP: %d/%d\n\n", Fround, enemy.health, enemy.maxHP, player.health, player.maxHP);
        printf("FIGHT> ");
        fgets(Finput, 32, stdin);
        Finput[strcspn(Finput, "\n")] = 0;
        fflush(stdin);
        printf("You entered: %s\n", Finput);

        if(!strcmp(Finput, "help")) { printf("%s\n", Fcomms); goto getInp; }
        
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

        if(strcmp(Finput, "a") && strcmp(Finput, "atk") && strcmp(Finput, "attack"))
            {
                int ranint = 0;
                ranint = rand() % 4 + 1;
                
                if(ranint==3)
                    {
                        int dmg = 2;
                        printf("You got hit by the goblin and lost %d health points!\n", dmg);
                        player.health -= dmg;
                    }
            }
        
        printf("-----------------------------------\n");
    }
    
}
