#include <stdio.h>
main()
{
	static int a=5;
	printf("%d\n",a--);
	if(a)
	main();
}
