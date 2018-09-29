#include<stdio.h>
#include<stdlib.h>
union size
{
char c;
int a;
int b;
};
union size single;
main()
{
single.a=300;
printf("union_size=%lu\n",sizeof(union size));
printf("single.avalue=%p\n",&single.a);
printf("single.asize=%lu\n",sizeof(single.a));
printf("single.c=%p\n",&single.c);
printf("single.csize=%lu\n",sizeof(single.c));
printf("single.b=%p\n",&single.b);
printf("single.b=%lu\n",sizeof(single.b));
}

