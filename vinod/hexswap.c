#include<stdio.h>
main()
{
	int a=0x12131415,b=0,c,i;
	char *p1=&a,*p2=&b;
	c=sizeof(int)-1;
	for(i=0;i<sizeof(int);i++,c--)
		*(p2+c)=*(p1+i);
	printf("before swap\n");
	for(i=0;i<sizeof(int);i++)
		printf("%x",*(p1+i));
	printf("\nAfter swap\n");
	for(i=0;i<sizeof(int);i++)
		printf("%x",*(p2+i));
	printf("\n");
}
