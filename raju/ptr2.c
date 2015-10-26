#include<stdio.h>
main()
{
	char ch='A';
	char *pch;
	pch=&ch;
	printf("*pch:%d\n",*pch);
	*pch='B';
	printf("*pch:%d\n",*pch);
	printf("pch:%d\n",pch);
	pch=pch+1;
	printf("pch:%d\n",pch);
//	printf("*pch:%d\n",*pch);


	pch++;
	printf("pch:%d\n",pch);
//	printf("*pch:%d\n",*pch);

}	


