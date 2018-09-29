/* By using flag variable */

#include <stdio.h>
int main()
{
	unsigned int mask = 1, n = 30, i = 1, flag = 0;
	for(i = 1; i <= 32; i++)
	{
		mask = 1;
		if((n&(mask<<(i-1)))== n)
		{
			flag = 1;
			break;
		}
	}
	printf("Given no %d is %s\n",n, ((flag == 1)?"power of 2":"not power of 2"));
}


/* By using bit count */

#include <stdio.h>
int main()
{
	unsigned int n = 1, i = 0, c = 0, mask = 1;
	for(i = 1; i <= 32; i++)
	{
		mask = 1;
		(((n&(mask<<(i-1)))!=0)?c++:c);
	}
	printf("The no of bits on in %d is = %d  ",n,c);
	printf("So the given no is %s\n",((c == 1)?"exact power of 2 ":"not power of 2"));
}
