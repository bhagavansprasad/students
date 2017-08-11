#include<stdio.h>
main()
{
	int i=4,temp;
	int a=0x12131415;
	printf("0x%x  ",a);
	char *p= (int *)&a;
	while(*p)
	{
	printf(" a=0x%x",*p);
		*p++;
	}
	short int *q=(int *)&a;
	while(*q)
	{
	printf(" a=0x%x",*q);
		*q++;
	}
	char *r= (int *)&a;
	while(*r)
	{
	
	printf(" a=0x%x",*r+3);
		
	}


}
