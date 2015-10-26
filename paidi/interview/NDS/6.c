#include <stdio.h>
main()
{
 struct xx
 {
  int x = 3;
  char name[] = "hello";
 };
 struct xx *s
 printf("%d\r\n",s->x);
 printf("%s\r\n",s->name);
}
