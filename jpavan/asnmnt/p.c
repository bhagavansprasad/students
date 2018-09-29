#include<stdio.h>
main()
{
int i;
int a=300;
int *pa=&a;
char *cp=&a;
printf("%d\n",*pa);
//printf("%d\n",*cp);
for(i=0;i<=3;i++)
{
printf("%d\n",*cp);
cp++;
}

}
