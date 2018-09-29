#include<stdio.h>
main()
{
char *p1="hi hello world";
char p2[]="hi hello world";

printf("array is %s\n",p2);
p2[2]='a';
printf("array is %s\n",p2);

printf("pointers is %s\n",p1);
//*(p1+1)='a';
//printf("pointer string is %s\n",p1);

}
