#include<stdio.h>
main()
{
    int a=400;
	int i;
	unsigned char *p;
	p=&a;

	for(i=3;i>=0;i--)
	{
		printf("%d\t",*(p+i));
		printf("%u\t",(p+i));

	}
	printf("\n");
}	
