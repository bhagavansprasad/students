#include<stdio.h>
#define show_bit(m,n) (m&n)
#define show_or_bit(m,n) (m||n)
int and_operation_bit(int,int);
main()
{
	int c,p,k,e,q;

	c=show_bit(5,6);
	p=and_operation_bit(5,6);
	q=show_or_bit(5,6);
	k=show_bit('A','B');
	e=show_bit('a','b');

	printf("function_using_o-->=%d\n",c);
	printf("and-->=%d\n",p);
	printf("or-->=%d\n",q);
	printf("asic valu-->=%d\n",k);
	printf("asic valu-->=%d\n",e);

}

int and_operation_bit(int s1,int s2)
{
	int u;
	u=(s1|s2);
	return u;

}
