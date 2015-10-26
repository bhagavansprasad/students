#include <stdio.h>
main()
{
	int a = 0x12131415,i;
	char *c,*p;
	short int *k;
	c=&a;
	k=&a;
	//	printf("%x\t addr------>%u\n",*p,p);
	//	printf("%u\n",&a+1);

	for(i=0;i<4;i++,c++)
	{
		printf("%x\t addr---->%u\n", *c,c);	
	}
	//	printf(" addr of c after for loop%u\n",c);

	for(i=0;i<2;i++,k++)
	{
		printf("%x \t addr---->%u\n",*k,k);
	}

	p=c--;
	for(i=0;i<4;i++)
	{
		p--;
		printf("%x\t addr------>%u\n",*p,p);
	}
}
