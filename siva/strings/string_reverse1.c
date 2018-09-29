#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	char s1[]="sib";
	int i;
	int len = strlen(s1);
	
	
	printf("string length===%d\n",strlen(s1));

	for(i=0; i<(strlen(s1)/2);i++)
	{
                    len--;
		s1[i]=s1[i]+s1[len];
		
		
		s1[len]=s1[i]-s1[len];
				
		s1[i]=s1[i]-s1[len];
		
			}
	printf("%s\n",s1);
}
