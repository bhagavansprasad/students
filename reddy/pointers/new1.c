#include <stdio.h>
main()
{
int a = 300;
int b = 0;
int i = 0;
char *p = ((char *)&a);
char *q = ((char *)&b);


	printf( " %02d ", *( q + (i+0) ) = *( p + (i+3)));
	printf( " %02d ", *( q + (i+1) ) = *( p + (i+2)));
	printf( " %02d ", *( q + (i+2) ) = *( p + (i+0)));
	printf( " %02d ", *( q + (i+3) ) = *( p + (i+1)));

}

