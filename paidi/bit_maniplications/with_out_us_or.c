/* withe out using and operation */
#include <stdio.h>
#if 0
int main()
{
   
    int a=10,b=5;
    int sum=0;

     //sum = a - (-b);
    sum = a - ~b -1;

    printf("Sum of two integers: %d\n",sum);

    return 0;
}
#endif

int main()
{
	int a = 4,b = 5,retval=0;
	retval = fun(a,b);
	printf("add ->= %d\n",retval);
}
fun(int x,int y)
{
	int p,q;
	while(p)
	{
		p = x&y;
		q = x^y;
		x = p<<1;
		y = q;
	}
	return q;
}

