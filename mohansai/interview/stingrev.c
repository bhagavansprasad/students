#include "stdio.h"
#include "string.h"

void astrrev(char * temp);
main()
{
	char name[]= "mohansai ";
	int i,j=0,len;
	
	char temp[10];	
		
	/*	for(i=0;name[i]!='\0';i++)
		{
			if(name[i] == ' ')
			{
				temp[j]='\0';
				printf("temp : %s\n\r",temp);
				j=0;
				astrrev(temp);
			}
				temp[j++]=name[i];
		}*/

	astrrev(temp);
	printf("%s\n\r",name);
}

void astrrev(char *temp)
{
	int len,i;
	len=strlen(temp);
	printf("len--> %d\n\r",len);
	printf("temp-->%s\n\r",temp);
	for(i=0 ; i<len-i ; i++)
	{
		temp[len]=temp[i];
		temp[i]=temp[len-1];
		temp[len-1]=temp[len];
		temp[len]='\0';
	}
printf("temp-->%s\n\r",temp);

}

