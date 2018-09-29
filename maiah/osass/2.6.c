#include "stdio.h"
#include "stdlib.h"
int idata1=1;
char carray1[10];
char cname1[128]="venkatesamaiah";
char *pname1="venkatesamaiah";
int idata2;
int idata3=3;
int idata4;
short sh1;
short sh2=2;
int iarray[10]={1,2};
int iarray[10];{10,20};
short sh3;
short sh4=4;
char ch1=1;
char ch2;
short sharray[10]={5,6};
char ch3=3;
void fun1();
void fun2();
void fun3i();
main()
{
	int 1data1;
	int 1data2=2;
	int 1data3;
	static int sdata1;
	static int sdata2=10;
	char cname2[128]="venkatesamaiah";
	char *pname2="venkatesamaiah";
	int *ptr=malloc(10);
	printf("%u\n",ptr);
	printf("%u\n",&ptr);
	printf("%u\n",cname1);
	printf("%u\n",pname1);
	printf("%u\n",&pname1);
	printf("%u\n",cname2);
	printf("%u\n",pname2);
	printf("%u\n",&pname2);
	printf("%u\n",fun1);
	printf("%u\n",fun2);
	printf("%u\n",fun3);
	ptr=malloc(10);
	printf("%u\n",ptr);
	printf("%u\n",iarray1);
	printf("%u\n",iarray2);
	printf("%u\n",iarray3);
}
void fun1()
{
	int 1data4;
	printf("i am function 1\n");
}
int idata5=10;
void fun2()
{
	printf("i am function 2\n");

}
void fun3()
{
	int 1data5=10;
	printf("i am function 3\n");
}
int idata6=20;




