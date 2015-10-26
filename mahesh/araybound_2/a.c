#include <stdio.h>
#include <stdlib.h>
main()
{
	int *p1,i,j,*p2;
	p1=malloc(5*sizeof(int));
	p2=malloc(5*sizeof(int));
	printf("enter elements into p1:\n");

	for(i=0;i<5;i++)
	{
		//printf("%u  :\t",p+i);
		scanf("%d\t",p1+i);
	}
	printf("enter elements into p2:\n");
	for(i=0;i<5;i++)
	{
		//printf("%u  :\t",p+i);
		scanf("%d\t",p2+i);
	}
	printf("elements of p1:\n");
	for(j=0;j<5;j++)
	{
	printf("%u  :\t",p1+j);
	printf("%d\t",*(p1+j));
	}
	printf("elements of p2:\n");
		for(j=0;j<5;j++)
	{
	printf("%u  :\t",p2+j);
	printf("%d\t",*(p2+j));
	}

}
