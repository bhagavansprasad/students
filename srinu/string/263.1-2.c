#include<stdio.h>
#include <string.h>
main()
{
char arr[10];
char *p[]={"orange","yellow","sky","blue","black"};

printf("%s%s%s\n",p[1],p[2],p[3]);
strcpy(arr,"luck""now");
printf("%s\n",arr);
}
