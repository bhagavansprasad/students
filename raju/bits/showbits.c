#include<stdio.h>

#define GET_BIT_VALUE(n,pos) ((n)&(1<<(pos)-1)?1:0)

main()
{

	unsigned int a=128,i,mask=10;

	printf("size:%d\n",sizeof(a));

	mask=mask<<4;
//	printf("%d\t",mask);

	mask=mask>>2;
//	printf("mask:%d\n",mask);

/*	for(i=8; i>=1; i--)
	{

		printf("%d",GET_BIT_VALUE(mask,i));
	
	}*/
	for(i=16; i>=1; i--)
	{

		if( i==24 || i==16 || i==8)
		{

			printf("  ");

		}	
	
		printf("%d",GET_BIT_VALUE(a,i));
	
	}


	printf("\n");
}

