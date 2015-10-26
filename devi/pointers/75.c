#include <stdio.h>
int main()
{
	int a=300;
	int *ip=&a;
	char *cp=(char *)&a;
	printf("a = %d\n", a);
	printf("&a = %p\n", &a);
	printf("ip = %p\n", ip);
	printf("&ip = %p\n", &ip);
	printf("*ip = %d\n", *ip);
	printf("*&ip = %p\n", *&ip);
	printf("**&ip = %d\n", **&ip);
	printf("*&a = %d\n",*&a);
	printf("cp = %p\n", cp);
	printf("&cp = %p\n", &cp);
	printf("*cp = %d\n", *cp);
	printf("*&cp = %p\n",*&cp);
	printf("**&cp = %d \n",**&cp);
	printf("after changing:\n");
	return 0;
}
