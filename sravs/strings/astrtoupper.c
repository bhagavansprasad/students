#include <stdio.h>
#include <string.h>
main()
{
	char buff1[]="aura networks";
	char buff2[]="AURA NETWORKS";
	astrtoupper(buff1,buff2);
	printf("%s%s \n",buff1,buff2);
}
int astrtoupper(char str1[],char str2[])
{
	int i;
	for(i=0;str1!='\0';i++)
	{
		if(str1[i]>=65&&str2[i]<=91)
			str1[i]=str2[i]-32;
	}
}
