#include<stdio.h>
char *a_strcpy(char *,char *);
main()
{
	char a[15]="manoharreddy";
	char b[20];
	a_strcpy(a,b);
}
char *a_strcpy(char *a,char *b)
{
	int i;
	for(i=0;a[i]!='\0';i++)
	{
	 b[i]=a[i];
	}
	printf("%s\n",b);
}
