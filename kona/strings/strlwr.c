#include <stdio.h>
#include <string.h>
main()
{
	int i;
	char s1[10]="SREENU";
	for(i=0;s1[i]!='\0';i++)
	{
		if(s1[i]>=65 &&s1[i]<=90)
			s1[i]=s1[i]+32;
	}
		
		printf("--->s1 string is :%s\n",s1);
	
}
