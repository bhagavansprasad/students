#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(void)
{
 FILE *fptr;
 int ch;
 if(fptr=fopen("file3.c","w")==NULL)
 {
  printf("error in opening file");
  exit(1);
 }
 printf("enter text\n");
 while((ch=getchar())!=EOF)
 fputc(ch,fptr);
 fclose(fptr);
 return0;
} 


