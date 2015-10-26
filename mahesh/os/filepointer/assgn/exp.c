#include <stdio.h>
main()
{
	int a;
	close(0);
	scanf("%d",&a);
	//close(1);
	close(2);
	printf("---%d\n",a);
}
