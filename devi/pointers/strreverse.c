#include <stdio.h>
void astrrev(char *p, int n)
{
	int i;
	for(i=n;i>=0;i--)
	{
		printf("%c", *(p+i));
	}
}
main()
{
	char str[]= "string string";
	printf("%s\n",str);
	char *cp;
	int n = strlen(str);
	cp = str;
	astrrev(cp,n);
}
