#include<stdio.h>
struct whole
{
	char a;
	int  b;
	short int f;
	char c;
	char e;
};
struct whole d;
 void main()
{

printf("%u\n",&d.a);
printf("%u\n",&d.b);
printf("%u\n",&d.f);
printf("%u\n",&d.c);
printf("%u\n",&d.e);
printf("%u\n",sizeof(d));
//printf("%u\n",sizeof(d)-(sizeof(d.a)+sizeof(d.b)+sizeof(d.c)+sizeof(d.e)));
}
