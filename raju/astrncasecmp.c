#include<stdio.h>
#include<string.h>
int astrncasecmp(char *s1,char *s2,int len);

main()
{
	char s1[]="HI HELLO HOW are you";
	char s2[]="Hi Hello How are YOU";
	int t,n=10;
	t=astrncasecmp(s1,s2,n);
	printf("t:%d\n",t);
	printf("s1:%s s2:%s\n",s1,s2);
	if(t==0)
	{
	  printf("Strings are equal\n");
	}
	else
	  printf("Strings are not equal\n");
}


int astrncasecmp(char *s1,char *s2,int len)
{

	int i,j=0;

	for(i=0;   ;i++)
	{
		if((s1[i]>=65 && s1[i]<=90) || (s1[i]>=97 && s1[i]<=122))
		{
			if((s2[i]>=65 && s2[i]<=90) || (s2[i]>=97 && s2[i]<=122))
			{
				if((s1[i]-s2[i]==32) || (s2[i]-s1[i]==32))
				{
					j=1;
				}
			}
		}
		if((s1[i]==s2[i]) || (j==1))
		{
			j=0;
			if(i==len-1)
			{
			  return 0;
			}
		}
		else 
			return 1;
	}
	
		  
}	


/*int astrncasecmp(char *s1,char *s2,int len)
{
	int i;
	for(i=0;i<len;i++)
	{
		if(s1[i]>='A' && s1[i]<='Z')
		{
		  s1[i]=s1[i]+32;
		}
	}
	for(i=0;i<len;i++)
	{
		if(s2[i]>='A' && s2[i]<='Z')
		{
		  s2[i]=s2[i]+32;
		}
	}
	for(i=0;s1[i]==s2[i];i++)
	{
		if(i==len-1)
		{
		  return 0;
		}
	}
	return 1;		

}	*/





