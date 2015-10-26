#include<stdio.h>
#include <string.h>
main()
{
	char s1[10]="sreenu";
	char s2[10];
	char *p=s1;
	int i=0;
	while((s2[i]=*p)!=0)
	{
		s2[i++];
		p++;
	}
	s2[i]='\0';
	printf("%s\n",s2);
}
