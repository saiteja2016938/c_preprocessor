#include "header.h"

char* remove_sl_comment(char *ptr)
{
        int i;
         for(i=0;ptr[i];i++)
         {
		 if(ptr[i]==34)
		 {
			 while(ptr[++i]!=34);
		 }

            if(ptr[i]=='/'&&ptr[i+1]=='/')
            {
                    int k,cmt_len=0;
                    for(k=i;ptr[k]!='\n'||'\0';k++)
                    {
                                cmt_len++;
                    }
                    memmove(ptr+i,ptr+i+cmt_len,strlen(ptr+i+cmt_len)+1);
                    ptr=realloc(ptr,(strlen(ptr)+1));

            }
           
         }


	 return ptr;

}

char* remove_ml_comment(char *ptr)
{

        int i,cmt_len,k;

        for(i=0;ptr[i];i++)
        {
		if(ptr[i]==34)
		{
			while(ptr[++i]!=34);
		}

                if(ptr[i]=='/' && ptr[i+1]=='*')
                {

                         k=i;
                         cmt_len=0;

                         while(ptr[k]!='\0' && !((ptr[k]=='*')&&(ptr[k+1])=='/'))
                        {
                                cmt_len++;
                                k++;
                        }
                        cmt_len+=2;

                       memmove(ptr+i,ptr+i+cmt_len,strlen(ptr+i+cmt_len)+1);
                      ptr=realloc(ptr,(strlen(ptr)+1));

                      i--;
                }


        }


        return ptr;

}


