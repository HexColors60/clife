//--TRANSLATED 100%--//

#include "arb.h"

int generate(int start, int end) { // Fix the confusing rand() syntax
    ranint = rand() % end + start;
    return ranint;
}

bool workMinigame(char *type) {
    if(!strcmp(type,"newspaper")) {
        ranint = generate(1,2);

        if(ranint==1) {
            int sentence = generate(1,2);
            char cSentence[128] = "ju Majkius ra kapitlon traga prazidento uffas"; // Correct sentence
            char wSentence[128]; // Obfuscated Sentence
            char obfuscators[8] = ";:,.!?/"; // The obfuscators
            int offset = 0;
            /* strcpy(cSentence, "ju Majkius ra kapitlon traga prazidento uffas"); */

            if(sentence==1) { strcpy(cSentence, "ju Majkius ra kapitlon traga prazidento uffas"); }
            if(sentence==2) { strcpy(cSentence, "tar peitors re tuvil san terkol ut ghavul"); }

            arbst = (char*)malloc(129 * sizeof(char));
            printf("\nOh no! A worker hasn't done his job right and left weird characters in the sentence!\nCan you correct this Aritrean sentence?\n\n");

            for(int i=0; i<128; ++i)
                {
                    if(cSentence[i]=='\0') break;
                    if(generate(1,5)==3) printf("%c", obfuscators[generate(0,7)]);
                    printf("%c", cSentence[i]);
                }
            printf("\n");
      
            printf("Of course. The sentence is: ");
            fgets(arbst,128, stdin);
            strtok(arbst, "\n");
            fflush(stdin);
            if(strcmp(arbst,cSentence)) { // If input is not the correct sentence
                printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (You have to improve your Aritrean!\n");
                free(arbst);
                return false; // The boolean answers the question 'Was money earned?'
            } else {
                printf("You get a small salary of 50 gold coins for your work.\n");
                free(arbst);
                return true;
            }
            free(arbst);
            return false;
        }
    
        if(ranint==2) { // Replace vowels minigame
            arbst = (char*)malloc(129 * sizeof(char));
            printf("All vowels are moved by one, so a=e, e=i, i=o, o=u, and u=a!\nCan you bring the sentence in correct order again?\n\n");
            printf("ghrut tosmal prezodintun erhotriun hjatels\n\n");
            printf("Of course. The sentence is: ");
            fgets(arbst, 128, stdin);
            strtok(arbst, "\n");
            fflush(stdin);
            if(strcmp(arbst,"ghrat tismul prazidenton arhitreon hjutals")) {
                printf("trejeku supralent u tangjha arhitreon utuls pulk-effers junae! (You need to improve your Aritrean!)\n");
                free(arbst);
                return false; // No money earned
            } else {
                printf("You get a small salary of 50 gold coins for your work.\n");
                free(arbst);
                return true;
            }
            free(arbst);
            return false;
        } else { printf("Oops!\nAn error happened!\nError code: NEWSPAPER_TOO_LARGE\n"); }
    }
    if(!strcmp(type,"calculator")) { // Calculator minigame
        printf("The computing agency of Aritrea wants you to solve this calculation:\n");
        int num1 = generate(1,6);
        int num2 = generate(1,6);
        num1 = num1 * 1000;
        num1 = generate(num1,(num1+999));
        printf("%d + ", num1);
        num2 = num2 * 100;
        num2 = generate(num2,(num2+999));
        printf("%d\n\n", num2);
        int decinp; // sum
        scanf("%d", &decinp);
        if(decinp==(num1+num2)) { printf("You get a small salary of 50 gold coins for your work.\n"); return true; }
        return false;
    }
}

int arb_addMoney(int algel, int lohn) { // New Gold = Old Gold + Salary
    ngold = algel + lohn;
    return ngold;
}

bool chooseWork(char *loca) {
    srand(time(NULL));
    ranint = generate(1, 2);
    if(ranint==1) {
        if(!strcmp(loca,"Majkius")) {
            printf("You get a job offer for the regional newspaper of Majkius.\n");
            return workMinigame("newspaper"); }
    } else {
        if(strcmp(loca,"Orar")) { // This will get very bigger
            printf("You get a job offer for the computing agency of Aritrea.\n");
            return workMinigame("calculator");
        }
    }
    return false; // If the above requirements do not match
}

int work(int algold, char *loca) {
    if(chooseWork(loca)==true) {
        return arb_addMoney(algold, 50);
    } else {
        printf("There are no Jobs in this city.\n");
    }
    return ngold;
}

int beg(int algold) {
    int begSuccess = generate(1,4);
    if(begSuccess==2) {
        printf("You were given 10 Gold coins!\n");
        return arb_addMoney(algold, 10);
    }
    else {
        printf("The people ignored you.\n");
        return algold;
    }
}
