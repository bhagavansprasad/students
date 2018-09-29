#include "stdio.h"
#include "stdlib.h"
#include <fcntl.h>
main(int argc , char *argv[])
{

int d,fs,retval=0;;
char buffer[25];
char buff[1024];
int list_of_numbers[500];
  
  d=atoi(argv[1]);

	sprintf(buffer,"/proc/%d/stat",d);
	printf("buffer-->%s\n",buffer);

  fs=open(buffer,O_RDONLY);
  if(fs == -1)
  {
 	perror("error");
	exit(1);
  }
 
 retval=read(fs,buff,1024);
 buff[retval]= '\0';
 printf("the buffer value %s\r\n",buff);


 tot_numbers = parse_and_store(list_of_numbers, buff);

}


int  parse_and_store(int *arr ,char buff)
{
int i;
temp[1024];
  for( i = 0 ; buff[i] != '\0' ; i++ )
  {
  if(buff[i]!=' ' || buff[i]!='\n' && buff[i]!='\r')
  {
 	temp[i]=buff[i];
  }
  else
  {
  	

