#include<stdio.h>
#include<stdlib.h>
#include<string.h>

extern int cnt;
extern char str[100];

static int flag=0;
//char header_path[100]="/usr/include/";
//char str[100];

//FILE *newptr=NULL,*headptr=NULL;



char* remove_sl_comment(char *ptr);
char* remove_ml_comment(char *ptr);
void save_file(char* ptr);
void print_heap(char *ptr);
char *read_file(FILE* fptr);





void copy_header();
void header_inclusion(char *ptr);
char* remove_header(char* heap);



char *find_macro(char* heap);
void replace_macro(char *p,char *mac_buf,char *val_buf);
char* remove_macro(char* heap);

