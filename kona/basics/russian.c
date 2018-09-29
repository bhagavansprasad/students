#include <stdio.h>
main()
{
	int x=19,y=25,s=0,a,b;
	a=x;
	b=y;
	while(a>=1)
	{
		if(a%2!=0)
		s=s+b;
		a=a/2;
		b=b*2;
	}
	printf("%d * %d =%d\n",x,y,s);
}
