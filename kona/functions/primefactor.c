#include <stdio.h>
main()
{
	int num=56;
	pfactor(num);
	printf("\n");
}
void pfactor(int num)
{
	int i;
	for(i=2;num!=1;i++)
	while(num%i==0)
	{
		printf("%d\t",i);
		num=num/i;
	}
}
