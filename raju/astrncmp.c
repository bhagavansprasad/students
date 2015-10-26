#include<stdio.h>
#include<string.h>
main()
{
	char s1[]="Hi Hello How are you";
	char s2[]="Hi Hello who are you";
	int len15,t;
	t=astrncmp(s1,s2,len);
	if(t==0)
	{
	  printf("Strings are equal\n");
	}
	else
	  printf("Strings are not equal\n");
}	  
int astrncmp(char *s1,char *s2,int n)
{
	int i;
	for(i=0;s1[i]==s2[i];i++)
	{
		if(i==n-1)
		{
		 return 0;
	    }
	}
	return 1;
}	


