#include "stdio.h"
#include "string.h"

void astrcpy(char *s, char *t)
	{
		while(*t != '\0')
			*s++ = *t++;
		*s = '\0';
	}

main()
{
	char name[10],name1[10],name2[10];
	int count=0,i,j=0;
	char temp[30];
	char str[50] ="mohansai sakethram vachanram ";
	
	for(i=0; str[i] != '\0' ; i++)
	{
		if(str[i]!=' ' )
		{
			temp[j++]=str[i];
		}
		else
		{
			temp[j]='\0';
			
			if(count==0)
			{
				astrcpy (name,temp);
				count++;
				printf("%s\n",name);
			}
			else if(count==1)
			{
				astrcpy (name1,temp);
				count++;
				printf("%s\n",name1);
			}
			else 
			{
				astrcpy (name2,temp);
				printf("%s\n",name2);
			}
			j=0;
		}
	}
}		
		
		
