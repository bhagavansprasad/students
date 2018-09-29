#include<stdio.h>
int main()
{
	int i;
    int a=300;
	short int b;
	char *p=(char *)&a;
	char *q=(char *)&b;
	for(i=0;i<=1;i++)
	{
	    *(q+i)=*(p+i+2);
		printf("%d\n",*(q+i));
	}
}
