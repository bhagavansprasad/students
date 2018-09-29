#include<stdio.h>
#include<string.h>
main()
{
	int i,t,k,x,n=4;
	char str1[]="aura networks";
	char str2[]="aura networks Bang";
	char str3[50];
	char str4[]="AURA networks";
	char str5[]="institute";

	t = astrcmp(str1, str2);
	if(t == 0)
	{
		printf("strcmp:strings are same:%d \n",t);
	}
	else
	{
		printf("strcmp:not same : \n");
	}

#if 0
	astrcpy(str3,str2);
	printf("strcpy:%s\n",str3);

	astrtolower(str1);
	astrtolower(str2);
	k=astrcasecmp(str1,str2);
	if (k==0)
	{
		printf("strcasecmp:strings are same:%d \n",k);
	}
	else
	{
		printf("strcasecmp:not same: \n");
	}

	astrcat(str1,str5);
	printf("strcat:%s \n",str1);

	x=astrncmp(str1,str2,n);
	if(x==0)
	{
		printf("strncmp:same string \n:%d\n",x);
	}
	else
	{
		printf("strncmp:not same");
	}
#endif
}
