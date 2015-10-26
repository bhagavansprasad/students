#include <stdio.h>
void astrcpy(char *a,char *b,int n);
main()
{
	char a[10]="maheswar",b[10],n=4;
	astrcpy(a,b,n);
	printf("%s\n",b);
}
void astrcpy(char *a,char *b,int n)
{
	int i;
	for(i=0;a[i]!='\0'&&i<n;i++)
	{
		b[i]=a[i];
	}
	b[i]='\0';
}
