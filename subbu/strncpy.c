#include<stdio.h>
#include<string.h>
main()
{
	int i=0,n=2;
	char s1[5]="mani";
	char s2[5];
	for(i=0;i<n;i++)
	{
		s2[i]=s1[i];
	}
	s2[i]='\0';
	printf("%s\n",s2);
}
