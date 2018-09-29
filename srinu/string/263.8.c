#include <stdio.h>
#include <string.h>
main()
{
char *p="HOW";
char arr[]="HOW";
*(p+2)='b';
arr[2]='b';
puts(p);
puts(arr);
}
