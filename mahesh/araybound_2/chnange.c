#include <stdio.h>
main()
{
	int a=10,b=5;
	int *p;
	p=&a;
	printf("adress of a : %u  adress of b :%u pointer :%u\n",&a,&b,p);

	printf("value of a : %d  value of b :%d\n",a,b);
	
	*(++p)=15;

	printf("value of a : %d  value of b :%d\n",a,b);

}
