# ifndef __CLIFE_READ_H__
# define __CLIFE_READ_H__
//--TRANSLATED 100%--//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "structs.h"

char *cL_read(const char *fpath);

char *cL_pread(const char *fpath);

char *cL_readWholeFile(const char *fpath, char *buf);

int proto_readConfig(const char *fpath, struct DATA *data);

int readConfig(const char *fpath, int g, char *l, int m, char *n, char *r);  // config path file, gold, location, motivation, name, role

char *cL_readWholeFile(const char *fpath, char *buf);

char *cL_read(const char *fpath);

char *cL_pread(const char *fpath);

# endif
