#include<stdio.h>
#include<string.h>
main()
{
char str[]="hello world";
int a;
a=astrlen(str);
printf("a is %d\n",a);
}

int astrlen(char *str)
{
int count=1;
if(*str=='\0')
return 0;
//printf("%c\n%u\n",*(str+1),str+1);
//str++;
return(count+astrlen(str+1));
}
