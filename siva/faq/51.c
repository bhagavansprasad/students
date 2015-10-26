#include <stdlib.h>
main()
{
	int *p;
	p=malloc(-10);
	
	if(p== NULL)
	{
	perror("failed\n");
	}
	else
	printf("success\n");
}
