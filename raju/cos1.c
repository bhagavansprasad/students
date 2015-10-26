#include<stdio.h>
main()
{
	unsigned int a=0x12131415;
	int i;
    char *p;
	p=(char *)&a;

	for(i=0;  i<=3;  i++)
	{
		
	//	printf("%d\t",p);	
		printf("%u\t %x\n",*p,*p);
		p++;
		

	}	
}	
