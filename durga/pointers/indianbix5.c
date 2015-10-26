#include <stdio.h>
main()
{
void *vp;
char *ch = "jack";
char c = 74;
int j = 65;
vp = &c;
printf("%c", *(char*)vp);
vp = &j;
printf("%c", *(int *)vp);
vp = ch;
printf("%s",(char*)vp+2);
}
