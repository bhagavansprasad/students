#include<stdio.h>
#include<stdlib.h>
union size
{
int a;
char c[2];
};
union size single;
main()
{
single.a=300;
printf("union_size=%lu\n",sizeof(union size));
printf("single.avalue=%p\n",&single.a);
printf("single.asize=%lu\n",sizeof(single.a));
printf("single.c[0]=%p\n",&single.c[0]);
printf("single.c[0]size=%lu\n",sizeof(single.c[0]));
printf("single.c[1]=%p\n",&single.c[1]);
printf("single.c[1]size=%lu\n",sizeof(single.c[1]));
}

