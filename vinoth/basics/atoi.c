#include <stdio.h>
main ()
{
	int t;
	char s[100] = "222";
	t = atoi(s);
	printf ("%d\n", t);
}

int atoi(char *s)
{
	int c=0, i;
	for (i=0; s[i] != '\0'; i++)
	{
		if (s[i] >= 48 && s[i] <=57)
		{
			c = c*10+s[i]-48;
		}
	}
	return c;
}

/*#include<stdio.h>
int aatoi(char a)
{
	int i=0,A=48,k;
	for(i=0;A<=57;i++,A++)
	{
		if(a==A)
		{
			return i;
		}
	}
}*/
