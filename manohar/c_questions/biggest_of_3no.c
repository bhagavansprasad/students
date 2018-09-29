#include <stdio.h>
int main()
{
	int a=20,b=30,c=10;
	if(a > b && a > c)
		printf("a is bigger %d\n",a);
	else if(b > c && b > a)
		printf("b is bigger %d\n",b);
	else
		printf("c is bigger %d\n",c);
	return 0;
}

