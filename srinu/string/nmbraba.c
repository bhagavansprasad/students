#include<stdio.h>
#include<string.h>
int main()
{
	int b=0,c=0,d=0,i;
	char s[100]={"AAABBBaaa"};
	for(i=0;s[i]!='\0';i++)
	{
		if(s[i]=='A')
		{
			b++;
		}
		else if(s[i]=='B')
		{
			c++;
		}
		else if(s[i]='a')
		{
			d++;
		}
	}
	printf("%d\n",b);
	printf("%d\n",c);
	printf("%d\n",d);
}
