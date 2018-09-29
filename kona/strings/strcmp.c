#include <stdio.h>
#include <string.h>
main()
{
	int i,c=0,n=2;
	char s1[10]="sreenu";
	char s2[10]="sreenu";
	for(i=0; i<n && s1[i]!='\0' && s2[i]!='\0';i++)
	{
		if (s1[i]!=s2[i])
		{
			c++;
			break;
		}
	}
	if(c==0)
		printf("strings are same\n");
	else
		printf("strings are not same\n");
}
