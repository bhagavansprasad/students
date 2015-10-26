#include<stdio.h>
main()
{
	int a=300,i;
	char *pch=&a;
	printf("%u\n",pch);
	printf("%u=%d\n",pch,*pch);

	for(i=0;i<=2;i++)
	{
		pch=pch+1;
		printf("%u=%d\n",pch,*pch);
	}
	printf("%u\n",&a);
}
