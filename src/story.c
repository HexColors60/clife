//--TRANSLATED 100%--//

#include "story.h"

char welcome[18]    = "Welcome to CLIfe!";
char pleaseName[24] = "Please enter your name!"; // I add +1 to the length of the string in case C wants to add another byte to it.
char yourName[80]   = "Your name is: ";
char roleSelect[25] = "Please select your role.";

const char *title1 = " #####  #       ###               \n\
#     # #        #  ###### ###### \n\
#       #        #  #      #      \n\
#       #        #  #####  #####  \n\
#     # #        #  #      #      \n\
 #####  ####### ### #      ######\n";

const char *title2 = "+--------+--------+--------+--------+--------+\n\
|01000011|01001100|01001001|01100110|01100101|\n\
+--------+--------+--------+--------+--------+\n";

const char *title3 = "+--+--+--+--+--+\n\
|43|4c|49|66|65|\n\
+--+--+--+--+--+\n";

const char *title4 = "+-+-+-+-+-+\n\
|C|L|I|f|e|\n\
+-+-+-+-+-+\n";

const char *title5 = "+---+---+---+---+---+\n\
|067|076|073|102|101|\n\
+---+---+---+---+---+\n";

const char *title6 = "/siː laɪf/\n";

void begSequence(struct DATA *d) {
    srand(time(NULL));
    int ranint = rand() % 6 + 1;
    switch(ranint) {
    case 1:
        printf("%s\n", title1);
        break;
    case 2:
        printf("%s\n", title2);
        break;
    case 3:
        printf("%s\n", title3);
        break;
    case 4:
        printf("%s\n", title4);
        break;
    case 5:
        printf("%s\n", title5);
        break;
    case 6:
        printf("%s\n", title6);
        break;
    }
    if(exists(SVF)==false)
        {
            getName(d);
            printf("NAME: %s\n", d->name);
            getRole(d);
            printf("ROLE: %s\n", d->role);
            /* strcpy(d->name, getName(&data)); */
            /* d->name = getName(); */
            /* strcpy(d->role, getRole()); */
            /* d->role = getRole(); */
            printStory(d->role);
            d->gold = 0;
            strcpy(d->loca, "Majkius");
            /* d->loca = "Majkius"; */
            d->moti = 100;
            /* setGold(); */
            /* setPos(); */
            /* setMot(); */
        }
}

void printStory(char *role) {
    printf("┌");
    for(int i=0;i<71;i++) {
        printf("─");
    }
    printf("┐\n");
    printf("│                                                                       │░\r Well, %s... I can see a glorious Future for you.      \r│\n", role);
    printf("│                                                                       │░\r  You will go a long road, and experience certain pain.                \r│\n");
    printf("│                                                                       │░\n");
    printf("│                                                                       │░\r But it is important that you give me the secret of Ko'hdor.        \r│\n");
    printf("│                                                                       │░\r  Nobody may ever receive it.           \r│\n");
    printf("│                                                                       │░\n");
    printf("│                                                                       │░\r You ask what it is? Well...                     \r│\n");
    printf("│                                                                       │░\r  Some secrets are best kept so.                              \r│\n");
    printf("└");
    for(int i=0;i<71;i++) {
        printf("─");
    }
    printf("┘░\n ");
    for(int i=0; i<73;i++) {
        printf("░");
    }
    printf("\n\n");
    return;
}



char *getRole(struct DATA *data) {
    char *choices[3] = {"Rogue", "Knight", "Mage"};
    int choice;
    int highlight = 0;

    printf("%d\n", 3); // 3 = size of choices

    // Start ncurses
    initscr();
    noecho();
    cbreak();

    int yMax, xMax;
    getmaxyx(stdscr, yMax, xMax);

    yMax-=2;
    xMax-=2;

    box(stdscr, 0, 0);
    refresh();

    move(1, ((xMax/2) - (strlen(roleSelect)/2)));
    printw("%s", roleSelect);

    WINDOW *menuwin = newwin((3+2), xMax, (yMax-4), 1); // Create menu window // 3 = size of choices
    refresh();
    box(menuwin, 0, 0);
    wrefresh(menuwin);

    // Enable arrow keys
    keypad(menuwin, true);

    while(1) {
        for(int i=0; i<3; ++i) { // 3 = size of choices
            if(i==highlight) {
                wattron(menuwin, A_REVERSE);
            }
            wmove(menuwin, i+1, 1);
            wprintw(menuwin, choices[i]);
            /* mvwprintw(menuwin, i+1, 1, choices[i]); */
            wattroff(menuwin, A_REVERSE);
        }
        choice = wgetch(menuwin);

        switch(choice) {
        case KEY_UP:
            if(highlight==0) { highlight = 2; break; }
            highlight--;
            break;
        case KEY_DOWN:
            if(highlight==2) { highlight = 0; break; }
            highlight++;
            break;
        default:
            break;
        }
        if(choice==10) {
            break;
        }
    }

    endwin();

    char *role;

    switch(highlight) {
    case 0: // Rogue
        role = "Rogue";
        break;
    case 1: // Knight
        role = "Knight";
        break;
    case 2: // Mage
        role = "Mage";
        break;
    }

    printf("You chose: %s\n", role);
    strcpy(data->role, role);
    return "";
}

char *getName(struct DATA *data) {
    char inputNom[64]; // The string the name is saved in
    int rows, cols; // This is actually unnecessary... Oops!

    printf("Going into ncurses...\n");
    initscr(); // Begin ncurses
    cbreak(); // Allow ncurses to be exited with CTRL+C

    int yMax, xMax; // Height and width (rows and columns) of Terminal
    getmaxyx(stdscr, yMax, xMax); // Get the height and width

    box(stdscr, 0, 0); // Make a fancy box on the terminal
    refresh(); // Make the box appear

    yMax-=2; // The border makes the free room to play
    xMax-=2; // in smaller.

    move(1, ((xMax/2) - (strlen(welcome)/2))); // Centers Text :)
    printw("%s", welcome);
    move(2, ((xMax/2) - (strlen(pleaseName)/2))); // Move to position y:2 x:1 in the terminal, to enter string
    printw("%s", pleaseName);



    WINDOW *inputwin = newwin(3, xMax, (yMax-3), 1);
    refresh();
    box(inputwin, 0, 0);
    wrefresh(inputwin);

    mvwprintw(inputwin, 1, 1, "I am ");

    wgetstr(inputwin, inputNom);

    for(int i=0; i<strlen(inputNom); ++i) { // Remove Whitespaces
        if(inputNom[i]==' ') {
            inputNom[i] = '_'; // Replace ' ' with '_'
        }
    }

    strcat(yourName, inputNom);

    wborder(inputwin, ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ');
    delwin(inputwin);
    clear();
    box(stdscr, 0, 0);
    refresh();

    move(1, ((xMax/2) - (strlen(yourName)/2)));
    printw("%s", yourName);

    getch();
    endwin(); // Leave ncurses
    printf("Going out of ncurses.\n");

    printf("You entered: %s\n", inputNom);

    strcpy(data->name, inputNom);
    /* data->name = inputNom; */
    /* return *inputNom; */
    return "";
}
