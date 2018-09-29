#include <stdio.h>
//#include <alloca.h>
#include <stdlib.h>
int idata1 = 1;
char carray1[10];
char cname1[128] = "Aura Networks";
char *pname1 = "Aura Networks";
int idata2;
int idata3 = 3;
int idata4;
short sh1;
short sh2 = 2;
int iarray1[10] = {1, 2};
int iarray2[10] = {10, 20};
int iarray3[10] = {100, 200, 300};
short sh3;
short sh4 = 4;
char ch1 = 1;
char ch2;
short sharray3[10] = {5, 6};
char ch3 = 3;

void fun1();
void fun2();
void fun3();
/*void fun1()
{
	int idata4;
	printf("I am function1\n");
}

int idata5=10;
void fun2()
{
	printf("I am function2\n");
}


void fun3()
{
	int idata5=10;
	printf("I am function3\n");
}

int idata6 = 20;*/
main()
{
int idata1;
int idata2 = 2;
int idata3;
static int sdata1;
static int sdata2 = 10;
char cname2[128] = "Aura Networks";
char *pname2 = "Aura Networks";
int *ptr = malloc(10);
printf("ptr=%u \n",ptr);
printf("&ptr=%u\n",&ptr);

printf("cname1=%u\n",cname1);
printf("pname1=%u\n",pname1);
printf("&pname=%u\n",&pname1);

printf("cname2=%u\n",cname2);
printf("pname2=%u\n",pname2);
printf("&pname2=%u\n",&pname2);

printf("fun1=%u\n",fun1);
printf("fun2=%u\n",fun2);
printf("fun3=%u\n",fun3);

ptr = malloc(10);
printf("ptr=%u\n",ptr);

printf("iarray1=%u\n",iarray1);
printf("iarray2=%u\n",iarray2);
printf("iarray3=%u\n",iarray3);
}


void fun1()
{
	int idata4;
	printf("I am function1\n");
}


int idata5=10;
void fun2()
{
	printf("I am function2\n");
}


void fun3()
{
	int idata5=10;
	printf("I am function3\n");
}
int idata6=20;
