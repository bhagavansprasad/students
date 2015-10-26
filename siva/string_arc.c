#include<stdio.h>
#include <string.h>
#include <fcntl.h>
#include<stdlib.h>
#include<string.h>
main(int argc, char *argv[])		
{
   
   char ch1[50];
   char ch2[50];
   int i;
  strcpy(ch1[],*argv[1]);
  strcpy(ch2[],*argv[2]);
	
	if(argc<=3)
	{
		printf("need arguements");
	}
	
	if(ch1[0]== '+' )
	{
		printf("STRING STARTING WITH + SIGN\n");

		for(i=0;ch1[i]!='\0';i++)
		{
			if(ch1[i]>=97 && ch1[i]<=122)
			{
				ch1[i]-=32;
			}
		}
		for(i=1;ch1[i]!='\0';i++)
			printf("%c",ch1[i]);
	}
	if(ch2[0] == '-')
	{
		printf("STRING STARTING WITH - SIGN\n");

		for(i=0;ch2[i]!='\0';i++)
		{
			if(ch2[i]>=65 && ch2[i]<=91)
			{
				ch2[i]+=32;
			}
		}
		for(i=1;ch2[i]!='\0';i++)
			printf("%c",ch2[i]);
	}
}
