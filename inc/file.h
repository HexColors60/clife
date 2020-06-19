# ifndef __CLIFE_FILE_H__
# define __CLIFE_FILE_H__
//--TRANSLATED 100%--//

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool exists(const char *fpath);

void write2(const char *fpath, const char *message);

void wrinte2(const char *fpath, int inte);

void appende2(const char *fpath, int inte);

void cat2(const char *fpath, const char *message);

# endif
