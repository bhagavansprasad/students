#include<stdio.h>
#include<stdlib.h>

int idata1=1;
char carray1[10];
char cname1[128]="Aura Networks";
char *pname1="Aura networks";
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
const int gunin;
const int ginit=99;

void fun1();                                                                      
void fun2();
void fun3();

main()
{
 register int ldata1;
	int ldata2=2;
	int ldata3;
	static int sdata1;
	static int sdata2=10;
	char cname2[128]="Aura Networks";
	char *pname2="Aura Networks";
	const int lunin;
	const int linit=42;

	int *ptr=malloc(10);
	int *ptr1;

	printf("ptr: %p\t    %x\n",ptr,ptr);
	printf("&ptr:%p\t    %x\n\n",&ptr,&ptr);

	printf("cname1: %p\t %x\n",cname1,cname1);
	printf("pname1: %p\t %x\n",pname1,pname1);
	printf("&pname1:%p\t %x\n\n",&pname1,&pname1);

	printf("cname2: %p\t %x\n",cname2,cname2);
	printf("pname2: %p\t %x\n",pname2,pname2);
	printf("&pname2:%p\t %x\n\n",&pname2,&pname2);

	printf("fun1:%p\t   \t %x\n",fun1,fun1);
	printf("fun2:%p\t   \t %x\n",fun2,fun2);
	printf("fun3:%p\t   \t %x\n\n",fun3,fun3);

	ptr1=malloc(10);
	
	printf("ptr1:%p\t   \t %x\n",ptr1 ,ptr1);
	printf("&ptr1:%p\t   \t %x\n",&ptr1,&ptr1);

	printf("iarray1: %p\t %x\n",iarray1,iarray1);
	printf("iarray2: %p\t %x\n",iarray2,iarray2);
	printf("sharray3:%p\t %x\n\n",sharray3,sharray3);

	printf("ldata1:%p\t   %x\n",&ldata1,&ldata1);
	printf("ldata2:%p\t   %x\n",&ldata2,&ldata2);
	printf("ldata3:%p\t   %x\n\n",&ldata3,&ldata3);

	printf("idata1:%p\t   \t %x\n",&idata1,&idata1);
	printf("idata2:%p\t   \t%x\n",&idata2,&idata2);
	printf("idata3:%p\t   \t %x\n",&idata3,&idata3);
	printf("idata4:%p\t   \t %x\n\n",&idata4,&idata4);


	printf("sdata1:%p\t   \t %x\n",&sdata1,&sdata1);
	printf("sdata2:%p\t   \t %x\n\n",&sdata2,&sdata2);

	printf("gunin:%p\t   \t %x\n",&gunin,&gunin);
	printf("ginit:%p\t   \t%x\n",&ginit,&ginit);
	printf("lunin:%p\t   \t %x\n",&lunin,&lunin);
	printf("linit:%p\t   \t %x\n\n",&linit,&linit);

	printf("gunin:%d\t   \t %d\n",gunin,gunin);
	printf("ginit:%d\t   \t%d\n",ginit,ginit);
	printf("lunin:%d\t   \t %d\n",lunin,lunin);
	printf("linit:%d\t   \t %d\n\n",linit,linit);

//	ginit++;       errors since they are read only variables
//	lunin=10;
//	gunin=25;
	
	printf("ginit:%d\t   \t%d\n",ginit,ginit);
	printf("linit:%d\t   \t %d\n\n",linit,linit);
	printf("lunin:%d\t   \t %d\n",lunin,lunin);
	printf("gunin:%d\t   \t %d\n",gunin,gunin);



	fun1();



}

void fun1()
{
	int ldata4;
	const int funin;
	const int finit=56;

	printf("I am function1\n");
	printf("ldata4:%p\t   %x\n\n",&ldata4,&ldata4);
	printf("funin:%d\t   \t %d\n",funin,funin);
	printf("finit:%d\t   \t %d\n",finit,finit);

	printf("funin:%p\t   \t %x\n",&funin,&funin);
	printf("finit:%p\t   \t %x\n\n",&finit,&finit);





}

int idata5=10;

void fun2()
{
	printf("I am function2\n");
}

void fun3()
{
	int ldata5=10;
	printf("I am function 3\n");
}

int idata6=20;










