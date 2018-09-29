#include <stdio.h>
//#include <stdlib.h>

void function1();
void function3();
void function2();

extern int idata6;
int idata1=1;
char carray1[10];
char  cname1[128] = "Aura Networks";
char  *pname1 = "Aura Networks";
int idata2;
int idata3=4;
int idata4;
short sh1;
short sh2;
int iarray2[10]={1,2};
short sh3;
short sh4=4;
char ch1=1;
char ch2;
short sharray3[10]={5,6};
char ch3=3;
/*int idata5=10;
int idata6=20;*/

main()
{

	int ldata1;
	int ldata2=2;
	int ldata3;
	static int sdata1;
	static int sdata2=10;
	char  cname2[128]="Aura Networks";
	char  *pname2 = "Aura Networks";
	
	int *ptr = malloc(10);
	printf("Main malloc \n");
	printf("ptr = %u\n", ptr);
	printf("*ptr = %u\n\n", &ptr);

	printf("Local main variables\n\n");
	printf("ldata1 = %u\n", &ldata1);
	printf("initialized ldata2 = %u\n", &ldata2);
	printf("ldata3 = %u\n", &ldata3);
	printf("static sdata1 = %u\n", &sdata1);
	printf("static initialized sdata2 = %u\n", &sdata2);
	printf("initialized cname2[128] = %u\n", pname2);
	printf("initialized *pname2 = %u\n\n", &pname2);
	function1();
	function2();
	function3();

	printf("Global variables\n\n");
	printf("extern intialized idata6 = %u\n", &idata6);
	printf("initialized idata1 = %u\n", &idata1);
	printf("carray1[10] = %u\n", carray1);
	printf("initialized cname1[128] = %u\n", cname1);
	printf("initialized *pname1 = %u\n", &pname1);
	
	printf("idata2 = %u\n", &idata2);
	printf("initialized idata3 = %u\n", &idata3);
	printf("idata4 = %u\n", &idata4);
	printf("sh1 = %u\n", &sh1);
	printf("sh2 = %u\n", &sh2);
	printf("initialized iarray2[10] = %u\n", iarray2);
	printf("sh3 = %u\n", &sh3);
	printf("initialized sh4 = %u\n", &sh4);
	printf("initialized ch1 = %u\n", &ch1);
	printf("ch2 = %u\n", &ch2);
	printf("initialized sharray3[10] = %u\n", sharray3);
	printf("initialized ch3 = %u\n", &ch3);
//	printf("idata5 = %u\n", &idata5);
//	printf("idata6 = %u\n\n", &idata6);
	printf("Function addresses\n\n");
	printf("function1 = %u\n", function1);
	printf("function2 = %u\n", function2);
	printf("function3 = %u\n", function3);

/*printf("ldata4 = %u\n", &ldata4);
	printf("idata5 = %u\n", &idata5);
	printf("idata6 = %u\n", &idata6);
	printf("ldata5 = %u\n", &ldata5);*/

}

void function1(void)
{
	int ldata4;
	printf("I am function1\n");
	printf("Function local ldata4 = %u\n", &ldata4);

}

int idata5=10;

void function2(void)
{
	printf("I am function2\n");
	printf("Global initialized in function2 idata5 = %u\n", &idata5);
}

void function3(void)
{
	int ldata5=10;
	printf("I am function3\n");
	printf("Function local ldata5 = %u\n\n", &ldata5);

}

int idata6=20;
