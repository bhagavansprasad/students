#include<stdio.h>
int i,j,t;
main()
{
	char s1[25]="haritha btect";
	char s2[25];
	astrncpy(s2,s1,6);
	printf("%s\n%s\n",s2,s1);
}
int astrncpy(char*s2,char*s1,int n)
{
	for(i=0;s1[i]!='\0'&&i<=6;i++)
	{
//		for(j=0;s2[j]!=6;j++)
		
			s2[i]=s1[i];
		
	}
}
