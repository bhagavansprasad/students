#include <stdio.h>
main()
{
	unsigned int a=300;
	int i;
	unsigned char *p=&a;

	for(i=0;i<=3;i++)
	{
		printf("%d\n",*p++);
	}
	/*printf("%d\n",*p++);
	printf("%d\n",*p++);
	printf("%d\n",*p++);*/
}
