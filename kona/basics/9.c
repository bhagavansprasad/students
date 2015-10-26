#include <stdio.h>
main()
{
	int n=4;
	if(n%2==0)
	goto even;
	else
	goto odd;
	even:
		printf("num is even");
		goto end;
	odd:
		printf("num is odd");
		goto end;
	end:
	printf("\n");
}
