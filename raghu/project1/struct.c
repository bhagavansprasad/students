#include <stdio.h>
struct a
{
	int s;
	int i;
	char p;
	char c;
}abc;
struct b
{
	int i;
	double d;
	short int s;
	float f;
}ab;
struct c
{
	char c;
	char c1;
	char c2;
	int i1;
	int i2;
	double d1;
	double d2;
	long int l1;
	char c3;
}a;
struct d
{
	double d1;
	double d2;
	int i1;
	int i2;
	char c;
	short int s;
}a1;
struct e
{
	short int s;
	int i;
	short int s2;
}a2;
struct f
{
	char c;
	int i;
	char c1;
}a3;
struct g
{
short int s;
char c;
int i;
char c1;
}a4;
struct h
{
	short int s;
	char c;
	short int s1;
	char c1;
	int i;
}a5;
struct i
{
	short int s;
	short int s1;
	short int s2;
}a6;
struct j
{
	int i;
	short int s;
}a7;
struct k
{
	short int s;
	char c;
	short int s1;
	int i;
}a8;
main()
{
	printf("The size of struct abc is %d\n",sizeof(abc));
	printf(" s add:%p\n i add:%p\n p add:%p\n c add :%p\n",&abc.s,&abc.i,&abc.p ,&abc.c);
	printf("\n");	
	
	printf("The size of struct ab is %d\n",sizeof(ab));
	printf(" i add:%p\n d add:%p\n s add:%p\n f add :%p\n",&ab.i,&ab.d,&ab.s,&ab.f);
	printf("\n");
	
	printf("The size of struct a is %d\n",sizeof(a));
	printf(" c add:%p\n c1 add:%p\n c2 add:%p\n i1 add:%p\n i2 add:%p\n d1 add:%p\n d2 add:%p\n l1 add:%p\n c3 add:%p\n",&a.c,&a.c1,&a.c2,&a.i1,&a.i2,&a.d1,&a.d2,&a.l1,&a.c3);
	printf("\n");
	
	printf("The size of struct a is %d\n",sizeof(a1));
	printf(" d1 add:%p\n d2 add:%p\n i1 add:%p\n i2 add:%p\n c add:%p\n s add:%p\n",&a1.d1,&a1.d2,&a1.i1,&a1.i2,&a1.c,&a1.s);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a2));
	printf(" s add:%p\n i add:%p\n s2 add:%p\n",&a2.s,&a2.i,&a2.s2);
	printf("\n");

		printf("The size of struct a is %d\n",sizeof(a3));
	printf(" c add:%p\n i add:%p\n c1 add:%p\n",&a3.c,&a3.i,&a3.c1);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a4));
	printf(" s add:%p\n c add:%p\n i add:%p\n c1 add:%p\n",&a4.s,&a4.c,&a4.i,&a4.c1);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a5));
	printf(" s add:%p\n c add:%p\n s1 add:%p\n c1 add:%p\n i add:%p\n",&a5.s,&a5.c,&a5.s1,&a5.c1,&a5.i);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a6));
	printf(" s add:%p\n s1 add:%p\n s2 add:%p\n",&a6.s,&a6.s1,&a6.s2);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a7));
	printf(" i add:%p\n s add:%p\n",&a7.i,&a7.s);
	printf("\n");

	printf("The size of struct a is %d\n",sizeof(a8));
	printf(" s add:%p\n c add:%p\n s1 add:%p\n i add:%p\n",&a8.s,&a8.c,&a8.s1,&a8.i);
	printf("\n");


}
