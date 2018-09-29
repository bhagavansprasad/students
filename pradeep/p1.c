#include<stdio.h>
main()
{
	int a=300,i=0;
	int *p=&a;
	char *cp=&a;
	printf("%d\n",*p);
	for(i=0;i<=3;i++)
	{
		printf("%d\n",*cp);
		cp++;
	}
}
