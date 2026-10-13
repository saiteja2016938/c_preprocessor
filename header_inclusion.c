#include "header.h"
FILE *newptr=NULL,*headptr=NULL;

char* remove_header(char* heap)
{
	char *ptr=heap,*found=NULL;
	int i,cnt_len=0,len=0;

	for(i=0;ptr[i];i++)
	{
		
		if(ptr[i]=='#' && ptr[i+1]=='i')
		{
	        if(strstr(ptr+i,"#include"))
		{
	          int k;
	          cnt_len=0;
	          for(k=i ;ptr[k]!='>';k++)
		  {
			  cnt_len++;
		  }
		  cnt_len++;
		  len+=cnt_len;
		  memmove(ptr+i,ptr+i+cnt_len,strlen(ptr+i+cnt_len));
		  i--;
		   
		}

		}

	}

	char *end=heap+(strlen(heap)-len);
	  //end=end+1;
	  *end='\0';


	return heap;
}


void copy_header(char* buffer)
{
	char header_path[100]="/usr/include/";
        strcat(header_path,buffer);	
	if(flag==0)
	{
          newptr = fopen(str,"w");
	  flag=1;
	}else
	{
	   newptr=fopen(str,"a");
	}

    if(newptr==NULL)
    {
	    printf("failed to open header file");
	    exit(0);

    }

  headptr = fopen(header_path,"r");

 if(headptr == NULL )
 {
	 printf("failed to open ");
	 exit(0);
 }
 int n;
 char buff[99];

 while((n = fread(buff,1,sizeof(buff),headptr))>0)
 {
	  fwrite(buff,1,n,newptr);
 }
 fclose(headptr);
 fclose(newptr);

}



	
void  header_inclusion(char *ptr)
{
	
	char *found=NULL, buffer[100], *tmp=NULL,*end=NULL;
	int i;
	tmp=buffer;
	if(ptr==NULL)
	{
		printf("ptr NULL");
		exit(0);
	}

	found = strstr(ptr,"#include<");
	if(found!=NULL)
	{
	while(found!=NULL)
	{
		
	found = found + 9;
	 while(*found && *found!='>')
	 {
		 *tmp = *found;
		 found++;
		 tmp++;
	 }
	 *tmp='\0';
	 puts(buffer);
	 copy_header(buffer);

	 if(*found=='>')
	 found++;


	 found = strstr(found,"#include<");
         tmp=buffer;
	}

	}

}



