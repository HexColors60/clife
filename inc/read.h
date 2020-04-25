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

int readConfig(const char *fpath, struct DATA *data);

char *cL_readWholeFile(const char *fpath, char *buf);

char *cL_read(const char *fpath);

char *cL_pread(const char *fpath);

# endif
