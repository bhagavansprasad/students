#include <stdio.h>
main()
{
	int a = 0x12131415;
	short int *p,*pp;
	short int aa;
	p=(short int *)&a;
	//short int aa=*p; it prints the stmt like 5141
	printf("%x\n",*p);
	pp=p+1;
	printf("%x\n",*pp);
	aa = *p;
	*p=*pp;
	*pp=aa;
	printf("%x after swaping\n",a);
}
