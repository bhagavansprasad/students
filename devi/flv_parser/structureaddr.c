#include<stdio.h>
struct abc
{
	int a;char b;
}*size;
main()
{
	printf("%u\n",&size);
	printf("%d\n",size);
	size++;
	printf("%u\n",&size);
	printf("%d\n",size);
	//printf("%u\n",);
	///printf("%u\n",&size.b);
}
