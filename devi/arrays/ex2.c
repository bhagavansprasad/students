#include<stdio.h>
void astrcpy(void);
char a[20]="HELLO WORLD";
char b[20];
main()
{
astrcpy();
printf("%s\n",b);
}
void astrcpy(void)
{
int i;
for(i=0;a[i]!='\0';i++)
 b[i]=a[i];
b[i]='\0';
//printf("%s\n",b);
}
