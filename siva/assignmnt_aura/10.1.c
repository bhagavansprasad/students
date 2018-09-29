#include<stdio.h>
#define FIRST  char*
typedef char* SECOND;
int main()
{
FIRST ch1,ch2;
SECOND ch3,ch4;
}
struct em
{
int i;
struct em *next;
struct em *prev;
}em;
x=em.next->next->prev->next.i;
printf("%d",x);


