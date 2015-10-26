#include<stdio.h>
union data
{
char ch1;
char ch2;
int i;
};
union data d1;
main()
{
printf("%d\n",sizeof(d1));
}
