#include<stdio.h>
#include<string.h>
main()
{
	char str1[20]="salmamateen";
	 const char *p="salmamateen";
	printf("before changing values\n");
	printf("arr :%s\n",str1);
	printf("ptr :%s\n",p);
	str1[5]='k';
	printf("after changing values\n");
	printf("arr :%s\n",str1);
	p[5]='k';
	printf("ptr :%s\n",p);
}
