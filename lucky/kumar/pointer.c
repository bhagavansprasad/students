#include<stdio.h>
main()
{
	int a=300,i=0;
	char *cp= &a;
	for(i=0;i<4;i++)
	{
		printf("%d\n",*cp);
		cp++;
	}
}
