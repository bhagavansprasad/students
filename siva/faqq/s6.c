#include<stdio.h>
main()
{
char *ptr[2]={"hello","goodmorning"};
swap(ptr[0],ptr[1]);
printf("%s\n%s",ptr[0],ptr[1]);
return 0;
}
void swap(char *t1,char *t2)
{
char *t;
t=t1;t1=t2;t2=t1;
}
