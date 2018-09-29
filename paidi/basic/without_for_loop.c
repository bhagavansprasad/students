#include<stdio.h>
main()
{
	static int i = 1;
	if(i<100)
	{
		printf("%d\t",i);
		i++;
		main();
	}
}


