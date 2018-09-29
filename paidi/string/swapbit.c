#include <stdio.h>
int *swapbit(int *,int *);
main()
{
	int a=10,b=20;
	printf("%d %d\n",a,b);
	swapbit(&a,&b);
	printf("%d %d\n",a,b);
}
int * swapbit(int *a, int *b)
{
	*a=*a^*b;
	*b=*a^*b;
	*a=*a^*b;
}  
