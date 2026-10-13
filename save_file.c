#include "header.h"
void save_file(char* ptr)
{
          int i;

        FILE* p=NULL;

        p=fopen(str,"w");

        if(p==NULL)
        {
                printf("failed to create file");

        }


        fputs(ptr,p);

        fclose(p);

}

