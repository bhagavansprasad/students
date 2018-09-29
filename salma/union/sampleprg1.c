#include<stdio.h>
union data
{
char ch1[4];
int i;
};
union data d1;
main()
{
int i;
d1.i=300;
printf("%d\n",sizeof(d1));
for(i=0;i<4;i++)
printf("%d\n",d1.ch1[i]);

}
