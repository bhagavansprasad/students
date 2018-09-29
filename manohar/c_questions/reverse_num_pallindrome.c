#include <stdio.h>
int main()
{
	int a=656,rem,sum = 0,temp;
	temp = a;
	while(a > 0)
	{
	rem = a%10;
	sum = sum * 10 + rem;
	a = a/10;
	}
	if(temp == sum)
	printf("pallidrome \n");
	else
	printf("not a pallidrome\n");
	return 0;
}
