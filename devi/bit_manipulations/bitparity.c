#include <stdio.h>
int parity(unsigned x) 
{
   unsigned y;
   y = x ^ (x >> 1);
   y = y ^ (y >> 2);
   y = y ^ (y >> 4);
   y = y ^ (y >> 8);
   y = y ^ (y >>16);
   return y & 1;
}
main()
{
	unsigned x = 7,s;
	s = parity(x);
	if(s)
	printf("odd\n");
	else
	printf("even\n");
}

