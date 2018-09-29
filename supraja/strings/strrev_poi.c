#include <stdio.h>
#include <string.h>
main()
{
	char *a="hello world";
	int c=strlen(a);
	printf("%d\n",c);
	a=a+c-1;
	while(c)
	{
		printf("%c",*a);
		a--;
		c--;
	}
	printf("\n");
	return 0;
}

