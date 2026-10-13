#include "header.h"


int cnt;
char str[100];
FILE *newptr1=NULL,*headptr1=NULL;

char *conditional_compilation(char* heap);
void check_condition(char *mbuf ,char *ptr);
int main(int argc,char* argv[])
{


	if(argc<2)
	{
		printf("invalid input");
		exit(0);

	}

	
	 strcpy(str,argv[1]);
	 memset((str+strlen(str)-1),'i',1);
	 

 FILE* fptr=NULL;
 char *heap=NULL;
 
  fptr= fopen(argv[1],"r");

  if(fptr==NULL)
  {
	  printf("failed to open the file");
	  exit(0);
  }

  heap = read_file(fptr);

  printf("========================printing heap after reading file======================\n");
  print_heap(heap);
   
  heap= remove_sl_comment(heap);
  
  printf("=================printing after single line comment removealread file==========\n");
  print_heap(heap);

  heap=remove_ml_comment(heap);

 printf("====================printing heap after multi line comment removeal=============\n");
 print_heap(heap);

 header_inclusion(heap);

 printf("====================printing heap after header inclusion=============\n");
 print_heap(heap);
 //save_file(heap);
 //
 /*
if(flag==0)
 {
	 newptr1= fopen(str,"w+");
	 flag=1;
 }else
 {
*/	 newptr1= fopen(str,"a");

heap = remove_header(heap);

heap = find_macro(heap);


heap = conditional_compilation(heap);

heap = remove_macro(heap);

 printf("====================printing heap after macro replacment inclusion=============\n");
print_heap(heap);
fputs(heap,newptr1);

 fclose(newptr1);

 
  fclose(fptr);


}



char *conditional_compilation(char* heap)
{	printf("entered find macro\n");
         
	char *mptr[100];
	char *ptr=heap;
	char MAC_buff[100],VAL_buff[100];
        int i,j,k,mac_len=0,val_len=0,arr_cnt=0; 
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
			     //mptr[arr_cnt]=MAC_buff;
			     //arr_cnt++;

			     check_condition(MAC_buff,ptr+i+mac_len);
			      
                             printf("Mac_buf:");
			     puts(MAC_buff);
			     printf("\n");
                          

			 }

	          }

	}

	/*
        int arr_size = sizeof(mptr)/sizeof(mptr[0]);
	for(int i=0;i<arr_size;i++)
	{
		printf("%d",*mptr[i]);

	}
	printf("\n");*/


	return heap;
}


void check_condition(char *mbuf ,char *ptr)
{
	int i,k,len_cnt;
	for(i=0;ptr[i];i++)
	{
		if(ptr[i]=='#' && ptr[i]=='i')
		{
			
			if(strstr(ptr+i,"#ifdef"))
			{
				k=i;
				
			        if(strcmp(ptr+i+6,mbuf))
				{
					break;
				}
				while(!strcmp(ptr+k,"#endif"))
				{
					memset(ptr+k,' ',1);
					k++;
				
				}
			
			}

		}

	}

}













/*
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

*/
