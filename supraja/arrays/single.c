#include <stdio.h>
main()
{
char str[15]="Aura Networks";
printf("%u\n",str);
printf("%u\n",&str);
printf("%u\n",str+1);
printf("%u\n",&str+1);
printf("%u\n",*&str);
printf("%c\n",*str);
printf("%c\n",**&str);
}

