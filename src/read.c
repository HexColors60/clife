//--TRANSLATED 100%--//

#include "read.h"

int readConfig(const char *fpath, struct DATA *data) {
    printf("Hey, you loaded!\n");
    FILE *f;
    f = fopen(fpath, "r");
    if(f==NULL)
    {
        printf("ERROR: File %s doesn't exist!CODE: 1\n", fpath);
       return 1;
    }
    const size_t line_size = 300;
    char *line = malloc(sizeof(char)*line_size);
    if(line==NULL) { printf("ERROR: Pointer 'line' not allocated!\n");
      return 1;
    }
    char *ptr   = line;
    char *KEY   = malloc(line_size);
    char *VALUE = malloc(line_size);

    while(fgets(line, line_size, f) != NULL)
    {
        memset(KEY,   '\0', sizeof(char) * line_size);
        memset(VALUE, '\0', sizeof(char) * line_size);
        int counter = 0;
        int result  = -1;
        for(int i = 0; i < line_size; ++i)
        {
            if(line[i]=='=')
            {
                result = i;
                break;
            }
        }
        if(result == -1)
        {
            printf("Didn't locate '=' sign!\n");
            free(ptr);
            free(KEY);
            free(VALUE);
            return 1;
        }

        int whitespace = 0;
        for(int i = 0; i < result; ++i) {
            if(line[i]==' ') {
                printf("Found a whitespace!\n");
                whitespace = 1;
                break;
            }
            KEY[i] = line[i]; // Don't add whitespaces into the key
        }
        if(whitespace==1) {
            fputs("Found a whitespace in the configuration file!\n", stdout);
            fputs("Please check arch/svf/svf.rtf and remove any whitespaces!\n", stdout);
            free(ptr);
            free(KEY);
            free(VALUE);
          return 2;
        }

        // trim off CR-NL
        for (int i = 0; i < line_size; ++i)
        {
            if ((line[i] == '\r') || (line[i] == '\n'))
            {
                line[i] = '\0';
            }
        }

        for (int i = result + 1, j =0; i < line_size; ++i, ++j)
        {
            VALUE[j] = line[i];
        }

        if(!strcmp(KEY,"GOLD"))
        {
            printf("Okay, we are in the Gold currently.\n");
            int goldInt = atoi(VALUE);
            if(goldInt<=-1) { // If gold is below 0, set it to 0
                printf("Re-setting Gold!\n");
                goldInt = 0;
            }
            data->gold = goldInt; // <-- halp
        }
        else if(!strcmp(KEY,"LOCA"))
        {
            printf("Okay, we are in the Location currently.\n");
            strcpy(data->loca, VALUE);
        }
        else if(!strcmp(KEY,"MOTI"))
        {
            //printf("ptr: %s line: %s\n", ptr, line); // <-- Unexpected behavior here.
            printf("Okay, we are in the Motivation currently.\n");
            int moti = atoi(VALUE);
            data->moti = moti; // <-- halp
        }
        else if(!strcmp(KEY,"NAME"))
        {
            printf("Okay, we are in the Name currently.\n");
            strcpy(data->name, VALUE);
        }
        else if(!strcmp(KEY,"ROLE"))
        {
            printf("Okay, we are in the Role currently.\n");
            strcpy(data->role, VALUE);
        }
        else
        { // Big error :(
            printf("OH NO! OH GOD NO! RUN IN CIRCLES! RUN IN CIRCLES! WE HAVE AN ERROR!\n");
        }

        printf("Key: %s, Value: %s\n", KEY, VALUE);
        memset(line,   0, sizeof(char) * line_size);
        printf("\n");
    }

    free(KEY);
    free(VALUE);
    free(ptr);
    return 0;
}

char *cL_readWholeFile(const char *fpath, char *buf) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) {
    printf("ERROR: File %s doesn't exist!CODE: 0\n", fpath);
    return "";
  }
  const size_t line_size = 300;
  char *line = malloc(line_size);
  int counter = 0;
  while(fgets(line, line_size, f) != NULL) { strcat(buf, line); }
  free(line);
  return buf;
}

char *cL_read(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!CODE: 1\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f) != NULL) {}
  return line;
}
char *cL_pread(const char *fpath) {
  FILE *f;
  f = fopen(fpath, "r");
  if(f==NULL) { printf("ERROR: File %s doesn't exist!CODE 2\n", fpath);
    return ""; }
  const size_t line_size = 300;
  char *buf;
  char *line = malloc(line_size);
  while(fgets(line, line_size, f)!=NULL) { printf("%s", line);
  }
  free(line);
  return "";
}
