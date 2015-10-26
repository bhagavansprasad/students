#include<stdio.h>
int main()
{
	int i;
	for(i=1;i<=10;)
	{
		printf("%d",i);
		if(i<=7)
			i+=2;
	}
	printf("i:%d\r\n",i);
}
