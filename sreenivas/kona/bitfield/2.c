#include <stdio.h>
struct date
{
   unsigned int d:5;
   unsigned int m:4;
   unsigned int y;
};
 
int main()
{
   printf("Size of date is %d bytes\n", sizeof(struct date));
   struct date dt = {31, 12, 2014};
   printf("Date is %d/%d/%d", dt.d, dt.m, dt.y);
   printf("\n");
}
