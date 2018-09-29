#include <stdio.h>
void inplace_swap_B(int *pa,int *pb)
{
	printf("a--->%d \t b---->%d\n",*pa,*pb);
	*pa = *pa^*pb;
	*pb = *pa^*pb;
	*pa = *pa^*pb;
	//*pa^=*pb^=*pa^=*pb;
	printf("a--->%d \t b---->%d\n",*pa,*pb);
}
main()
{
	int a=10,b=20;
	inplace_swap_B(&a,&b);
	printf("a--->%d \t b---->%d\n",a,b);
}
