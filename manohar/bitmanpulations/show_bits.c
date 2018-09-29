#include <stdio.h>
int  showbits(int ,int );
int main()
{
	int n=54;
	showbits(n,7);
	return 0;
}
int  showbits(int n,int pos)
{
	int i;
	for(i=pos;i>=0;i--)
	{
		if(n & (1<<i))
		printf("1 ");
		else
		printf("0 ");
	}
	printf("\n");
return 0;	
}
