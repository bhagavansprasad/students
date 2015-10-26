#include<stdio.h>
main()
{
	int a=10;
	int *p;
	p=&a;
	printf("*p:%d\n",*p);
	*p=20;
	printf("*p:%d\n",*p);
	printf("p:%d\n",p);
	p=p+1;
	printf("p:%d\n",p);
//	printf("*p:%d\n",*p);
	
	p++;
	printf("p:%d\n",p);
//	printf("*p:%d\n",*p);


}	
	

