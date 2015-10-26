#include <stdio.h>
main()
{
	int a = 0,b = 0;
	if(!a)
	{
		b = !a;
		printf("---->b%d\n",b);
		if(b)
			a =!b;
		printf("---->a:%d\n",a);
	}
	printf("%d%d",a,b);
	return(0);
}
