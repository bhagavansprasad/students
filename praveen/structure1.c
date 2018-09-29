#include<stdio.h>
struct mem
{
	char c;
	short int s1;
	int a;
	short int s;

};
struct mem b;

struct mem1
{
	short int s;
	char c;
	int i;
	char c1;
};
struct mem1 b1;

struct mem2
{
	short int s;
	char c;
	short int s1;
	char c1;
	int i;
};
struct mem2 b2;

struct mem3
{
	short int s;
	short int s1;
	short int s2;
};
struct mem3 b3;

struct mem4
{
	short int s;
	char c;
	short int s1;
	int i;
};
struct mem4 b4;

struct mem5
{
 int i;
 double d;
 int i1;
 double d1;
};
struct mem5 b5;

struct mem6
{
	double d;
	double d1;
	int i;
	int i1;
	char c;
	short int s;
};
struct mem6 b6;
struct mem7
{
 int i;
 double d;
 int i1;
};
struct mem7 b7;
struct mem8
{
 int i;
 char c;
 double d;
};
struct mem8 b8;
struct mem9
{
 int i;
 double d;
 double d1;
};
struct mem9 b9;


main()
{
printf("structure\n");
printf("%p\n",&b.c);
printf("%p\n",&b.s1);
printf("%p\n",&b.a);
printf("%p\n",&b.s);
printf("%d\n",sizeof(b));
printf("structure1\n");
printf("%p\n",&b1.s);
printf("%p\n",&b1.c);
printf("%p\n",&b1.i);
printf("%p\n",&b1.c1);
printf("%d\n",sizeof(b1));
printf("structure2\n");
printf("%p\n",&b2.s);
printf("%p\n",&b2.c);
printf("%p\n",&b2.s1);
printf("%p\n",&b2.c1);
printf("%p\n",&b2.i);
printf("%d\n",sizeof(b2));
printf("structure3\n");
printf("%p\n",&b3.s);
printf("%p\n",&b3.s1);
printf("%p\n",&b3.s2);
printf("%d\n",sizeof(b3));
printf("structure4\n");
printf("%p\n",&b4.s);
printf("%p\n",&b4.c);
printf("%p\n",&b4.s1);
printf("%p\n",&b4.i);
printf("%d\n",sizeof(b4));
printf("structure5\n");
printf("%p\n",&b5.i);
printf("%p\n",&b5.d);
printf("%p\n",&b5.i1);
printf("%p\n",&b5.d1);
printf("%d\n",sizeof(b5));
printf("structure6\n");
printf("%p\n",&b6.d);
printf("%p\n",&b6.d1);
printf("%p\n",&b6.i);
printf("%p\n",&b6.i1);
printf("%p\n",&b6.c);
printf("%p\n",&b6.s);
printf("%d\n",sizeof(b6));
printf("structure7\n");
printf("%p\n",&b7.i);
printf("%p\n",&b7.d);
printf("%p\n",&b7.i1);
printf("%d\n",sizeof(b7));
printf("structure8\n");
printf("%p\n",&b8.i);
printf("%p\n",&b8.c);
printf("%p\n",&b8.d);
printf("%d\n",sizeof(b8));
printf("structure9\n");
printf("%p\n",&b9.i);
printf("%p\n",&b9.d);
printf("%p\n",&b9.d1);
printf("%d\n",sizeof(b9));
}

