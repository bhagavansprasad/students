#include <stdio.h>
int idata1=1;
char carry1[10];
int idata2;
int idata3=3;
int idata4;
short sh1;
short sh2=2;
int iarray2[10]={1, 2};
short sh3;
short sh4;
char ch1=1;
char ch2;
short sharray3[10]={5, 6};
char ch3=3;
main()
{
	int ldata1,i;
	int ldata2=2;
	int ldata3;
	static int sdata1;
	static int sdata2=10;
	printf("ldata1=%u\n",&ldata1);
	printf("ldata2=%u\n",&ldata2);
	printf("ldata3=%u\n",&ldata3);
	printf("sdata1=%u\n",&sdata1);
	printf("sdata2=%u\n",&sdata2);
	int *ptr=malloc(10);
	fun1();
	fun2();
	fun3();
	printf("ptr=%u\n",&ptr);
	printf("ptr=%u\n",&ptr);
	printf("idata1=%u\n",&idata1);
	for(i=0;i<10;i++)
		printf("%u\n",&carry[i]);
	printf("idata2=%u\n",&idata2);
	printf("idata3=%u\n",&idata3);
	printf("idata3=%u\n",&idata3);
	printf("sh1=%u\n",&sh1);
	printf("sh2=%u\n",&sh2);
	for(i=0;i<10;i++)
		printf("%u\n",&iarray2[i]);
	printf("sh3=%u\n",&sh3);
	printf("sh4=%u\n",&sh4);
	printf("ch1=%u\n",&ch1);
	printf("ch2=%u\n",&ch2);
	for(i=0;i<10;i++)
		printf("%u\n",&sharray3[i]);
	printf("ch3=%u\n",&ch3);
}
void fun1()
{
	int ldata4;
	printf("ldata4=%u",&ldata4);
	printf("i am function1\n");
}
int idata5=10;
void fun2()
{
	printf("i am function2\n");
}
void fun3()
{
	int ldata5=10;
	printf("ldata5=%u\n",&ldata5);
	printf("i am function3\n");
}
int idata6=20;
