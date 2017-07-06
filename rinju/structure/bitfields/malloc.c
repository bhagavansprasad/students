#include<stdio.h>
#include<stdlib.h>
main()
{
	int *p,*q,i;
	p = malloc( 10*sizeof(int));
	if( p == NULL)
	printf(" cant allocate");

	q=calloc(10,sizeof(int));
	if( q == NULL )
	printf("cant allocate");
	
//	for(i=1;i<=10;i++)
//	{
//	*p++ = i+1;
//	}
	for(i=1;i<=10;i++)
	{
	printf(" %d\t ",*p+i);
	}
	strcpy(q,"rinju");
	printf("%s",q);
	printf(" %d\n ",sizeof(p));
	printf(" %ld\n ",sizeof(q));
}
