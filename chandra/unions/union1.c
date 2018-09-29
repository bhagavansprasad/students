#include<stdio.h>
union student
{
	int a;
	char c[3];
};
union student print;

main()
{
	print.a = 0x11121314 ;
	printf("a is : %x\n", print.a);
	printf("c[0] is : %x\n", print.c[0]);
	printf("c[1] is : %x\n", print.c[1]);
	printf("c[2] is : %x\n", print.c[2]);
	printf("c[3] is : %x\n", print.c[3]);
}

