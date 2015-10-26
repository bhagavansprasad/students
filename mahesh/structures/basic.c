#include<stdio.h>
#include"string.h"
main()
{
	typedef struct book
	{
		int i;
		char c[9];
		short s;
	}a;
	a b={3,"stru",8};
	printf("adress of i: %u\n adress of c: %u\n adress of s: %u\n",&b.i,&b.c,&b.s);
	printf("total size: %d\n",sizeof(struct book));
//	printf("string length:%d\n",strlen("structure"));
printf("c=%c\n c= %d\n",b.c[4],b.c[4]);
}
