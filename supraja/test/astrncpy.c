#include <stdio.h>
#include <string.h>
char *astrncpy(char *,char *,int );
int main()
{
	char a[]="Global Edge";
	char b[100];
	astrncpy(a,b,5);
	printf("%s\n",b);
}
char *astrncpy(char *a,char *b,int n)
{
	int i;
	for(i=0;a[i]!='\0'&&i<n;i++)
	{
		b[i]=a[i];
	}
	b[i]='\0';
	return b;
}
