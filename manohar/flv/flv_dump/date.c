#include <stdio.h>
struct
{
short int date;
}dates;
int main()
{
dates.date = 185;
dates.date = 54;
printf("%d %d\n",dates.date,dates.date);
}
