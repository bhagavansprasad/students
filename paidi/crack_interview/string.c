#include <string.h>
#include <stdio.h>
main()
{
 char arr[]="string";
 char *str = "paidi";

 printf("%s\n",arr);
 printf("%c\n",*arr);
 printf("%s\n",str);
 printf("%c\n",*str);

 char *p = "kumar"; 
 *p++;
 printf("p--> %s\n",str);
 printf("p--> %c\n",*str);

 char *ptr = "aura";
 (*ptr) ++;
 printf("ptr--> %s\n",str);
 printf("ptr--> %c\n",*str);

}
