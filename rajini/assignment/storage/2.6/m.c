#include "stdio.h"
#include "stdlib.h"

int idata1=1;
char carray[10];
char cname1[128]="Rajini Kanth";
char *pname1="Rajini Kanth";
int idata2;
int idata3=3;
int idata4;
int idata5;
int idata6;
short sh1;
short sh2=2;
int iarray1[10]={1,2};
int iarray2[10]={10,20};
short sh3;
short sh4=4;
char ch1=1;
char ch2;
short isharray3[10]={5,6};
char ch3;


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
   char cname2[128]="Rajini Kanth";
   char *pname2="Rajini Kanth";
   int *ptr=malloc(10);

   printf("%p\n",ptr);
   printf("%p\n",&ptr);

   printf("%s\n",cname1);
   printf("%p\n",pname1);
   printf("%p\n",&pname1);
   
   printf("%s\n",cname2);
   printf("%p\n",pname2);
   printf("%p\n",&pname2);

   printf("%p\n",fun1);
   printf("%p\n",fun2);
   printf("%p\n",fun3);

   ptr=malloc(10);
   printf("%p\n",ptr);

   printf("%p\n",iarray1);
   printf("%p\n",iarray2);
   printf("%p\n",isharray3);

}


void fun1()
{
   int ldata4;
   printf("iam function1\n");
}


int idata5=10;

void fun2()
{
   printf("iam function 2\n");
}


void fun3()
{
   int ldata5=10;
   printf("iam function 3\n");
}

int idata6=20;



