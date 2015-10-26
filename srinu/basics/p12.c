#include<stdio.h>
int main()
{
	int i;
	for(i=1;i<=10;)
	{
		printf("%d\n",i);
		if(i<=7)
			i=i+2;
	}
	printf("%d\n",i);
}
