#include <stdio.h>
int main()
{
	int a=426,b=0;
	b=(b*10)+(a%10);
	a=a/10;

	b=(b*10)+(a%10);
	a=a/10;

	b=(b*10)+(a%10);
	a=a/10;

	printf("%d is reverse of 426 \n",b); 


}


