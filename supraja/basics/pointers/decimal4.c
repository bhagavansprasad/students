#include<stdio.h>
int main()
{
	int i;
	int a=300;
	int b=300;
	char *p=(char *)&a;
	char *q=(char *)&b;
	*(p+3)=*(p+1);
	*(p+2)=*(p);
	*(p+1)=*(q+3);
	*(p+0)=*(q+2);
	for(i=0;i<=3;i++)
	{
		printf("%d\n",*(p+i));
	} 
}
