#include<stdio.h>
int main()
{
	char ch='A';
	char *pch;
	pch=&ch;
	printf("%c\n",*pch);
	*pch='B';
	printf("%c\n",*pch);
	printf("%c\n",pch);
	pch=pch+1;
	printf("%c\n",pch);
	pch++;
	printf("%c\n",pch);
}
