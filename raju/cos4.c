#include<stdio.h>
main()
{
	unsigned int a=0x12131415;
	int i,j=0,t;
	char *p;
	p=&a;
	for(i=3;i>j;i--,j++)
	{
		t=*(p+i);
		*(p+i)=*(p+j);
		*(p+j)=t;
	}	
	printf("After Swapping Value Of a is\n");
	for(i=3;i>=0;i--)
	{
		printf("%x",*(p+i));
	}
	printf("\n");
}	



