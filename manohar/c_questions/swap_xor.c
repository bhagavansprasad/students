#include <stdio.h>
int main()
{
	int a=10,b=20;
	a = a^b;
	b = b^a;
	a = b^a;
	printf("a---->%d\tb----->%d\n",a,b);
	return 0;
}
