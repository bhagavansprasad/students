#include <stdio.h>
main()
{
	int ldata1;
	int ldata2=2;
	int ldata3;
	static int sdata1;
	int idata=1;
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

	static int sdata2=10;
	char cname2[128]="aura networks";
	char *pname2="aura networks";

	int *ptr=malloc(10);

	printf("--->ptr :%u\n",ptr);
	printf("---->&ptr :%u\n",&ptr);

	printf("--->cname1 :%u\n",cname1);
	printf("--->pname1 :%u\n",pname1);
	printf("---->&pname1 :%u\n",&pname1);

	printf("--->cname2 :%u\n",cname2);
	printf("--->pname2 :%u\n",pname2);
	printf("--->&pname2 :%u\n",&pname2);

	printf("--->fun1 :%u\n",fun1);
	printf("--->fun2 :%u\n",fun2);
	printf("---->fun3 :%u\n",fun3);

	ptr=malloc(10);
	printf("--->ptr :%u\n",ptr);

	printf("--->iarray1 :%u\n",iarray1);
	printf("---> iarray2 :%u\n",iarray2);
}
void fun1()
{
	int ldata4;
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
	printf("i am function3\n");
}
int idata6=20;

