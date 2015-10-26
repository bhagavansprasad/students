#include <stdio.h>
main()
{	
	int i;
	int size=(char *)(&i+1)-(char *)(&i);
	printf("%d\n",size);
}
