#include<stdio.h>
main()
{
	int a=300;
	char *pa;
	pa=(char*)&a;
	printf("%d\n",*(pa));
	printf("%d\n",*(pa+1));
	printf("%d\n",*(pa+2));
	printf("%d\n",*(pa+3));


}
