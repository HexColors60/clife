# ifndef __CLIFE_ARB_H__
# define __CLIFE_ARB_H__
//--TRANSLATED 100%--//

# include <stdbool.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

char *workt;
char *arbst;
int ranint;
int ngold;

int generate(int start, int end); // Fix the confusing rand() syntax

bool workMinigame(char *type);

int arb_addMoney(int algel, int lohn);  // New Gold = Old Gold + Salary

bool chooseWork(char *loca);

int work(int algold, char *loca);

int beg(int algold);

# endif
