#include <stdio.h>
main()
{
int i;
char str[]=" hi i  am    devi  ";
i=astrlen(str);
printf("%d is the length of %s",i,str);
}
int astrlen(char *strr)
{
int j;
for(j=0;strr[j]!='\0';j++);
return j;
}
