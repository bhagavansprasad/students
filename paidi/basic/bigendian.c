#include<stdio.h>
main()
{
	int a=0x12345678;
	unsigned char *p=(unsigned char *)(&a);
	printf("valu---=%x\nadd--->=%u\n",*p,p);
	if(*p == 0x78)
		printf("big endian\n");
	else
		printf("little Endian\n");
}

/*
main()
{
	int a=300,i;
	unsigned char *p=(unsigned char *)(&a);
	printf("endian cheek it-->=   ");
	for(i=0;i<4;i++)
	{
		printf("  ");
		printf("valu-->= %d\t\n  ",*p);
		printf("add--->= %u  ",p);
		*p++;
	}
	printf("\n");
}
*/
