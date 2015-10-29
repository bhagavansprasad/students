#include <stdio.h>
//#define num 5
#define fun(num,i) { return (i<=5)?num:0; }
main()
{
	int num = 5,i=0,rtal;
	rtal = fun(num,i++);
	printf("%d\n", rtal);
}
