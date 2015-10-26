#include<stdio.h>
#include<string.h>
int main()
{
	int b=0,c=0,i;
	char s[20]={"sRaVaNi"};
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]>= 65 && s[i]<=90)
		{
			b++;
		}
		else if(s[i]>=97 && s[i]<=122)
		{
			c++;
		}
	}
	printf("%d\n",b);

	printf("%d\n",c);
}
