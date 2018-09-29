#include<stdio.h>
#include<string.h>
main()
{
char *c;
c=malloc(100*sizeof(char));
printf("address of c %p\n",c);
c++;
printf("address of c%p\n",c);
c="hello\n";
printf("%s\n",c);
free(c);
}
