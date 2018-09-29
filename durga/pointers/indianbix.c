#include <stdio.h>
main()
{

int x= 30, *y, *z;
y = &x;
z = y;
*y++ = *z++;
x++;
printf("x : %d\t y:%u\t z:%u", x,y,z);
}
