#include<stdio.h>
char *a_strncpy(char *,char *,int n);
main()
{
	int n=5;
	char a[15]="manoharreddy";
	char b[20];
	a_strncpy(a,b,n);
}
char *a_strncpy(char *a,char *b,int n)
{
	int i;
	for(i=0;i<5;i++)
	{
	 b[i]=a[i];
	}
	printf("%s\n",b);
}

