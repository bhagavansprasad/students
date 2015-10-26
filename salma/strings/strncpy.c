#include<stdio.h>
#include<string.h>
char *astrncpy(char *str1,char *str2,int n)
{
	int i=0;
	for(i=0;i<n;i++)
	{
		*str1=*str2;
		str1++;
		str2++;
    }
	*str1='\0';
	return str1;
}
main()
{
	char str1[20];
	char str2[]="salmamateen";
	astrncpy(str1,str2,5);
	printf("%s\n",str1);
}

