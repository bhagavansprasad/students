#include <stdio.h>
int sum(int x,int y);
int main(void)
{
	int a,b,s;
	printf("enter a and b= ");
	scanf("%d%d",&a,&b);
	s=sum(a,b);
	printf("sum of %d and %d is %d\n",a,b,s);
	return 0;
}
int sum(int x,int y)
{
	int s;
	s=x+y;
	return s;
}
