#include <stdio.h>
int   idata1=1;
char  carray1[10];
int   idata2;
int   idata3 = 3;
int   idata4;
short sh1;
short sh2 = 2;
int   iarray2[10] = {1, 2};
short sh3;
short sh4 = 4;
char  ch1 = 1;
char  ch2;
short sharray3[10] = {5, 6};
char  ch3 = 3;

main()
{
	int ldata1;
	int ldata2 = 2;
	int  ldata3;
	static int sdata1;
	static int sdata2 = 10;

	int *ptr=malloc(10);

	printf("%u\n", ptr);
	printf("%u\n", &ptr);
}

void fun1( )
{ 
	int ldata4;

	printf("I am funcion1\n");
}

int idata5 = 10;
void fun2( )
{ 
	printf("I am function 2\n");
}

void fun3()
{
	int ldata5 = 10;
	printf("I am funcion 3\n");
}

int idata6 = 20;

