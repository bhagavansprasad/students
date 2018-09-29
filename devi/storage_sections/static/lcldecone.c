#include <stdio.h>
void main()
{
	int i;
	for(i = 0;i < 3;i++)
	{
		{
			static int a = 5;
			printf("%d\n",a);
			a++;
		}
	visit();
	}
}


/* o/p:
5
Don't disturb,I am learning
6
Don't disturb,I am learning
7
Don't disturb,I am learning
*/
