#include <stdio.h>
#include<stdlib.h>
int idata1=1;
char carray1[10];
char cname1[128]="aura networks";
char *pname1="aura networks";
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
	char cname2[128]="aura networks";
	char *pname2="aura networks";
	int *ptr=malloc(10);

	printf("idata1    :%p\n",&idata1);
	printf("carray1   :%p\n",&carray1);

	printf("\n");

	printf("cname1    :%p\n",cname1);
	printf("pname1 val:%p\n",pname1);
	printf("pname1    :%p\n",&pname1);

	printf("\n");

	printf("idata2    :%p\n",&idata2);
	printf("idata3    :%p\n",&idata3);
	printf("idata4    :%p\n",&idata4);

	printf("\n");

	printf("sh1       :%p\n",&sh1);
	printf("sh2       :%p\n",&sh2);

	printf("\n");

	printf("iarray1   :%p\n",iarray1);
	printf("iarray2   :%p\n",iarray2);
	printf("sh3       :%p\n",&sh3);
	printf("sh4       :%p\n",&sh4);

	printf("\n");

	printf("ch1       :%p\n",&ch1);
	printf("ch2       :%p\n",&ch2);
	printf("sharray3  :%p\n",sharray3);

	printf("\n");

	printf("ch3       :%p\n",&ch3);

	printf("ldata1    :%p\n",&ldata1);
	printf("ldata2    :%p\n",&ldata2);
	printf("ldata3    :%p\n",&ldata3);

	printf("\n");

	printf("sdata1    :%p\n",&sdata1);
	printf("sdata2    :%p\n",&sdata2);

	printf("\n");


	printf("cname2     :%p\n",cname2);
	printf("pname2     :%p\n",pname2);
	printf("pname2     :%p\n",&pname2);

	printf("\n");

	printf("ptr        :%p\n",ptr);
	printf("ptr        :%p\n",&ptr);
	ptr=malloc(10);
	printf("ptr        :%p\n",ptr);
}
void fun1()
{
	int idata4;
	printf("i am function1\n");
}
void fun2()
{
	printf("i am function2\n");
}
void fun3()
{
	int idata5=10;
	printf("i am function3\n");
}

int idata6=20;




