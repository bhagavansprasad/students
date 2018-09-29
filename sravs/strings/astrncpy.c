#include<stdio.h>
#include<string.h>
#include<stddef.h>
char* astrcpy( char str1[],char str2[],int n);
main()
{
int n=5;
	char buff1[30];
	char buff2[]="aura networks";
	astrcpy(buff1,buff2,n);
	printf("%s\n",buff1);
	printf("%s\n",buff2);
}
char* astrcpy( char str1[],char str2[],int n)
{
	int i;
	for(i=0;i<=n && str2[i]!='\0';i++)
	{
		str1[i]=str2[i];
	}	
		str1[i]='\0';
	return str1;
}


