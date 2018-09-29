#include <stdio.h>
#include <string.h>
main()
{
char str1[20]="B";
char str2[20]="a";
int ptr;
ptr=strcasecmp(str1,str2);
/* TO DO : How function retruns a value of negative,zero and positive values*/
printf("%d\n",ptr);
}
