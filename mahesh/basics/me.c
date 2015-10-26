#include <stdio.h>
int conv(char c)
{
<<<<<<< me.c
	if(isdigit(c))
		return c - '0';
	else if(c >='a'&& c <= 'f')
		return (10+c - 'a');
	else if (c >= 'A' && c <= 'F')
		return (10+c - 'A');
=======
	if(isdigit(c))
			return c - '0';
	else if(c >='a'&& c <= 'f')
		return 10+c - 'a';
	else if (c >= 'A' && c <= 'F')
		return 10+c - 'A';
>>>>>>> 1.2
}
main()
{
	char s[50]="Abauranetworks";
	char d[10];
	int a= conv(*s);
	printf("%d\n",a);
	int b=conv(*(s+1));
	printf("%d\n",b);
	int len = (a)*10+b;
//	printf("%d\n",(*s)*10);
	printf("%d\n",len);
	//printf("%s\n",s+2);
	strncpy(d,s,2);
	printf("%s\n",d);
	printf("%s\n",s+2);
}

