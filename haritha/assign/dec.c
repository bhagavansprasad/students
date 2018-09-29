#include "stdio.h"
#include "stdlib.h"
int idata1=1;
char carray1[10];
char cname1[128]="Aura Networks";
char *pname1="Aura Networks";
int idata2;
int idata3=3;
int idata4;
short sh1;
short sh2=2;
int iarray1[10]={1,2};
int iarray2[10]={10,20};
short sh3;
short sh4=4;
char ch1=1;
char ch2;
short sharray3[10]={5,6};
char ch3=3;
void fun1();
void fun2();
void fun3();
main()
{
	int ldata1;
	int ldata2=2;
	int ldata3;
	static int sdata1;
	static int sdata2=10;
	char cname2[128]="Aura Networks";
	char *pname2="Aura Networks";
	int *ptr=malloc(10);
	printf("ptr--->%p\n",ptr);
	printf("&ptr-->%p\n",&ptr);
	printf("cname1--->%p\n",cname1);
	printf("pname1--->%p\n",pname1);
	printf("&pname1--->%p\n",&pname1);
	printf("cname2--->%p\n",cname2);
	printf("pname2--->%p\n",pname2);
	printf("&pname2--->%p\n",&pname2);
	printf("fun1--->%p\n",fun1);
	printf("fun2--->%p\n",fun2);
	printf("fun3--->%p\n",fun3);
	ptr=malloc(10);
	printf("ptr--->%p\n",ptr);
	printf("iarray1--->%p\n",iarray1);
	printf("iarray2--->%p\n",iarray2);
	printf("sharray3--->%p\n",sharray3);
}
void fun1()
{
	int ldata4;
	printf("iam function 1 \n");
}
int idata5=10;
void fun2()
{
	printf("i am function 2\n");
}
void fun3()
{
	int ldata5=10;
	printf("i am function 3\n");
}
int idata6=20;














