#include <stdio.h>
void showbits_actualorder(int a)
{
	int mask=1,i,n;
	printf("actual order of bits");
	for(i=7;i>=0;i--)
	{
	n = a & (mask << i);
	//printf("%d\n",n);
	if(n == 0)
	printf("0");
	else
	printf("1");
	}
	printf("\n");
}
void	showbits_reverseorder(int a)
{

	int mask=1,i,n;
	printf("reverse order of bits");
	for(i=0;i<8;i++)
	{
	n = a & (mask << i);
	//printf("%d\n",n);
	if(n == 0)
	printf("0");
	else
	printf("1");
	}
	printf("\n");
}
main()
{
	int a=5;
	showbits_actualorder(a);
	showbits_reverseorder(a);
}
