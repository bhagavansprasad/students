/*#include <stdio.h>
int main()
{
	unsigned int n = 5, mask = 1;
	if( mask&n )
	{
		printf("%d is a odd number\n",n);
	}
	else 
	{
		printf("%d is a even number\n",n);
	}
}
*/
#include <stdio.h>
int main()
{
	unsigned int n = 250, mask = 1;
	printf("%d is a %s number\n",n,((mask&n)?"odd":"even"));
}

