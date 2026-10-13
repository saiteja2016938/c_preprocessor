#include "header.h"

char *find_macro(char* heap)
{	printf("entered find macro\n");
  
	char *ptr=heap;
	char MAC_buff[100],VAL_buff[100];
        int i,j,k,mac_len=0,val_len=0; 
	for(i=0;ptr[i];i++)
	{
		if(ptr[i]=='#' && ptr[i+1]=='d')
		{
			printf("enterded #\n");
			if(strstr(ptr+i,"#define "))
			{
				printf("entered #def\n");
					;
			     mac_len=0,val_len=0;
			     for(k=i+8;ptr[k]!=32;k++)
			     {
			          MAC_buff[mac_len]=ptr[k];
				  mac_len++;
			     }
			     MAC_buff[mac_len]='\0';

			     for(j=k;ptr[j]!='\n';j++)
			     {

		                  VAL_buff[val_len]=ptr[j];
				  val_len++;
			     }
			     VAL_buff[val_len]='\0';
			     printf("mac_buf:");
			     puts(MAC_buff);
			     printf("\n");
			     printf("val_buf");
			     puts(VAL_buff);
			     replace_macro(ptr+i+mac_len+val_len+8,MAC_buff,VAL_buff);

			 }

	          }

	}
	return heap;
}

void replace_macro(char *ptr,char *mac_buf,char *val_buf)
{
	
	printf("entered replace macro\n");
	puts(ptr);
	
	int i,k,len,j;
	len=strlen(mac_buf);

       for(i=0;ptr[i];i++)
       {

	       k=0;
	       while(ptr[i+k]==mac_buf[k] && mac_buf[k]!='\0')
	       {
		k++;
	       }
	       if(mac_buf[k]=='\0')
	       {
		       j = strlen(ptr+i+len);
		    
			     memmove(ptr+i+strlen(val_buf),ptr+i+len,j+1);
			     memcpy(ptr+i,val_buf,strlen(val_buf));
			     i += strlen(val_buf)-1;

	       }

       }

}


char* remove_macro(char* heap)
{
	char *ptr=heap,*found=NULL;
	int i,cnt_len=0,len=0;

	for(i=0;ptr[i];i++)
	{
		
		if(ptr[i]=='#' && ptr[i+1]=='d')
		{
	        if(strstr(ptr+i,"#define"))
		{
	          int k;
	          cnt_len=0;
	          for(k=i ;ptr[k]!='\n';k++)
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



