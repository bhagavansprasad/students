#include <stdio.h>
#include <string.h>
void count(char *str1)
{
	int n,i,j,c;
	char str[30],ch;
	strcpy(str,str1);
	n = strlen(str);
	for(i=0;i<n;i++)
	{
		if(str[i]!=0)
		{
			c=0;
			ch = str[i];
			for(j=0;j<n;j++)
			{
				if(str[j]==ch)
				{
					c++;
					str[j]=0;
				}
			}
		printf("%c occurs %d times\n",ch,c);
		}
	}
}
main()
{
	char str[]="aura networks real";
	puts(str);
	count(str);
}
