#include <stdio.h>
main()
{
	int a=0x12131415,i,n=4;
	short int *sh1,*sh2,*t;
	sh1=(short int *)&a;
	sh2=sh1+1;
	t=sh1;
	sh1=sh2;
	sh2=t;
	//printf("%x%x",*sh1,*sh2);
	char *p1,*p2,*p3,*p4;
	p1=sh1;
	p2=p1+1;
	printf("%x",*p1);
	printf("%x",*p2);
	p3=sh2;
	p4=p3+1;
	printf("%x",*p3);
	printf("%x",*p4);

}
