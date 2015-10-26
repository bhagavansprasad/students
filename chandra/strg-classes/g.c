#include<stdio.h>
#include<stdlib.h> 
static int sdata3;
static int sdata4= 30;
int idata1=1;
int iarray1[10];
char cname1[128]= "aura networks";
char *pname1= "aura networks";
int idata2;
int idata3 = 3;
int idata4;
short sh1;
short sh2 = 2;
int iarray2[10]= {1, 2};
short sh3;
short sh4= 4;
char ch1=1;
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
	char cname2[128] = "aura networks";
	char *pname2 = "aura networks";
	int *ptr= malloc(10);

    printf("idata1:%u\n", idata1);
	printf("idata2:%u\n", idata2);
	printf("idata3:%u\n", idata3);
	printf("idata4:%u\n", idata4);

	printf("ptr  :%p\n", ptr);
	printf("&ptr :%p\n", &ptr);
    
	printf("iarray2:%p\n", iarray2);
	printf("cname1:%p\n", cname1);
	printf("pname1:%p\n", pname1);
	printf("&pname1:%p\n", &pname1);
	
	printf("cname2:%p\n", cname2);
	printf("pname2:%p\n", pname2);
	printf("&pname2:%p\n", &pname2);
    
	printf("sh1:%u\n", sh1);
	printf("sh2:%u\n", sh2);
	printf("sh3:%u\n", sh3);
	printf("sh4:%u\n", sh4);
	
	printf("ch1:%u\n", ch1);
	printf("ch2:%u\n", ch2);
	printf("ch3:%u\n", ch3);
	
	printf("ldata1:%u\n", ldata1);
	printf("ldata2:%u\n", ldata2);
	printf("ldata3:%u\n", ldata3);
	
	printf("sdata1:%u\n", sdata1);
	printf("sdata2:%u\n", sdata2);
    
	printf("fun1:%p\n", fun1);
	printf("fun2:%p\n", fun2);
	printf("fun3:%p\n", fun3);
	printf("fun3:%p\n", fun3);


	printf("idata1:%u\n", &idata1);
	printf("carray1:%u\n", carray1);
	printf("idata2:%u\n", &idata2);
	printf("idata3:%u\n", &idata3);
	printf("idata4:%u\n", &idata4);

	printf("sh1:%u\n", &sh1);
	printf("sh2:%u\n", &sh2);
	printf("sh3:%u\n", &sh3);
	printf("sh4:%u\n", &sh4);

	printf("ch1:%u\n", &ch1);
	printf("ch2:%u\n", &ch2);
	printf("ch3:%u\n", &ch3);

	printf("sharray3:%u\n", &sharray3);

	printf("ldata1:%u\n", &ldata1);
	printf("ldata2:%u\n", &ldata2);
	printf("ldata3:%u\n", &ldata3);

	printf("sdata1:%u\n", &sdata1);
	printf("sdata2:%u\n", &sdata2);
	printf("sdata3:%u\n", &sdata3);
	printf("sdata4:%u\n",&sdata4);

	printf("ptr:%u\n", ptr);
	printf("&ptr:%u\n", &ptr);

	printf("canme1:%u\n", cname1);
	printf("pname1:%u\n", pname1);
	printf("&pname1:%u\n", &pname1);

	printf("cname2:%u\n", cname2);
	printf("pname2:%u\n", pname2);
	printf("&pname2:%u\n", &pname2);

	printf("fun1:%u\n", fun1);
	printf("fun2:%u\n", fun2);
	printf("fun3:%u\n", fun3);

}

void fun1()
{
	int ldata4;
	printf("i am function1\n");
}

int idata5 =10;
void fun2()
{
	printf("i am function2\n");
}

void fun3()
{
	int ldata5= 10;
	printf("i am function3\n");
}
