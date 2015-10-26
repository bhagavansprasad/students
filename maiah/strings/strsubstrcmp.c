#include <stdio.h>
#include <fcntl.h>
#include <string.h>
char *my_strstr(char *s2,char *s1);
main()
{
	char s2[80]="my name is venkatesamaiah and i am pursuing embedded systems in aura net";
	char s1[20]="pursuing";
	char *t;
	printf("the sub string is:%s\n",my_strstr(s2,s1));
	return(0);
}
char *my_strstr(char *s2,char *s1)
{
	int i,j;
	int flag = 0;
	if(s2 == '\0' || s1 == '\0')
		return NULL;

	for(i=0; s2[i] !='\0'; i++)
	{
printf("In for loo\n");
		if(s2[i] == s1[0])
		{
			for(j=1; ;j++)
			{
printf("In for loop 2\n");
				if(s1[j-1]== '\0')
				{
					flag=1;
					break;
				}
				if(s2[j]==s1[j-1])
					continue;
				else break;
			}
			if(flag==1)
				break;
		}
		if(flag==1)
			return s2+i;
	}
}
