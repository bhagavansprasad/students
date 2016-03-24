#include<stdio.h>
#include<string.h>
#include<stdlib.h>
main()
{
	int ret;
	char str1[]="aura networks";
	char str2[]="auranet works";
	ret=strncmp(str1,str2,8);
	printf("%d    \n",ret);
}
