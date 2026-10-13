#include "header.h"

char *read_file(FILE* fptr)
{
        char ch;
        char *ptr=NULL;


        while((ch=fgetc(fptr))!=EOF)
        {

                ptr=realloc(ptr,(cnt+1)*sizeof(*ptr));

                ptr[cnt]=ch;
                cnt++;

        }

        return ptr;


}


