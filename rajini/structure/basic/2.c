#include <stdio.h>
#include <string.h>
struct student
{
char a;
char c;
//char b;
//short int b;
//int d;
};
int main()
{
struct student st1;
printf("sizeof struct--%d\n",sizeof(struct student));
printf("size%d\n",sizeof(st1.a));
printf("size%d\n",sizeof(st1.b));
//printf("size%d\n",sizeof(st1.c));
//printf("size%d\n",sizeof(st1.d));
//printf("size%d\n",sizeof(st1.e));
//printf("size%d\n",sizeof(st1.f));
printf("ad---%u\n",&st1.a);
printf("add---%u\n",&st1.b)
//printf("add---%u\n",&st1.c)
//printf("add---%u\n",&st1.d);
//printf("add---%u\n",
return 0;
}
