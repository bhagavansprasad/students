#include<stdio.h>
#include<string.h>
main()
{
	char s1[]="siva";
	char s2[]="siva";
	int diff;
	diff=string_cmp(s1,s2);
	if(diff==0)
	{
		printf("strings r equal\n");
	}
	if(diff>0)
	{
		printf("string s1>s2\n");
         }
		else
	{
		printf("string s<s2\n");
	}
}
	int string_cmp(char s1[],char s2[])
	{
                    int i;
		for(i=0;s1[i]!='\0' && s2[i]!='\0';i++)
		{    
			if(s1[i]!=s2[i])
			{
		
			}
		}
		return s1[i]-s2[i];
	}
