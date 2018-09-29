#include <stdio.h>
main()
{
int num=458,year,day,weeks;
year=num/365;
weeks=(num/7)-(52*year);
day=num%7;
printf("no of years:%d\nno of weeks:%d\nno of days:%d\n",year,weeks,day);
}
