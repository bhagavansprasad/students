#include<stdio.h>
int i,t;
main()
{
	char a[10]="HARITHA";
	char b[10]="hariTHa";
	t=astrcasecmp(a,b,2);
	printf("%d",t);
}
int astrcasecmp(char *s1,char *s, int n) 
{
	for(i=0;s1[10]!='\0'&&i<=2;i++)
	{
		if(strcasecmp(s1,s)== 0)
		{
			return 0;
		}
		else

			return 1;
	}
}

