#include<stdio.h>
main()
{
	int a=6, n = a, b,c=0;
	while(a>0)
	{
		b=a&1;
		c=c|b;
		if(a>1)
			c=c<<1;
		a=a>>1;
	}
	printf("%d",c);

	if( c == n)
		printf("palindrome\n");
	else
		printf("not a palindrome\n");
}


