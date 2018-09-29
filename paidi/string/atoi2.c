#include<stdio.h>
#include<string.h>

char str[]=" 10,20,30,40,+_)(50";
char name[30];
main()
{
	int i,j=0,c=0;
	for(i=0; ;i++)
	{
		if(str[i]>='0' && str[i] <='9' && str[i] !='\0')
		{	
			c++;
			name[j++]=str[i];

		}	
		else
		{
			if(c!=0)
			{
				name[j]='\0';
				printf("vall-->=%d\n",atoi(name));
				j=0;
			}
			c=0;
		}
		if(str[i]=='\0')
			break;

	}
}
