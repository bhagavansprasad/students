#include <stdio.h>
int main()
{
	int a = 0;
	{
		int a  = 10;
		printf("%d", a);//10
		a++;
		{
		a = 20;
		}
		{
			printf("%d", a);//20
			int a = 30;
			{
				a++;
			}
			printf("%d", a++);//31
		}
		printf("%d", a++);//20
	}
	printf("%d", a);//0
	return 0;
}
