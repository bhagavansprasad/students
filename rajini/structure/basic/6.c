#include <stdio.h>
#include <string.h>
struct student
{
char a;
char b;

};
int main()
{
struct student st1;
printf("sizeof struct--%d\n",sizeof(struct student));
printf("size%d\n",sizeof(st1.a));
printf("size%d\n",sizeof(st1.b));
printf("ad---%p\n",&st1.a);
printf("add---%p\n",&st1.b);
return 0;
}
