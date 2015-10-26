#include"stdio.h"
#include"string.h"
main()
{
char str1[]="veeravenkata ramprasad yerramsetti";
char *ptr;
ptr=strdup(str1);
printf("ptr=%s\n",ptr);
}
