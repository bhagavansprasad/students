#include<stdio.h>
int idata1=1;
char carray1[10];
char cname1[128] = "Aura Networks";
char *pname1 = "Aura Networks";
int idata2;
int idata3 = 3;
int idata4;
short sh1;
short sh2 = 2;
int iarray2[10] = {1, 2};
short sh3;
short sh4 = 4;
char ch1 = 1;
char ch2;
short sharray3[10] = {5, 6};
char ch3 = 3;
void fun1();
void fun2();
void fun3();
main()
{
	int ldata1;
	int ldata2 = 2;
	int ldata3;
	static int sdata1;
	static int sdata2 = 10;
	char cname2[128] = "Aura Networks";
	char *pname2 = "Aura Networks";
	int *ptr=malloc(10);
	printf("%u\n",&idata1);
	printf("%u\n",&carray1);
	//printf("%u\n",cname1);
	printf("%u\n",&idata2);
	printf("%u\n",&idata3);
	printf("%u\n",&idata4);
	printf("%u\n",&sh1);
	printf("%u\n",&sh2);
	printf("%u\n",&iarray2);
	printf("%u\n",&sh3);
	printf("%u\n",&sh4);
	printf("%u\n",&ch1);
	printf("%u\n",&ch2);
	printf("%u\n",&sharray3);
	printf("%u\n",&ch3);
	printf("%u\n",&ldata1);
	printf("%u\n",&ldata2);
	printf("%u\n",&ldata3);
	printf("%u\n",&sdata1);
	printf("%u\n",&sdata2);
	//printf("%u\n",carry1);

	//printf("%u\n",ptr);
	printf("%u\n",&ptr);
	printf("%u\n",&cname1);
	//printf("%u\n",pname1);
	printf("%u\n",&pname1);
	printf("%u\n",&cname2);
	//printf("%p\n",pname2);
	printf("%u\n",&pname2);
	printf("%u\n",&fun1);
	printf("%u\n",&fun2);
	printf("%u\n",&fun3);
	//printf("%u\n",fun3);
//		my_fun();
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
int idata6=20;
