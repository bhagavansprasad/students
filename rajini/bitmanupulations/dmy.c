#include <stdio.h>
main()
{
  unsigned int d=9, m=3, y=1994, year, month, day, date;

  date=(y-1980)*512+m*32+d;
  printf("\nDate=%u", date);
  year=1980+(date>>9);
  month=((date<<7)>>12);
  day=((day<<11)>>11);
  printf("\nDay=%u", day);
  printf("\nMonth=%u", month);
  printf("\nyear=%u", year);
}  
