#include <stdio.h>
int *foo();
main()
{
 int z;
 z = foo();
 printf("string--->=%s\r\n",z);
}

int *foo()
{
 return "hellow";
}
