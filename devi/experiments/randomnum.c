#include <stdio.h>
#include <stdlib.h>
int main()
{
	int r,a,b,n=100;
	puts("100 Random Numbers");
	for(a=0;a<20;a++)
	{
		for(b=0;b<5;b++)
		{
			r=rand();
			r%=n+1;
			printf("%d\t",r);
		}
		putchar('\n');
	}
	return(0);
}
