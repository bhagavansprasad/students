#include"stdio.h"
char *rstrdup(char *s)
{
char *p;
int i;
p=(char *)malloc(50*sizeof(char));
for(i=0;s[i]!='\0';i++)
p[i]=s[i];
p[i]='\0';
return p;
}
main()
{
char str[]="ramprasad vvr munna chinnu yerramsetti";
char *ptr;
ptr=rstrdup(str);
printf("ptr=%s\n",ptr);
}
