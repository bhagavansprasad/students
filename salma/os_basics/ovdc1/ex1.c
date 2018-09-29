#include<stdio.h>
int get_count(int *);
main()
{
int a[10]={10,20,30};
int count;
count=get_count(a);
printf("count=%d\n",count);
}
int get_count(int *a)
{
int i;
for(i=0;a[i]!='\0';i++);
  return i;
}
