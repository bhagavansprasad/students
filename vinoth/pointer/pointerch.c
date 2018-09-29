#include<stdio.h>
main()
{
	char ch='A';
	char *pch;
	pch=&ch;
	printf("%d\n",*pch);
	*pch='B';
	printf("%d\n",*pch);
	printf("%d\n",pch);
	pch=pch+1;
	printf("%d\n",pch);
	pch++;
	printf("%d\n",pch);
}

