#include<stdio.h>
#include<stdlib.h>
void* amalloc(int);
void afree(void*);
int flag=0;
char buff[100];
main()
{
char *p1,*p2;
p1=amalloc(100);
printf(" p1 address :%p\t\n",p1);
p2=amalloc(100);
printf("p2 address :%p\t\n",p2);
afree(p1);
p2=amalloc(100);
printf("p2 address :%p\t\n",p2);
//free(p1);
//free(p1);
}
void* amalloc(int size)
{
 if(flag==0)
 {
  flag=1;
  return buff;
 }
 else 
  return NULL;
}
void afree(void* p)
{
flag=0;
}
