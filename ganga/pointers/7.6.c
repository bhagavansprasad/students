#include <stdio.h>

main()
{
 char str[15] = "Aura Networks";
 printf("-->str :%p\n", str);
 printf("-->&str :%p\n", &str);
 printf("-->str+1 :%p\n", str+1);
 printf("-->&str+1 :%p\n", &str+1);
 printf("-->*&str :%p\n", *&str);
 printf("-->*str :%c\n", *str);
 printf("--**&str :%c\n", **&str);
}
