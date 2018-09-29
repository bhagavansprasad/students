#include "stdio.h"
#include "string.h"

char *name,name1[10],name2[10];

void parse_and_store(char *str,char *temp)
{
	//int *p=temp;
	int count=0;
	while(*str!='\0')
	{
		if(count==0)
		{
			while((*name++ = *str++) != ' ') ;
			*name ='\0';
			count++;
		}
		if(count==1)
		{
			while((*name++ = *str++) != ' ') ;
			*name ='\0';
			count++;
		}
		if(count==2)
		{
			while((*name++ = *str++) != ' ') ;
			*name ='\0';
		}
	}
}

main()
{
	int count=0,i,j=0;
	char temp[30];
	char str[50] ="mohansai sakethram vachanram ";
	
	parse_and_store(str,temp);
	
printf("name %s\r\n", name);
printf("name1 %s\r\n", name1);
printf("name2 %s\r\n", name2);
}		

